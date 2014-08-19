/**
  * \file tkrtap.h
  * \brief Implementation of the main GUI class
  * \author Shariff Côté and Quentin Barry-Marcheterre
  * \date 07/16/2014
*/

#ifndef TKRTAP_H
#define TKRTAP_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include <QStringListModel>
#include <QSettings>
#include <QDebug>
#include <QRect>
//#include <QXmlStreamReader>
#include <QTreeWidget>
#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QtWebKitWidgets/QWebView>
#include <QSet>
#include <QTimer>
#include <QListWidgetItem>
#include "marketmapview.h"
#include "quickstockchart.h"
#include "matricergb.h"
#include "rssclient.h"
#include <QFile>
#include <QTextStream>
#include <cstdlib>
#include <iostream>
#include <jsonquery.h>
#include <QFileDialog>

namespace Ui {
class TKRTAP;
}

class TKRTAP : public QMainWindow
{
    Q_OBJECT
private slots:
    void linkSEC(); /**< @brief Function that opens in a default browser seclive.com Link*/
    void linkCharts(); /**< @brief Function that opens in a default browser freestockcharts.com Link*/
    void linkScreener(); /**< @brief Function that opens in a default browser Finviz Screener Link*/
    void linkEcon(); /**< @brief Function that opens in a default browser tradingeconomics.com Link*/
    void linkFinStat(); /**< @brief Function that opens in a default browser Morningstar financial statements Link*/
    void linkAnalysis(); /**< @brief Function that opens in a default browser Seeking Alpha Link*/
    void linkOther(); /**< @brief Function that opens in a default browser Google Spreadsheet Link*/
    void on_Spreadsheet_clicked();

    void on_AddButton_clicked(); /**< @brief Adds a stock*/
    void on_DelButton_clicked(); /**< @brief Function that deletes a stock*/

    void on_SaveButton_clicked(); /**< @brief Triggers the SaveSettings Function*/
    void SaveSettings(); /**< @brief Opens the save file dialog*/

    void on_LoadButton_clicked(); /**< @brief Triggers the LoadSettings function when clicked*/
    void LoadSettings(); /**< @brief Opens the load file dialog*/

    void LoadMarketMap(); /**< @brief Opens the Market Map dialog box*/
    void on_AllButton_clicked(); /**< @brief Triggers all the buttons*/

    void on_SpreadsheetButtonTextEdit_textChanged(const QString &arg1); /**< @brief Function that opens in a default browser the SEC Link*/
    void on_MarkmapButtonTextEdit_textChanged(const QString &arg1); /**< @brief Changes the text on the market map button*/
    void on_AnalysisButtonTextEdit_textChanged(const QString &arg1);  /**< @brief Changes the text on the Analysis button*/
    void on_SECButtonTextEdit_textChanged(const QString &arg1);  /**< @brief Changes the text on the SEC button*/
    void on_FinStatButtonTextEdit_textChanged(const QString &arg1);   /**< @brief Changes the text on the Financial Statement button*/
    void on_EconButtonTextEdit_textChanged(const QString &arg1);    /**< @brief Changes the text on the Economic indicators button*/
    void on_ScreenerButtonTextEdit_textChanged(const QString &arg1);   /**< @brief Changes the text on the Screener button*/
    void on_ChartsButtonTextEdit_textChanged(const QString &arg1);    /**< @brief Changes the text on the Charts button*/

    void setScrollSpeed();    /**< @brief Changes the speed of the LED Panel*/
    void setCouleurs();       /**< @brief Changes the colors of the LED Panel*/
    void setLigne1();         /**< @brief Changes the text on the first line of the LED Panel*/
    void setLigne2();         /**< @brief Changes the text on the second line of the LED Panel*/
    void toggleSerialPort();
    void Removing_Duplicates_RSS();   /**< @brief Functions that removes any duplicates in the RSS link list*/

    void on_listView_doubleClicked(const QModelIndex &index); /**< @brief Triggers the quick stock chart dialog of the stock clicked*/
    void openStockChart(QString ticker); /**< @brief Opens the Finviz stock chart of the inputed ticker*/

    QStringList GenerateStockRSS();  /**< @brief Creates RSS links for each stocks*/

    void on_button_add_link_clicked();   /**< @brief Adds a editable line to the RSS link list*/
    void on_button_remove_link_clicked();  /**< @brief Deletes the selected link*/
    void on_AddStockRSSButton_clicked();   /**< @brief Adds a RSS link for each stock in watchlist*/
    void on_button_clear_RSS_links_clicked();  /**< @brief Clears the RSS link list*/

    void timerStart();   /**< @brief Starts the timer*/
    void timerEnd();    /**< @brief Ends the timer*/

    void on_AuthTokenpushButton_clicked();  /**< @brief Link to the Quandl Auth Token web page*/

    void validate_tickers();  /**< @brief Check if the user input is valid and if not deletes it*/

    //JSON
    void JSONParseComplete(QStringList txt_list,QString colour_text); /**< @brief Formats the stock quotes results*/
    void SetupRequest();  /**< @brief Updates the stock quotes*/

    //RSS
    void startRSS();   /**< @brief Starts the RSS search*/
    void updateTable(QStringList str_list, QStringList link_rss, QStringList time_rss); /**< @brief Updates the RSS results list in the UI*/
    void openRSSLink(QListWidgetItem* item); /**< @brief Opens the linked RSS*/

    void on_Save_Button_RSS_clicked();   /**< @brief Triggers the save file dialog for the RSS link list*/

    void on_Load_Button_RSS_clicked();   /**< @brief Triggers the load file dialog for the RSS link list*/

public:
    QStringListModel *RSSlinklistmodel;
    explicit TKRTAP(QWidget *parent = 0);
    ~TKRTAP();



private:

    JsonQuery *_JSON_query;                     /**< @brief JSON query object*/

    Ui::TKRTAP *ui;
    QStringList _rss_title,_rss_link;
    QStringList _rss_time;                      /**< @brief String list containing the RSS articles published times*/
    RssClient *_rss_client;
    QStringListModel *model;
    MarketMapView *mDialog;                     /**< @brief Dialog box of the Market Map*/
    QuickStockChart *mDialog2;                  /**< @brief Dialog box of the Quick finviz stock chart*/

    MatriceRgb *_matrice;
    QString _nom_port;
    QTimer *Ticker_Timer;
    QTimer *RSS_Timer;

    //Variables used for stock price data
    QNetworkAccessManager manager;
    QNetworkReply *currentReply;
   };

#endif // TKRTAP_H
