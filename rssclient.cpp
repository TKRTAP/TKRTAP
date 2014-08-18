/**
  * \file rssclient.cpp
  * \brief Implementation of the RSS client class
  * \author Quentin Barry-Marcheterre
  * \date 07/16/2014
*/

#include "rssclient.h"
#include <QDebug>
#include <QNetworkReply>
#include <QAbstractTableModel>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>

#include <QHash>

#include "datetime_utils.hpp"
#include <iostream>
#include <string>
#include "strtk.hpp"

/**
 * @fn RssClient::RssClient()
 * @brief Constructor
 */
RssClient::RssClient()
{
    _model_data = new QStandardItemModel;
    _model_data->setColumnCount(3);
    _no_data = 0;
}

/**
 * @fn RssClient::parseXml()
 * @brief Parses the XML object and extracts the title, date and link information. These are strored in
 * RssClient#_model_data
 */
void RssClient::parseXml()
{

    while (!_xml.atEnd()) {
        _xml.readNext();
        if (_xml.isStartElement()) {
            if (_xml.name() == "item")

                _link_string = _xml.attributes().value("rss:about").toString();
            _current_tag = _xml.name().toString();
        } else if (_xml.isEndElement()) {
            if (_xml.name() == "item") {
                QStandardItem *title = new QStandardItem;
                QStandardItem *date = new QStandardItem;
                QStandardItem *link = new QStandardItem;
                title->setText(_title_string);
                link->setText(_link_string);

                QDateTime date_qt = parseDate(_date_string);
                date->setText(QString::number(date_qt.toTime_t()));

                _model_data->setItem(_no_data,0,title);
                _model_data->setItem(_no_data,1,date);
                _model_data->setItem(_no_data++,2,link);

                _title_string.clear();
                _link_string.clear();
                _date_string.clear();
            }

        } else if (_xml.isCharacters() && !_xml.isWhitespace()) {
            if (_current_tag == "title"){
                _title_string = _xml.text().toString();
            }
            else if (_current_tag == "link"){
                _link_string += _xml.text().toString();
            }

            else if (_current_tag == "pubDate"){
                _date_string += _xml.text().toString();
            }
        }
    }
    if (_xml.error() && _xml.error() != QXmlStreamReader::PrematureEndOfDocumentError) {
        qWarning() << "XML ERROR:" << _xml.lineNumber() << ": " << _xml.errorString();
    }
    moreRSS();
}

/**
 * @fn RssClient::fetch
 * @brief fetches the first RSS link. If there are no RSS links loaded, will do nothing
 */
void RssClient::fetch()
{
    _model_data->clear();
    _no_rss = 0;
    _xml.clear();
    if(_link_string_list.count()){
        QUrl url(_link_string_list.at(_no_rss));
        _no_rss++;
        get(url);
    }

}

/**
 * @brief Fetches every RSS link after the first and emits the #rssFinished when all the RSS links are finished
 * reading
 */
void RssClient::moreRSS(){
    if(_no_rss == _link_string_list.count())
    {
        if(!_no_data){
            return;
        }
        QStringList str_rss,link_rss,date_rss;
        _model_data->sort(1,Qt::DescendingOrder);
        qDebug() << _no_data << "RSS Loaded";
        _no_data--;
        for(int i=0;i<_no_data;i++){
            QDateTime date_time = QDateTime::fromTime_t(_model_data->item(i,1)->text().toDouble());
            str_rss << _model_data->item(i,0)->text();
            link_rss << _model_data->item(i,2)->text();
            date_rss << date_time.toString("HH:mm");
        }
        _no_data = 0;
        emit rssFinished(str_rss,link_rss,date_rss);
        return;
    }
    _xml.clear();
    QUrl url(_link_string_list.at(_no_rss));
    _no_rss++;
    get(url);

}

/**
 * @fn RssClient::get(QUrl url)
 * @brief Sets up the QNetworkAccessManager and connects its signals to various slots
 * @param url The url of the RSS feed to read
 */
void RssClient::get(QUrl url)
{
    QNetworkRequest request(url);
    _current_reply = _manager.get(request);
    connect(_current_reply, SIGNAL(metaDataChanged()), this, SLOT(metaDataChanged()));
    connect(_current_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));
    connect(_current_reply, SIGNAL(finished()),this, SLOT(readyRead()));

}

/**
 * @fn RssClient::readyRead()
 * @brief Adds the received data to the XML object
 */
void RssClient::readyRead()
{
    int statusCode = _current_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if (statusCode >= 200 && statusCode < 300) {
        QByteArray data = _current_reply->readAll();
        _xml.addData(data);
        parseXml();
    }
}

/**
 * @fn RssClient::error(QNetworkReply::NetworkError)
 * @brief Error handling
 */
void RssClient::error(QNetworkReply::NetworkError)
{
    qWarning("error retrieving RSS feed");
    _current_reply->disconnect(this);
    _current_reply->deleteLater();
    _current_reply = 0;
}

/**
 * @brief Used when meta data is changed
 */
void RssClient::metaDataChanged()
{
    QUrl redirectionTarget = _current_reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
    if (redirectionTarget.isValid()) {
        get(redirectionTarget);
    }
}

/**
 * @fn RssClient::loadRSS(QStringList list_RSS)
 * @brief Sets the RSS links
 * @param list_RSS The list of RSS links
 */
void RssClient::loadRSS(QStringList list_RSS){
    _link_string_list = list_RSS;
}

/**
 * @fn RssClient::parseDate(QString str_date)
 * @brief Parses the date and time contained in a QString. This function relies on the
 * <a href="http://www.partow.net/programming/datetime/index.html">Date And Time Parsing Utilities Library</a>
 * by Arash Partow.
 * @param str_date The QString containing the date to parse
 * @return A QDateTime containing the parsed date
 */
QDateTime RssClient::parseDate(QString str_date){

    QHash<QString,QString> time_zones;
    time_zones.insert("EDT","-0400");

    bool check = true;
    QString str_time_zone = str_date.mid(str_date.lastIndexOf(char(32))+1);
    str_time_zone.toInt(&check); //Check

    if(!check && time_zones.contains(str_time_zone)){

        str_date.remove(str_time_zone);
        str_date.append(time_zones[str_time_zone]);
    }
    else if(!check && !time_zones.contains(str_time_zone)){
        //           QMessageBox::critical(NULL,tr("Erreur"),"_title_string");
        qDebug() << "ERR";
    }

    dt_utils::datetime dt;
    dt_utils::datetime_format22 dt21(dt);

    strtk::string_to_type_converter(str_date.toStdString(),dt21);

    QDateTime datetime_qt(QDate(dt.year,dt.month,dt.day),QTime(dt.hour,dt.minute,dt.second));
    datetime_qt.setUtcOffset(dt.tzd*60);
    return datetime_qt;
}
