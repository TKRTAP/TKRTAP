/**
  * \file matricergb.h
  * \brief Declaration of the RGB Matrix class
  * \author Quentin Barry-Marcheterre
  * \date 07/15/2014
*/

#ifndef MATRICERGB_H
#define MATRICERGB_H

#include <QtSerialPort>

/**
 * @brief The MatriceRgb class is used to link the physical matrix display with the rest of the program. It can write text on both lines of the display
 * in 8 different colours.
 */
class MatriceRgb : public QObject
{
    Q_OBJECT
public:
    MatriceRgb();
    inline void setText(QString txt_line,int line_no);
    inline void setStringColor(QString txt_colour,int line_no);
    inline void setDefaultColors(int* colours);
    inline QList<QSerialPortInfo> getListPorts();

public slots:
    inline void setPortName(QString nom_port);
    bool toggleSerialPort();
    void sendAll();
    void sendLine(int line_no);
    void sendSpeed(unsigned char speed = 15);

private :
    unsigned char _scroll_speed;
    QString unicodetoCP437(QString unicode_str);
    QString createColorString(int line_no);
    unsigned char calculCRC(const char* message, int length);
    /**
     * @brief Pointer to a QSerialPort object
     */
    QSerialPort *_serial;
    /**
     * @brief The array of QStrings containing the message's text
     */
    QString _string_lines[2];
    /**
     * @brief The array of QString containing the message's colour information
     */
    QString _string_colours[2];
    /**
     * @brief The QString containing the serial port's name
     */
    QString _string_port_name;
    /**
     * @brief The selected baud rate for the serial communication
     */
    int _port_baudrate;
    /**
     * @brief _data_bits_port
     */
    int _data_bits_port;
    /**
     * @brief Array containing the default colour parameters (text & background) for both lines. The fist two elements are the text colour for
     * line 1 and 2 respectively while the last two elements are the background colours. Used by #createColorString.
     */
    int _colours[4];

};

/**
 * @fn MatriceRgb::setText(QString txt_line,int line_no)
 * @brief Sets the text for a given line
 * @param txt_line The text to be set
 * @param line_no The line number
 */
inline void MatriceRgb::setText(QString txt_line,int line_no)
{
    _string_lines[line_no]=txt_line;
}

/**
 * @fn MatriceRgb::setPortName(QString port_name)
 * @brief Sets the serial port that will be used
 * @param port_name The name of the serial port as specified by the OS
 */
inline void MatriceRgb::setPortName(QString port_name)
{
    _string_port_name=port_name;
}

/**
 * @fn QList<QSerialPortInfo> MatriceRgb::getListPorts()
 * @brief Returns a QList of the available serial ports as returned by the OS. This is a list of QSerialPortInfo.
 * @return A QList of the available ports
 */
inline QList<QSerialPortInfo> MatriceRgb::getListPorts()
{
    return QSerialPortInfo::availablePorts();
}

/**
 * @fn MatriceRgb::setStringColor(QString txt_colour,int line_no)
 * @brief Sets the colour string for the specified line
 * @param txt_colour The string containing the colour information
 * @param line_no The line number
 */
inline void MatriceRgb::setStringColor(QString txt_colour,int line_no){
    _string_colours[line_no]=txt_colour;
}

/**
 * @fn MatriceRgb::setDefaultColors(int* colours)
 * @brief Sets the default colour information
 * @param colours A pointer to the first element of ints containing the default colour information
 */
inline void MatriceRgb::setDefaultColors(int* colours)
{
    memcpy(_colours,colours,sizeof(int)*4);
}

#endif // MATRICERGB_H
