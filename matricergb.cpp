/**
  * \file matricergb.cpp
  * \brief Implementation of the RGB Matrix class
  * \author Quentin Barry-Marcheterre
  * \date 07/15/2014
*/

#include "matricergb.h"
#include <QMessageBox>
#include <QDebug>

#define DELAYSERIAL 1000     /**< Delay (in ms) before timeout on serial transmission */
#define INITDELAYSERIAL 3000 /**< Delay (in ms) before sending information when opening a serial connection */
#define BAUDRATE 57600       /**< BaudRate of the serial port */
#define NBCHARSCOMM 116      /**< Number of characters to transmit at once over the serial port */
#define NBRETRY 2            /**< Number of retries on bad CRC calculation */

/**
 * @fn MatriceRgb::MatriceRgb
 * @brief Default constuctor
 * This constructor does not need any parameters
 */
MatriceRgb::MatriceRgb()
{
    _port_baudrate = BAUDRATE;
    _serial = new QSerialPort();
}


/**
 * @fn bool MatriceRgb::toggleSerialPort
 * @brief Toggles the chosen serial port ON/OFF.
 * Will pass any OS error through an error dialog
 * @return  True if port was opened else false
 */
bool MatriceRgb::toggleSerialPort()
{
    if(!_serial->isOpen())
    {
        _serial->setPortName(_string_port_name);
        _serial->open(QIODevice::ReadWrite);
        if (_serial->error())
        {
            QMessageBox::critical(NULL,tr("Error"),_serial->errorString());
            return false;
        }
        _serial->setBaudRate(_port_baudrate);
        _serial->setDataBits(_serial->Data8);
        QString str_no_led_req;
        str_no_led_req.append(char(9));
        _serial->write(str_no_led_req.toLatin1().constData(),1);
        char donnes_recue = 0;

        //Retry getting the number of connected LED matrices on the LED display if the result is 0
        while(!donnes_recue){
            _serial->write(str_no_led_req.toLatin1().constData(),1);
            if(!_serial->waitForReadyRead(INITDELAYSERIAL)){}
            _serial->read(&donnes_recue,1);
        }
        _number_of_led_matrices = donnes_recue;
        return true;
    }
    _serial->close();
    return false;
}

/**
 * @fn MatriceRgb::sendAll
 * @brief Sends the text and colour information for both lines of the matrix
 */
void  MatriceRgb::sendAll()
{
    sendLine(0);
    sendLine(1);
    sendSpeed();
}

/**
 * @fn MatriceRgb::sendLine(int line_no)
 * @brief Sends the text and color information of one line to the matrix over the serial port
 * @param line_no The line number
 */
void  MatriceRgb::sendLine(int line_no)
{
    if (_serial->isOpen()){

        int retry_counter[2];
        QString parsed_text = unicodetoCP437(_string_lines[line_no]);
        parsed_text = parsed_text.leftJustified(_number_of_led_matrices*4,char(32),false);
        _string_lines[line_no] = parsed_text;
        QTextStream stream_text(&parsed_text);

        QString str_couleur,colors_str;
        colors_str = _string_colours[line_no];
        if(_string_lines[line_no].count() != _string_colours[line_no].count())
        {
            colors_str = createColorString(line_no);
        }
        QTextStream stream_couleur(&colors_str);

        char code = 0;
        while(!stream_text.atEnd() && !stream_couleur.atEnd()){
            QString str_txt = stream_text.read(NBCHARSCOMM);
            bool retry = false;
            while(true){
                QString str_temp = str_txt;
                if(retry)
                {
                    str_temp.prepend(char(0x16));
                }
                str_temp.prepend(char(code+line_no+1));
                str_temp.append(char(10));
                _serial->write(str_temp.toLatin1().constData(),str_temp.length());
                char donnes_recue = 0;
                if(!_serial->waitForReadyRead(DELAYSERIAL))
                {
                    QMessageBox::critical(NULL,"Erreur","Timeout");
                    return;
                }
                _serial->read(&donnes_recue,1);
                unsigned char CRC_calc;
                CRC_calc = calculCRC(str_txt.toLatin1().constData(),str_txt.length());
                qDebug() << "Message Ligne # " << line_no+1;
                qDebug() << "Micro ->" << (unsigned char)donnes_recue;
                qDebug() << "PC    ->" << CRC_calc;
                if((unsigned char)donnes_recue == CRC_calc || retry_counter[0] >= NBRETRY)
                {
                    retry_counter[0]=0;
                    break;
                }
                qDebug() << "Mauvaise transmission Ligne #" << line_no+1;
                retry_counter[0]++;
                retry=true;
            }
            retry = false;
            str_couleur = stream_couleur.read(NBCHARSCOMM);

            while(true){
                QString str_temp = str_couleur;
                if(retry)
                {
                    str_temp.prepend(char(0x16));
                }
                str_temp.prepend(char(code+line_no+5));
                str_temp.append(char(10));
                _serial->write(str_temp.toLatin1().constData(),str_temp.length());
                char donnes_recue = 0;
                if(!_serial->waitForReadyRead(DELAYSERIAL))
                {
                    QMessageBox::critical(NULL,"Erreur","Timeout");
                    return;
                }
                _serial->read(&donnes_recue,1);
                unsigned char CRC_calc;
                CRC_calc = calculCRC(str_couleur.toLatin1().constData(),str_couleur.length());
                qDebug() << "Couleur Ligne # " << line_no+1;
                qDebug() << "Micro ->" << (unsigned char)donnes_recue;
                qDebug() << "PC    ->" << CRC_calc;
                if((unsigned char)donnes_recue == CRC_calc || retry_counter[1] >= NBRETRY)
                {
                    retry_counter[1] = 0;
                    break;
                }
                qDebug() << "Mauvaise transmission Ligne #" << line_no+1;
                retry_counter[1]++;
                retry=true;
            }
            code=char(2);
        }
    }
}

