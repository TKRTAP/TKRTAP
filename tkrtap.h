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
    void linkSEC();
    void linkCharts();
    void linkScreener();
    void linkEcon();
    void linkFinStat();
    void linkAnalysis();
    void linkOther();
    void on_Spreadsheet_clicked();
    void on_AddButton_clicked();
    void on_DelButton_clicked();
    void on_SaveButton_clicked();
    void SaveSettings();
    void on_LoadButton_clicked();
    void LoadSettings();
    void LoadMarketMap();
    void on_AllButton_clicked();

    void on_SpreadsheetButtonTextEdit_textChanged(const QString &arg1);

    void on_MarkmapButtonTextEdit_textChanged(const QString &arg1);

    void on_AnalysisButtonTextEdit_textChanged(const QString &arg1);

    void on_SECButtonTextEdit_textChanged(const QString &arg1);

    void on_FinStatButtonTextEdit_textChanged(const QString &arg1);

    void on_EconButtonTextEdit_textChanged(const QString &arg1);

    void on_ScreenerButtonTextEdit_textChanged(const QString &arg1);

    void on_ChartsButtonTextEdit_textChanged(const QString &arg1);

    void setScrollSpeed();
    void setCouleurs();
    void setLigne1();
    void setLigne2();
    void toggleSerialPort();
    void Removing_Duplicates_RSS();

    void openStockChart(QString ticker);
    QStringList GenerateStockRSS();

    void on_button_add_link_clicked();

    void on_button_remove_link_clicked();

    void on_AddStockRSSButton_clicked();

    void on_button_clear_RSS_links_clicked();

    void timerStart();

    void timerEnd();

    void on_AuthTokenpushButton_clicked();

    void validate_tickers();


    //JSON
    void JSONParseComplete(QStringList txt_list,QString colour_text);
    void SetupRequest();

    //RSS
    void startRSS();
    void updateTable(QStringList str_list, QStringList link_rss, QStringList time_rss);
    void openRSSLink(QListWidgetItem* item);


    void on_Save_Button_RSS_clicked();

    void on_Load_Button_RSS_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

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
    MarketMapView *mDialog;
    QuickStockChart *mDialog2;

    MatriceRgb *_matrice;
    QString _nom_port;
    QTimer *Ticker_Timer;
    QTimer *RSS_Timer;

    //Variables used for stock price data
    QNetworkAccessManager manager;
    QNetworkReply *currentReply;
   };

#endif // TKRTAP_H
