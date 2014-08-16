#ifndef RSSCLIENT_H
#define RSSCLIENT_H

#include <QString>
#include <QStringList>
#include <QNetworkAccessManager>
#include <QXmlStreamReader>
#include <QNetworkReply>
#include <QStandardItemModel>
#include <QDateTime>

/**
 * @brief The RssClient class handles the reception and sorting (by date) of multiple RSS news feeds
 */
class RssClient : public QObject
{
    Q_OBJECT
public:
    RssClient();
    void loadRSS(QStringList list_RSS);

public slots:
    void fetch();

signals:
    /**
     * @brief Signal used when the RSS are finished reading
     * @param title_rss List of RSS titles
     * @param link_rss List of the RSS links
     */
    void rssFinished(QStringList title_rss, QStringList link_rss);


private slots:
    void parseXml();
    void moreRSS();
    void readyRead();
    void error(QNetworkReply::NetworkError);
    void metaDataChanged();
    void get(QUrl url);


private:
    QDateTime parseDate(QString str_date);
    QStandardItemModel* _model_data;        /**< @brief Contains all the extracted info from the RSS feeds*/
    int _no_data;                           /**< @brief Current count of received RSS news items*/
    int _no_rss;                            /**< @brief Current count of RSS feeds*/
    QXmlStreamReader _xml;                  /**< @brief XML object*/
    QString _current_tag;                   /**< @brief String containing the currently read tag from the XML/RSS feed*/
    QString _date_string;                   /**< @brief String containing the current date from the RSS News item*/
    QString _link_string;                   /**< @brief String containing the current link from the RSS News item*/
    QString _title_string;                  /**< @brief String containing the current title from the RSS News item*/

    QStringList _link_string_list;          /**< @brief List of stings containing all the URLs for the RSS feeds to be read*/

    QNetworkAccessManager _manager;         /**< @brief The manager used to perform the network request*/
    QNetworkReply *_current_reply;          /**< @brief The current network reply*/
};

#endif // RSSCLIENT_H