/**
 * @fn MatriceRgb::unicodetoCP437(QString unicode_str)
 * @brief Converts a Unicode QString to a slightly modified version of the CP437 "standard" that is used in the physical matrix's ROM.
 * The matrix uses a slightly modified version of the <a href="http://en.wikipedia.org/wiki/Cp437">CP437</a> character set.
 * @param unicode_str The input QString in Unicode
 * @return The converted QString
 */
QString MatriceRgb::unicodetoCP437(QString unicode_str){
    QString parsed_message = unicode_str;

    //Unicode to matrix ROM character code
    parsed_message.replace(0x25B2,0x1E); //Arrow UP
    parsed_message.replace(0x25BC,0x1F); //Arrow DOWN
    parsed_message.replace(0x00E9,0x82); //é
    parsed_message.replace(0x00C7,0x80); //Ç
    parsed_message.replace(0x00FC,0x81); //ü
    parsed_message.replace(0x00E2,0x83); //â
    parsed_message.replace(0x00E4,0x84); //ä
    parsed_message.replace(0x00E0,0x85); //à
    parsed_message.replace(0x00E7,0x87); //ç
    parsed_message.replace(0x00EA,0x88); //ê
    parsed_message.replace(0x00EB,0x89); //ë
    parsed_message.replace(0x00E8,0x8A); //à
    parsed_message.replace(0x00EF,0x8B); //ï
    parsed_message.replace(0x00EE,0x8C); //î
    parsed_message.replace(0x00EC,0x8D); //ì
    parsed_message.replace(0x00C4,0x8E); //Ä
    parsed_message.replace(0x00C9,0x90); //É
    parsed_message.replace(0x00E6,0x91); //æ
    parsed_message.replace(0x00C6,0x92); //Æ
    parsed_message.replace(0x00F4,0x93); //ô
    parsed_message.replace(0x00F6,0x94); //ö
    parsed_message.replace(0x00F2,0x95); //ò
    parsed_message.replace(0x00FB,0x96); //û
    parsed_message.replace(0x00F9,0x97); //ù
    parsed_message.replace(0x00FF,0x98); //ÿ
    parsed_message.replace(0x00D6,0x99); //Ö
    parsed_message.replace(0x00DC,0x9A); //Ü
    parsed_message.replace(0x00A2,0x9B); //¢
    parsed_message.replace(0x00A3,0x9C); //£
    parsed_message.replace(0x00A5,0x9D); //¥
    parsed_message.replace(0x00E1,0xA0); //á
    parsed_message.replace(0x00ED,0xA1); //í
    parsed_message.replace(0x00F3,0xA2); //ó
    parsed_message.replace(0x00FA,0xA3); //ú
    parsed_message.replace(0x00AB,0xAE); //«
    parsed_message.replace(0x00BB,0xAF); //»
    parsed_message.replace(0x00B0,0xF8); //°
    parsed_message.replace(0x20AC,0x1C); //€
    parsed_message.replace(0x2013,0x2D); //–
    return parsed_message;
}

/**
 * @fn QString MatriceRgb::createColorString(int line_no)
 * @brief Creates a color string using the default parameters
 * @param line_no The line for witch the sting is to be created
 * @return The created QString
 */
QString MatriceRgb::createColorString(int line_no){
    return QString(_string_lines[line_no].count(),(_colours[line_no]<<4)+_colours[line_no+2]);
}

/**
 * @fn unsigned char MatriceRgb::calculCRC(const char* message,int length)
 * @brief Calculates a simple CRC8 on a char array. This code was taken from  <a href="http://www.leonardomiliani.com/en/2013/un-semplice-crc8-per-arduino/">here</a>.
 * @param message A pointer to the beginning of the char array
 * @param length The length in bytes of the message
 * @return The calculated CRC
 */
unsigned char MatriceRgb::calculCRC(const char* message,int length){
    //CRC-8 - based on the CRC8 formulas by Dallas/Maxim
    //code released under the therms of the GNU GPL 3.0 license
    unsigned char crc = 0x00;
    while (length--) {
        unsigned char extract = *message++;
        for (int tempI = 8; tempI; tempI--) {
            unsigned char sum = (crc ^ extract) & 0x01;
            crc >>= 1;
            if (sum) {
                crc ^= 0x8C;
            }
            extract >>= 1;
        }
    }
    return crc;
}

/**
 * @brief Sends the scroll speed (in ms) to the display. Default is 15ms
 * @param speed The speed in ms
 */
void MatriceRgb::sendSpeed(unsigned char speed){
    _scroll_speed = speed;
    if (_serial->isOpen()){
        QString str_temp;
        str_temp += char(11);
        str_temp += char(_scroll_speed);
        _serial->write(str_temp.toLatin1().constData(),str_temp.length());
    }
}
