/**
  * \file jsonquery.cpp
  * \brief Implementation of the jsonquery class
  * \author Quentin Barry-Marcheterre and Shariff Côté
  * \date 07/16/2014
*/

#include "jsonquery.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#define BLACK   0
#define RED     1
#define GREEN   2
#define YELLOW  3

/**
 * @brief Default constructor
 * @param parent Parent of the object (default = 0)
 */
JsonQuery::JsonQuery(QObject *parent) :
    QObject(parent)
{
}

/**
 * @brief Creates an URL using the ticker names for Quandl or Yahoo
 * @return The QUrl for the specified JSON request
 */
QUrl JsonQuery::createJsonUrl(){
    QString url_string;

    if(_service_name == "Quandl")
    {
        url_string = "http://quandl.com/api/v1/multisets.json?columns=";
        foreach (const QString &str_ticker, _ticker_names)
        {
            url_string += "WIKI." + str_ticker + ".4,";
        }
        url_string.remove(url_string.size()-1, 1);
        url_string += "&rows=2&auth_token=";
        url_string += _Quandl_auth_token;
    }

    else if(_service_name == "Yahoo")
    {
        url_string = "http://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20csv%20where%20url%3D%27http%3A%2F%2Fdownload.finance.yahoo.com%2Fd%2Fquotes.csv%3Fs%3D";
        foreach (const QString &str_ticker, _ticker_names)
        {
            url_string += str_ticker + ",";
        }
        url_string.remove(url_string.size()-1, 1);
        url_string += "%26f%3Dsl1d1t1c1ohgv%26e%3D.csv%27%20and%20columns%3D%27symbol%2Cprice%2Cdate%2Ctime%2Cchange%2Ccol1%2Chigh%2Clow%2Ccol2%27&format=json&callback=";
    }
    return QUrl(url_string);
}

/**
 * @brief Sets up the request and connects the proper signal to the parsing function
 */
void JsonQuery::sendRequest(){
    QNetworkRequest APIurl(createJsonUrl());
    _current_reply = _manager.get(APIurl);
    connect(_current_reply, SIGNAL(finished()), this, SLOT(parseJSON()));
}

/**
 * @brief Parses the received information from the JSON request and emits the #parsingComplete() signal when done
 */
void JsonQuery::parseJSON(){
    QByteArray data = _current_reply->readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(data));
    QJsonObject json = loadDoc.object();
    int _nb_tickers = _ticker_names.count();

    QString symbol_string,price_string,change_string, time_string, percent_change_string;
    double price,change;

    unsigned char colour;
    QString UpSign = QString::fromUtf8("\u25B2");
    QString DownSign = QString::fromUtf8("\u25BC");

    QString final_text_string, final_colour_string;
    QStringList str_list;

    if (_service_name == "Yahoo"){
        QJsonObject company;
        for(int comp_no=0;comp_no<_nb_tickers;comp_no++){
            if(!(_nb_tickers-1)) //Only one ticker
            {
                company = json["query"].toObject().value("results").toObject().value("row").toObject();
            }
            else                 //More than one ticker
            {
                company = json["query"].toObject().value("results").toObject().value("row").toArray().at(comp_no).toObject();
            }
            symbol_string=company.value("symbol").toString();
            price_string=company.value("price").toString();
            change_string=company.value("change").toString();
            time_string=company.value("time").toString();
            price = price_string.toDouble();
            change = change_string.toDouble();
            percent_change_string = QString::number((change/price)*100, 'f', 2);

            QString temp_text_string; //A temporary string is required to properly create the colour string
            temp_text_string = symbol_string;              //Company name
            temp_text_string += " $" + QString::number(price, 'f', 2);                        //Stock price

            if (symbol_string.contains("=X", Qt::CaseInsensitive)){
                    temp_text_string.remove(symbol_string.length()-2, 2);
                    //temp_text_string.remove(QChar('='), Qt::CaseInsensitive);
                    temp_text_string.insert(3, "/");
                    temp_text_string+= char(32);
                    colour=(YELLOW<<4)+BLACK;
            }

            else{
                if (change >= 0)
                {
                    temp_text_string+= " +" + QString::number((change), 'f', 2);
                    temp_text_string+=UpSign;                                              //Change arrow
                    temp_text_string+= "+" + percent_change_string + "% "; //Change in %
                    colour=(GREEN<<4)+BLACK;
                }
                else if (change < 0)
                {
                    temp_text_string+= " " + QString::number((change), 'f', 2);
                    temp_text_string+=DownSign;                                            //Change arrow
                    temp_text_string+= percent_change_string + "% "; //Change in %
                    //                temp_text_string+= time_string + " ";
                    colour=(RED<<4)+BLACK;
                }
                else
                {
                    temp_text_string = symbol_string + " N/A ";                //Invalid ticker
                    colour=(YELLOW<<4)+BLACK;
                }
                if (price == 0){
                    temp_text_string = symbol_string + " N/A ";                //Invalid ticker
                    colour=(YELLOW<<4)+BLACK;
                }
            }
            //            temp_text_string+=
            final_text_string=temp_text_string;
            if (temp_text_string == symbol_string + " N/A "){
                //Doesn't add the time
            }
            else{
                final_text_string+=time_string+char(32);
            }
            str_list += final_text_string;
            final_colour_string+=QString(temp_text_string.count(),colour);            //Creation of the colour string
        }
    }

    else if (_service_name == "Quandl")
    {
        QJsonValue price = json["data"];
        if(price.type() == QJsonValue::Array)
        {
            QJsonArray price_array = price.toArray();
            for (int i=1; i<=_nb_tickers;i++)
            {
                QString current_price_string(QString::number(price_array.at(0).toArray().at(i).toDouble(),'f',6));
                QString last_price_string(QString::number(price_array.at(1).toArray().at(i).toDouble(),'f',6));

                double current_price(current_price_string.toDouble());
                double last_price(last_price_string.toDouble());
                double change = current_price-last_price;
                percent_change_string = QString::number((change/last_price)*100, 'f', 2);
                QString temp_text_string; //A temporary string is required to properly create the colour string
                if (percent_change_string == "nan"){
                    percent_change_string = "0.00";
                }
                if(current_price == 0 or current_price > 250000 or current_price < 0)
                {
                    temp_text_string = _ticker_names.at(i-1) + " N/A ";                        //Invalid ticker
                    colour=(YELLOW<<4)+BLACK;
                }
                else{
                    temp_text_string = _ticker_names.at(i-1) + " $";                               //Company name
                    temp_text_string += QString::number(current_price, 'f', 2);              //Stock price

                    if (change >= 0)
                    {
                        temp_text_string+= " +" + QString::number((change), 'f', 2);
                        temp_text_string += UpSign;                                          //Change arrow
                        temp_text_string+= "+" + percent_change_string + "% ";//Change in %
                        colour=(GREEN<<4)+BLACK;
                    }
                    else if (change < 0)
                    {
                        temp_text_string+= " " + QString::number((change), 'f', 2);
                        temp_text_string += DownSign;                                        //Change arrow
                        temp_text_string+= percent_change_string + "% ";//Change in %
                        colour=(RED<<4)+BLACK;
                    }
                    else
                    {
                        temp_text_string = _ticker_names.at(i-1) + " N/A ";                        //Invalid ticker
                        colour=(YELLOW<<4)+BLACK;
                    }
                }

                final_text_string+=temp_text_string;
                str_list += temp_text_string;
                final_colour_string+=QString(temp_text_string.count(),colour);                 //Creation of the colour string
            }
        }
    }
    emit parsingComplete(str_list,final_colour_string);
}
