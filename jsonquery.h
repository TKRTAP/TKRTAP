#ifndef JSONQUERY_H
#define JSONQUERY_H

#include <QObject>
#include <QNetworkReply>

/**
 * @brief The JsonQuery class handles the JSON queries to Quandl and Yahoo and parses them into a simple string.
 */
class JsonQuery : public QObject
{
    Q_OBJECT
public:
    explicit JsonQuery(QObject *parent = 0);
    inline void setServiceName(QString service_name);
    inline void setTickerNames(QStringList tkr_names);
    inline void setAuthCodeQuandl(QString aut_code);

signals:

    /**
     * @brief Signal used when the JSON request has been parsed
     * @param str_list The formatted text message String List
     * @param str_colour  The formatted colour string
     */
    void parsingComplete(QStringList str_list, QString str_colour);

public slots:
    void sendRequest();

private slots:
    void parseJSON();

private:
    QUrl createJsonUrl();

    QString _service_name;          /**< @brief The name of the JSON data service provider. Note: Only Quandl and Yahoo are currently supported*/
    QStringList _ticker_names;      /**< @brief List of tickers*/
    QString _Quandl_auth_token;     /**< @brief The Quandl Auth token is needed to make more than 50 requests per day*/

    QNetworkAccessManager _manager; /**< @brief The Network manager used to send the JSON requests*/
    QNetworkReply *_current_reply;  /**< @brief The current reply*/
};

/**
 * @brief Sets the service used for the JSON query
 * @param service_name The name of the chosen service
 */
inline void JsonQuery::setServiceName(QString service_name){
    _service_name = service_name;
}

/**
 * @brief Sets the list of tickers
 * @param tkr_names The list of tickers
 */
inline void JsonQuery::setTickerNames(QStringList tkr_names){
    _ticker_names = tkr_names;
}

/**
 * @brief Set the Quandl auth code
 * @param auth_code The auth code used by Quandl
 */
inline void JsonQuery::setAuthCodeQuandl(QString auth_code){
    _Quandl_auth_token = auth_code;
}

#endif // JSONQUERY_H
