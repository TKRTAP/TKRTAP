/**
  * \file tkrtap.cpp
  * \brief Implementation of the main GUI class
  * \author Shariff Côté and Quentin Barry-Marcheterre
  * \date 07/16/2014
*/

#include "tkrtap.h"
#include "ui_tkrtap.h"
#include "marketmapview.h"
#include "matricergb.h"
#include "jsonquery.h"
#define NOIR 0
#define ROUGE 1
#define VERT 2
#define JAUNE 3
#define BLEU 4
#define MAGENTA 5
#define CYAN 6
#define BLANC 7

#define LINE1 0
#define LINE2 1

TKRTAP::TKRTAP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TKRTAP)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icons/img/tkrtapico.ico"));
    connect(ui->SEC,SIGNAL(clicked()),this,SLOT(linkSEC()));
    connect(ui->Charts,SIGNAL(clicked()),this,SLOT(linkCharts()));
    connect(ui->Screener,SIGNAL(clicked()),this,SLOT(linkScreener()));
    connect(ui->Econ,SIGNAL(clicked()),this,SLOT(linkEcon()));
    connect(ui->FinStat,SIGNAL(clicked()),this,SLOT(linkFinStat()));
    connect(ui->Analysis,SIGNAL(clicked()),this,SLOT(linkAnalysis()));
    connect(ui->Other,SIGNAL(clicked()),this,SLOT(linkOther()));

    //JSON query---------------------------------------------------------------------------------------------------
    _JSON_query = new JsonQuery();
    connect(_JSON_query,SIGNAL(parsingComplete(QStringList,QString)),this,SLOT(JSONParseComplete(QStringList,QString)));

    //LED Panel----------------------------------------------------------------------------------------------------
    _matrice = new MatriceRgb;
    QList<QSerialPortInfo> list = _matrice->getListPorts();
    for (QList<QSerialPortInfo>::ConstIterator iterator = list.cbegin(); iterator != list.cend(); ++iterator) {
        ui->comboBoxPorts->addItem(iterator->portName());
    }

    connect(ui->Line1,SIGNAL(editingFinished()),this,SLOT(setLigne1()));
    connect(ui->Line2,SIGNAL(editingFinished()),this,SLOT(setLigne2()));
    connect(ui->comboBoxScrollSpeed,SIGNAL(currentIndexChanged(int)),this,SLOT(setScrollSpeed()));
    connect(ui->comboBoxBottomlinebg,SIGNAL(activated(int)),this,SLOT(setCouleurs()));
    connect(ui->comboBoxToplinebg,SIGNAL(activated(int)),this,SLOT(setCouleurs()));
    connect(ui->comboBoxBottomlinetext,SIGNAL(activated(int)),this,SLOT(setCouleurs()));
    connect(ui->comboBoxToplinetext,SIGNAL(activated(int)),this,SLOT(setCouleurs()));

    connect(ui->bout_connexion,SIGNAL(clicked()),this,SLOT(toggleSerialPort()));

    //Mise en place des listes de couleurs
    QStringList noms_couleurs;
    noms_couleurs << "Black"
                  << "Red"
                  << "Green"
                  << "Yellow"
                  << "Blue"
                  << "Magenta"
                  << "Cyan"
                  << "White";

    ui->comboBoxToplinetext->addItems(noms_couleurs);
    ui->comboBoxToplinebg->addItems(noms_couleurs);
    ui->comboBoxBottomlinetext->addItems(noms_couleurs);
    ui->comboBoxBottomlinebg->addItems(noms_couleurs);

    //Timer for refreshing stock prices and RSS data
    Ticker_Timer = new QTimer(this);
    RSS_Timer = new QTimer(this);
    RSS_Timer->start(150000); //2.5 minutes
    connect(Ticker_Timer, SIGNAL(timeout()), this, SLOT(SetupRequest()));
    connect(ui->comboBoxRefresh,SIGNAL(currentIndexChanged(int)),this,SLOT(timerStart()));
    connect(RSS_Timer, SIGNAL(timeout()), this, SLOT(startRSS()));

    //Stock list----------------------------------------------------------------------------------------------------
    model = new QStringListModel (this);

    QStringList StockList;
    StockList << "GOOG" << "MSFT" << "AAPL" <<"CADUSD=X";

    model->setStringList(StockList);

    ui->listView->setModel(model);

    ui->listView->setEditTriggers(false);

    connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(validate_tickers()));
    connect(model,SIGNAL(rowsRemoved(QModelIndex,int,int)),this,SLOT(validate_tickers()));

    //Actions that updates stock prices
    connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(SetupRequest()));
    connect(model,SIGNAL(rowsRemoved(QModelIndex,int,int)),this,SLOT(SetupRequest()));

    connect(ui->DataFeedcomboBox,SIGNAL(activated(int)),this,SLOT(SetupRequest()));
    connect(ui->lineEditAuthToken,SIGNAL(editingFinished()),this,SLOT(SetupRequest()));

    //RSS Link list---------------------------------------------------------------------------------------------------
    RSSlinklistmodel = new QStringListModel (this);

    QStringList RSSlinklist;
    RSSlinklist << "http://rss.cbc.ca/lineup/topstories.xml";

    RSSlinklistmodel->setStringList(RSSlinklist);

    ui->RSSlistView->setModel(RSSlinklistmodel);

    ui->RSSlistView->setEditTriggers(false);

    //Load initial settings
    LoadSettings();

    //RSS

    _rss_client = new RssClient;
    connect(ui->button_loadRSS,SIGNAL(clicked()),this,SLOT(startRSS()));
    connect(_rss_client,SIGNAL(rssFinished(QStringList,QStringList,QStringList)),this,SLOT(updateTable(QStringList,QStringList,QStringList)));

    connect(ui->RSSBrowser,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(openRSSLink(QListWidgetItem*)));


    startRSS();

}

TKRTAP::~TKRTAP()
{
    SaveSettings();
    delete ui;
}

/**
 * @fn TKRTAP::linkSEC()
 * @brief Open the link in the default browser of the user
 */
void TKRTAP::linkSEC(){
    QDesktopServices::openUrl(QUrl(ui->linkEditSEC->text(), QUrl::TolerantMode));
}

/**
 * @fn TKRTAP::linkCharts()
 * @brief Open the link in the default browser of the user
 */
void TKRTAP::linkCharts(){
    QDesktopServices::openUrl(QUrl(ui->linkEditCharts->text(), QUrl::TolerantMode));
}

/**
 * @fn TKRTAP::linkScreener()
 * @brief Open the link in the default browser of the user
 */
void TKRTAP::linkScreener(){
    QDesktopServices::openUrl(QUrl(ui->linkEditScreener->text(), QUrl::TolerantMode));
}

/**
 * @fn TKRTAP::linkEcon()
 * @brief Open the link in the default browser of the user
 */
void TKRTAP::linkEcon(){
    QDesktopServices::openUrl(QUrl(ui->linkEditEcon->text(), QUrl::TolerantMode));
}

/**
 * @fn TKRTAP::linkFinStat()
 * @brief Open the link in the default browser of the user
 */
void TKRTAP::linkFinStat(){
    QDesktopServices::openUrl(QUrl(ui->linkEditFinStat->text(), QUrl::TolerantMode));
}

/**
 * @fn TKRTAP::linkAnalysis()
 * @brief Open the link in the default browser of the user
 */
void TKRTAP::linkAnalysis(){
    QDesktopServices::openUrl(QUrl(ui->linkEditAnalysis->text(), QUrl::TolerantMode));
}

/**
 * @fn TKRTAP::LoadMarketMap()
 * @brief Open the link of the Finviz MarketMap in a browser customized for it
 */
void TKRTAP::LoadMarketMap()
{
    //Open a dialog window for the Market Map
    mDialog = new MarketMapView(this,QUrl(ui->linkEditOther->text()));
    mDialog->show();
}

/**
 * @fn TKRTAP::linkOther()
 * @brief Open the link in the default browser of the user
 */
void TKRTAP::linkOther()
{
    //QDesktopServices::openUrl(QUrl(ui->linkEditOther->text(), QUrl::TolerantMode));
    LoadMarketMap();
}

/**
 * @fn TKRTAP::on_Spreadsheet_clicked()
 * @brief Open the link in the default browser of the user
 */
void TKRTAP::on_Spreadsheet_clicked()
{
    QDesktopServices::openUrl(QUrl(ui->linkEditSpreadsheet->text(), QUrl::TolerantMode));
}

//Editable Button Text----------------------------------------------------------------

/**
 * @fn TKRTAP::on_SpreadsheetButtonTextEdit_textChanged(const QString &arg1)
 * @brief Changes the text on the button
 * @param arg1 Text for the default Spreadsheet button
 */
void TKRTAP::on_SpreadsheetButtonTextEdit_textChanged(const QString &arg1)
{
    ui->Spreadsheet->setText(arg1);
}

/**
 * @fn TKRTAP::on_MarkmapButtonTextEdit_textChanged(const QString &arg1)
 * @brief Changes the text on the button
 * @param arg1 Text for the default MarketMap button
 */
void TKRTAP::on_MarkmapButtonTextEdit_textChanged(const QString &arg1)
{
    ui->Other->setText(arg1);
}

/**
 * @fn TKRTAP::on_AnalysisButtonTextEdit_textChanged(const QString &arg1)
 * @brief Changes the text on the button
 * @param arg1 Text for the default Analysis button
 */
void TKRTAP::on_AnalysisButtonTextEdit_textChanged(const QString &arg1)
{
    ui->Analysis->setText(arg1);
}

/**
 * @fn TKRTAP::on_SECButtonTextEdit_textChanged(const QString &arg1)
 * @brief Changes the text on the button
 * @param arg1 Text for the default SEC button
 */
void TKRTAP::on_SECButtonTextEdit_textChanged(const QString &arg1)
{
    ui->SEC->setText(arg1);
}

/**
 * @fn TKRTAP::on_FinStatButtonTextEdit_textChanged(const QString &arg1)
 * @brief Changes the text on the button
 * @param arg1 Text for the default FinStat button
 */
void TKRTAP::on_FinStatButtonTextEdit_textChanged(const QString &arg1)
{
    ui->FinStat->setText(arg1);
}

/**
 * @fn TKRTAP::on_EconButtonTextEdit_textChanged(const QString &arg1)
 * @brief Changes the text on the button
 * @param arg1 Text for the default Econ button
 */
void TKRTAP::on_EconButtonTextEdit_textChanged(const QString &arg1)
{
    ui->Econ->setText(arg1);
}

/**
 * @fn TKRTAP::on_ScreenerButtonTextEdit_textChanged(const QString &arg1)
 * @brief Changes the text on the button
 * @param arg1 Text for the default Screener button
 */
void TKRTAP::on_ScreenerButtonTextEdit_textChanged(const QString &arg1)
{
    ui->Screener->setText(arg1);
}

/**
 * @fn TKRTAP::on_ChartsButtonTextEdit_textChanged(const QString &arg1)
 * @brief Changes the text on the button
 * @param arg1 Text for the default Charts button
 */
void TKRTAP::on_ChartsButtonTextEdit_textChanged(const QString &arg1)
{
    ui->Charts->setText(arg1);
}

//Stock TAB------------------------------------------------------------------------------------
/**
 * @fn TKRTAP::on_AddButton_clicked()
 * @brief Adds a line to the ticker list and enables editing of that line
 */
void TKRTAP::on_AddButton_clicked()
{
    //Add a stock
    int row = model->rowCount();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);

    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

/**
 * @fn TKRTAP::on_DelButton_clicked()
 * @brief Delete a selected stock
 */
void TKRTAP::on_DelButton_clicked()
{
    model->removeRows(ui->listView->currentIndex().row(),1);
}

/**
 * @fn TKRTAP::on_SaveButton_clicked()
 * @brief When the Save Button is clicked the settings are saved
 */
void TKRTAP::on_SaveButton_clicked()
{
    //Save
    QString filename = QFileDialog::getSaveFileName();
    if (filename.isEmpty()){
        //Do nothing
    }
    else{
        filename += ".txt";
        QFile f(filename);
        if (f.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream s2(&f);
            for (int i = 0; i < model->stringList().size(); ++i)
                s2 << model->stringList().at(i) << '\n';
        } else {
            std::cerr << "error opening output file\n";
            //return EXIT_FAILURE;
        }
        // store data in f
        f.close();
    }
}

/**
 * @fn TKRTAP::on_LoadButton_clicked()
 * @brief When the Load Button is clicked an open file dialog opens to let the user choose a file to load
 */
void TKRTAP::on_LoadButton_clicked()
{
    //Load
    QString load_filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                         "",
                                                         tr("Files (*.*)"));
    QFile fIn(load_filename);
    QStringList ticker_list;
    if (fIn.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream sIn(&fIn);
        while (!sIn.atEnd())
            ticker_list += sIn.readLine();
    } else {
        std::cerr << "error opening output file\n";
        //return EXIT_FAILURE;
    }
    if (ticker_list.isEmpty()){
        //Do nothing
    }
    else{
        model->setStringList(ticker_list);
    }
    SetupRequest();
}

/**
 * @fn TKRTAP::on_Save_Button_RSS_clicked()
 * @brief Let the user choose a file name and a destination for the saved RSS list file
 */
void TKRTAP::on_Save_Button_RSS_clicked()
{
    //Save
    QString filename = QFileDialog::getSaveFileName();
    if (filename.isEmpty()){
        //Do nothing
    }
    else{
        filename += ".txt";
        QFile f(filename);
        if (f.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream s2(&f);
            for (int i = 0; i < RSSlinklistmodel->stringList().size(); ++i)
                s2 << RSSlinklistmodel->stringList().at(i) << '\n';
        } else {
            std::cerr << "error opening output file\n";
            //return EXIT_FAILURE;
        }
        // store data in f
        f.close();
    }
}

/**
 * @fn TKRTAP::on_Load_Button_RSS_clicked()
 * @brief When the Load Button is clicked an open file dialog opens to let the user choose an RSS list file to load
 */
void TKRTAP::on_Load_Button_RSS_clicked()
{
    QString load_filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                         "",
                                                         tr("Files (*.*)"));
    QFile fIn(load_filename);
    QStringList RSS_list;
    if (fIn.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream sIn(&fIn);
        while (!sIn.atEnd())
            RSS_list += sIn.readLine();
    } else {
        std::cerr << "error opening output file\n";
        //return EXIT_FAILURE;
    }
    if (RSS_list.isEmpty()){
        //Do nothing
    }
    else{
        RSSlinklistmodel->setStringList(RSS_list);
    }
}

/**
 * @fn TKRTAP::on_AllButton_clicked()
 * @brief Trigger all the link buttons
 */
void TKRTAP::on_AllButton_clicked()

{
    QDesktopServices::openUrl(QUrl(ui->linkEditSEC->text(), QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl(ui->linkEditCharts->text(), QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl(ui->linkEditScreener->text(), QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl(ui->linkEditEcon->text(), QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl(ui->linkEditFinStat->text(), QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl(ui->linkEditAnalysis->text(), QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl(ui->linkEditSpreadsheet->text(), QUrl::TolerantMode));
    LoadMarketMap();
}

//Saving parameters-----------------------------------------------------------------------------------------------
/**
 * @fn TKRTAP::SaveSettings()
 * @brief Saves all the user settings
 */
void TKRTAP::SaveSettings()
{
    //Save
    QSettings settings ("TKRTAP", "TKRTAP");
    settings.beginGroup("MainWindow");
    settings.setValue("position",this->geometry());
    settings.setValue("StockList",model->stringList());
    // write data for ticker list
    QFile fOut("autosave_ticker_list.txt");
    if (fOut.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream s(&fOut);
        for (int i = 0; i < model->stringList().size(); ++i)
            s << model->stringList().at(i) << '\n';
    } else {
        std::cerr << "error opening output file\n";
        //return EXIT_FAILURE;
    }
    fOut.close();

    // write data for RSS links list
    QFile fOut2("autosave_rss_list.txt");
    if (fOut2.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream s2(&fOut2);
        for (int i = 0; i < RSSlinklistmodel->stringList().size(); ++i)
            s2 << RSSlinklistmodel->stringList().at(i) << '\n';
    } else {
        std::cerr << "error opening output file\n";
        //return EXIT_FAILURE;
    }
    fOut2.close();

    //Saving Stock Tab Combo Boxes index
    settings.setValue("ComboBoxDataFeed", ui->DataFeedcomboBox->currentIndex());
    settings.setValue("ComboBoxRefresh", ui->comboBoxRefresh->currentIndex());

    //Saving Text on Buttons
    settings.setValue("ChartButtonTextEdit", ui->ChartsButtonTextEdit->text());
    settings.setValue("ScreenerButtonTextEdit", ui->ScreenerButtonTextEdit->text());
    settings.setValue("EconButtonTextEdit", ui->EconButtonTextEdit->text());
    settings.setValue("FinStatButtonTextEdit", ui->FinStatButtonTextEdit->text());
    settings.setValue("SECButtonTextEdit", ui->SECButtonTextEdit->text());
    settings.setValue("AnalysisButtonTextEdit", ui->AnalysisButtonTextEdit->text());
    settings.setValue("MarketmapButtonTextEdit", ui->MarkmapButtonTextEdit->text());
    settings.setValue("SpreadsheetButtonTextEdit", ui->SpreadsheetButtonTextEdit->text());

    //Saving User Links
    settings.setValue("ChartEditLink", ui->linkEditCharts->text());
    settings.setValue("ScreenerEditLink", ui->linkEditScreener->text());
    settings.setValue("EconEditLink", ui->linkEditEcon->text());
    settings.setValue("FinStatEditLink", ui->linkEditFinStat->text());
    settings.setValue("SECEditLink", ui->linkEditSEC->text());
    settings.setValue("AnalysisEditLink", ui->linkEditAnalysis->text());
    settings.setValue("MarketmapEditLink", ui->linkEditOther->text());
    settings.setValue("SpreadsheetEditLink", ui->linkEditSpreadsheet->text());

    //Saving LED Panel parameters
    settings.setValue("COMPort", ui->comboBoxPorts->currentIndex());
    settings.setValue("TopLineTextColor", ui->comboBoxToplinetext->currentIndex());
    settings.setValue("TopLineBGColor", ui->comboBoxToplinebg->currentIndex());
    settings.setValue("BottomLineTextColor", ui->comboBoxBottomlinetext->currentIndex());
    settings.setValue("BottomLineBGColor", ui->comboBoxBottomlinebg->currentIndex());
    settings.setValue("AuthTokenEdit", ui->lineEditAuthToken->text());
    settings.setValue("ScrollSpeed", ui->comboBoxScrollSpeed->currentIndex());

    //Saving RSS List
    settings.setValue("RSSLinkList", RSSlinklistmodel->stringList());
    settings.setValue("ComboBoxRSSSource", ui->RSScomboBox->currentIndex());
    settings.setValue("RSS_results_spinbox", ui->RSS_results_spinBox->value());
    settings.setValue("Window_Maximized", this->isMaximized());

    settings.endGroup();
}

//Loading parameters----------------------------------------------------------------------------------------
/**
 * @fn TKRTAP::LoadSettings()
 * @brief Loads all the user settings
 */
void TKRTAP::LoadSettings()
{
    //Load;
    QSettings settings ("TKRTAP", "TKRTAP");
    settings.beginGroup("MainWindow");

    //Load stock list model
    // read data for ticker list
    QStringList ticker_list;
    QFile fIn("autosave_ticker_list.txt");
    if (fIn.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream sIn(&fIn);
        while (!sIn.atEnd())
            ticker_list += sIn.readLine();
    } else {
        std::cerr << "error opening output file\n";
        //return EXIT_FAILURE;
    }
    model->setStringList(ticker_list);

    // read data for RSS links list
    QStringList rss_list;
    QFile fIn2("autosave_rss_list.txt");
    if (fIn2.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream sIn2(&fIn2);
        while (!sIn2.atEnd())
            rss_list += sIn2.readLine();
    } else {
        std::cerr << "error opening output file\n";
        //return EXIT_FAILURE;
    }
    RSSlinklistmodel->setStringList(rss_list);

    int indexDataFeedComboBox = settings.value("ComboBoxDataFeed", 1).toInt();
    ui->DataFeedcomboBox->setCurrentIndex(indexDataFeedComboBox);
    int indexRefreshComboBox = settings.value("ComboBoxRefresh", 1).toInt();
    if (settings.value("ComboBoxRefresh", 1).toString() == ""){
        ui->comboBoxRefresh->setCurrentIndex(1);//An if to trigger the timer even if its the first time the user uses the software.
    }
    else{
        ui->comboBoxRefresh->setCurrentIndex(indexRefreshComboBox);
    }

    //Load RSS link list model
    //QStringList SavedRSSList = settings.value("RSSLinkList").toStringList();
    //RSSlinklistmodel->setStringList(SavedRSSList);
    Removing_Duplicates_RSS();
    int indexRSSSourceComboBox = settings.value("ComboBoxRSSSource", 1).toInt();
    ui->RSScomboBox->setCurrentIndex(indexRSSSourceComboBox);

    //Load position of the main window
    bool window_maximized = settings.value("Window_Maximized").toBool();
    if (window_maximized == true){
        this->showMaximized();
    }
    else{
        QRect MaindefaultRect(8,30,491,305);
        QRect Mainrect = settings.value("position",MaindefaultRect).toRect();
        setGeometry(Mainrect);
    }

    //Load User Saved Button Names
    QString SavedChartButtonTextEdit = settings.value("ChartButtonTextEdit","Charts").toString();
    ui->ChartsButtonTextEdit->setText(SavedChartButtonTextEdit);
    QString SavedScreenerButtonTextEdit = settings.value("ScreenerButtonTextEdit","Screener").toString();
    ui->ScreenerButtonTextEdit->setText(SavedScreenerButtonTextEdit);
    QString SavedEconButtonTextEdit = settings.value("EconButtonTextEdit","Economic Indicators").toString();
    ui->EconButtonTextEdit->setText(SavedEconButtonTextEdit);
    QString SavedFinStatButtonTextEdit = settings.value("FinStatButtonTextEdit","Financial Statements").toString();
    ui->FinStatButtonTextEdit->setText(SavedFinStatButtonTextEdit);
    QString SavedSECButtonTextEdit = settings.value("SECButtonTextEdit","SEC").toString();
    ui->SECButtonTextEdit->setText(SavedSECButtonTextEdit);
    QString SavedAnalysisButtonTextEdit = settings.value("AnalysisButtonTextEdit","Analysis").toString();
    ui->AnalysisButtonTextEdit->setText(SavedAnalysisButtonTextEdit);
    QString SavedMarketmapButtonTextEdit = settings.value("MarketmapButtonTextEdit","Market Map").toString();
    ui->MarkmapButtonTextEdit->setText(SavedMarketmapButtonTextEdit);
    QString SavedSpreadsheetButtonTextEdit = settings.value("SpreadsheetButtonTextEdit","Spreadsheet").toString();
    ui->SpreadsheetButtonTextEdit->setText(SavedSpreadsheetButtonTextEdit);

    //Load User Links
    QString SavedChartLinkTextEdit = settings.value("ChartEditLink","http://www.freestockcharts.com/").toString();
    ui->linkEditCharts->setText(SavedChartLinkTextEdit);
    QString SavedScreenerLinkTextEdit = settings.value("ScreenerEditLink","http://www.finviz.com/screener.ashx").toString();
    ui->linkEditScreener->setText(SavedScreenerLinkTextEdit);
    QString SavedEconLinkTextEdit = settings.value("EconEditLink","http://www.tradingeconomics.com/").toString();
    ui->linkEditEcon->setText(SavedEconLinkTextEdit);
    QString SavedFinStatLinkTextEdit = settings.value("FinStatEditLink","http://www.morningstar.ca/").toString();
    ui->linkEditFinStat->setText(SavedFinStatLinkTextEdit);
    QString SavedSECLinkTextEdit = settings.value("SECEditLink","http://www.seclive.com/").toString();
    ui->linkEditSEC->setText(SavedSECLinkTextEdit);
    QString SavedAnalysisLinkTextEdit = settings.value("AnalysisEditLink","http://seekingalpha.com/").toString();
    ui->linkEditAnalysis->setText(SavedAnalysisLinkTextEdit);
    QString SavedMarketmapLinkTextEdit = settings.value("MarketmapEditLink","http://www.finviz.com/map.ashx?t=sec").toString();
    ui->linkEditOther->setText(SavedMarketmapLinkTextEdit);
    QString SavedSpreadsheetLinkTextEdit = settings.value("SpreadsheetEditLink","https://docs.google.com/spreadsheets/d/1OUmzVaOjg4L-9qLeJC5ETxUjSqxdhu07DzekbiyhAgo/edit?usp=sharing").toString();
    ui->linkEditSpreadsheet->setText(SavedSpreadsheetLinkTextEdit);

    //Load LED Panel Settings

    int indexCOMPort = settings.value("COMPort", 1).toInt();
    ui->comboBoxPorts->setCurrentIndex(indexCOMPort);
    int indexTopLineText = settings.value("TopLineTextColor", 3).toInt();
    ui->comboBoxToplinetext->setCurrentIndex(indexTopLineText);
    int indexTopLineBG = settings.value("TopLineBGColor", 0).toInt();
    ui->comboBoxToplinebg->setCurrentIndex(indexTopLineBG);
    int indexBottomLineText = settings.value("BottomLineTextColor", 3).toInt();
    ui->comboBoxBottomlinetext->setCurrentIndex(indexBottomLineText);
    int indexBottomLineBG = settings.value("BottomLineBGColor", 0).toInt();
    ui->comboBoxBottomlinebg->setCurrentIndex(indexBottomLineBG);
    QString SavedAuthToken = settings.value("AuthTokenEdit").toString();
    ui->lineEditAuthToken->setText(SavedAuthToken);
    int SavedScrollSpeed = settings.value("ScrollSpeed", 1).toInt();
    ui->comboBoxScrollSpeed->setCurrentIndex(SavedScrollSpeed);

    int RSS_results_number = settings.value("RSS_results_spinbox").toInt();
    ui->RSS_results_spinBox->setValue(RSS_results_number);

    settings.endGroup();
}

//RSS TAB------------------------------------------------------------------------------------------------

/**
 * @fn TKRTAP::on_button_add_link_clicked()
 * @brief Add a RSS link to the list
 */
void TKRTAP::on_button_add_link_clicked()
{
    int row2 = RSSlinklistmodel->rowCount();
    RSSlinklistmodel->insertRows(row2, 1);

    QModelIndex index2 = RSSlinklistmodel->index(row2);

    ui->RSSlistView->setCurrentIndex(index2);
    ui->RSSlistView->edit(index2);
}

/**
 * @fn TKRTAP::on_button_remove_link_clicked()
 * @brief Delete a RSS link from the list
 */
void TKRTAP::on_button_remove_link_clicked()
{
    RSSlinklistmodel->removeRows(ui->RSSlistView->currentIndex().row(),1);
}

/**
 * @fn TKRTAP::on_AddStockRSSButton_clicked()
 * @brief When the button is clicked an RSS link is created for each stock ticker in the stock ticker list by calling GenerateStockRSS
 */
void TKRTAP::on_AddStockRSSButton_clicked()
{
    QStringList RSSURLList = GenerateStockRSS();
    foreach (const QString &url, RSSURLList)
    {
        int row = RSSlinklistmodel->rowCount();
        RSSlinklistmodel->insertRows(row, 1);
        QModelIndex index = RSSlinklistmodel->index(row);

        RSSlinklistmodel->setData(index,url);
    }
    Removing_Duplicates_RSS();
}

/**
 * @fn TKRTAP::on_button_clear_RSS_links_clicked()
 * @brief Deletes completely in the RSS url list
 */
void TKRTAP::on_button_clear_RSS_links_clicked()
{
    int count = RSSlinklistmodel->rowCount();
    RSSlinklistmodel->removeRows(0,count);
}

/**
 * @fn TKRTAP::Removing_Duplicates_RSS()
 * @brief Removes the duplicates in the RSS url lists
 */
void TKRTAP::Removing_Duplicates_RSS()
{
    //Removing duplicates of the RSS link list
    QStringList with_duplicatelist(RSSlinklistmodel->stringList());
    QSet<QString> without_duplicateset = with_duplicatelist.toSet();
    QStringList without_duplicatelist;
    without_duplicatelist = without_duplicateset.toList();
    RSSlinklistmodel->setStringList(without_duplicatelist);
    ui->RSSlistView->setModel(RSSlinklistmodel);
}

//LED Panel TAB--------------------------------------------------------------------------------------------
/**
 * @fn TKRTAP::on_AuthTokenpushButton_clicked()
 * @brief Opens the url to the page for getting a quandl auth token
 */
void TKRTAP::on_AuthTokenpushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.quandl.com/users/sign_in", QUrl::TolerantMode));
}

/**
 * @fn TKRTAP::setCouleurs()
 * @brief Sets the color chosen to the text outputing to the LED panel
 */
void TKRTAP::setCouleurs()
{
    int couleurs[4];
    couleurs[0] = ui->comboBoxToplinetext->currentIndex();
    couleurs[1] = ui->comboBoxBottomlinetext->currentIndex();
    couleurs[2] = ui->comboBoxToplinebg->currentIndex();
    couleurs[3] = ui->comboBoxBottomlinebg->currentIndex();
    _matrice->setDefaultColors(couleurs);
}

/**
 * @fn TKRTAP::setLigne1()
 * @brief Sends a line of text to the first line of the LED panel to display
 */
void TKRTAP::setLigne1()
{
    _matrice->setText(ui->Line1->text(),LINE1);
    _matrice->sendLine(LINE1);
}

/**
 * @fn TKRTAP::setLigne2()
 * @brief Sends a line of text to the second line of the LED panel to display
 */
void TKRTAP::setLigne2()
{
    _matrice->setText(ui->Line2->text(),LINE2);
    _matrice->setStringColor(QString(ui->Line2->text().count(),(ui->comboBoxBottomlinetext->currentIndex()<<4)+ui->comboBoxBottomlinebg->currentIndex()),LINE2);
    _matrice->sendLine(LINE2);
}

void TKRTAP::setScrollSpeed(){
    unsigned char speed[3] = {15,25,50};
    _matrice->sendSpeed(speed[ui->comboBoxScrollSpeed->currentIndex()]);
}
/**
 * @fn TKRTAP::toggleSerialPort()
 * @brief Activates the necessary functions to start outputing data to the LED panel
 */
void TKRTAP::toggleSerialPort()
{
    _matrice->setPortName(ui->comboBoxPorts->currentText());
    if(_matrice->toggleSerialPort())
    {
        ui->bout_connexion->setText("DISCONNECT");
        setScrollSpeed();
        setLigne1();
        setLigne2();
        setCouleurs();
        SetupRequest();
    }
    else
    {
        ui->bout_connexion->setText("CONNECT");
    }
}

/**
 * @fn TKRTAP::GenerateStockRSS()
 * @brief Activates the necessary functions to start outputing data to the LED panel
 * @return The full list RSS url for each stock
 */
QStringList TKRTAP::GenerateStockRSS()
{
    QStringList RSSURLList;
    QStringList RSSStockStringList(model->stringList());
    RSSURLList.clear();
    QString CurrentDataFeed(ui->RSScomboBox->currentText());
    foreach (const QString &str, RSSStockStringList)
    {
        QString RSSURL;
        if (CurrentDataFeed == "Financial Content")
        {
            RSSURL = "http://markets.financialcontent.com/stocks/action/rssfeed?Symbol=" + str;
        }

        else
        {
            RSSURL = "http://finance.yahoo.com/rss/headline?s=" + str;
        }
        RSSURLList.append(RSSURL);
    }
    return RSSURLList;
}


/**
 * @fn TKRTAP::SetupRequest()
 * @brief Setups the request with the created API url to get the needed data
 */
void TKRTAP::SetupRequest()
{
    model->sort(0, Qt::AscendingOrder);
    _JSON_query->setAuthCodeQuandl(ui->lineEditAuthToken->text());
    _JSON_query->setServiceName(ui->DataFeedcomboBox->currentText());
    _JSON_query->setTickerNames(model->stringList());
    _JSON_query->sendRequest();
    qDebug() <<"Updating Stock quotes";
}

/**
 * @brief Passes the formatted String List from to JSON requests to the different parts of the UI
 * @param txt_list The received StringList
 * @param colour_text The colour code for the string that will be sent to the RGB matrix
 */
void TKRTAP::JSONParseComplete(QStringList txt_list,QString colour_text){
    ui->PricesListWidget->clear();
    QString formatted_text;
    for(int i=0;i<txt_list.count();i++){
        QString current_stock = txt_list.at(i);
        ui->PricesListWidget->addItem(current_stock);
        if(current_stock.contains(QString::fromUtf8("\u25B2"))){
            ui->PricesListWidget->item(i)->setForeground(Qt::green);
        }
        else if(current_stock.contains(QString::fromUtf8("\u25BC"))){
            ui->PricesListWidget->item(i)->setForeground(Qt::red);
        }
        else{
            ui->PricesListWidget->item(i)->setForeground(Qt::yellow);
        }
        QString modded_string = txt_list.at(i);
        if(ui->DataFeedcomboBox->currentText()=="Yahoo"){
            int index = modded_string.lastIndexOf(char(32),-2);
            modded_string.chop(modded_string.count()-index-1); //removing the data time for the LED panel output
        }
        formatted_text += modded_string;
    }
    ui->Line1->setText(formatted_text);
    _matrice->setStringColor(colour_text,LINE1);
}


/**
 * @fn TKRTAP::timerStart()
 * @brief Timer function to start refreshing the stock prices
 */
void TKRTAP::timerStart()
{
    if (ui->DataFeedcomboBox->currentText() == "Off"){
        //Doesn't start the timer if Data feed is off
    }
    else{
        int NumberOfStocks = model->stringList().count();
        int Time = NumberOfStocks*12000;
        if (ui->comboBoxScrollSpeed->currentText() == "Fast"){
            Time = NumberOfStocks*3000;
        }
        else if (ui->comboBoxScrollSpeed->currentText() == "Medium"){
            Time = NumberOfStocks*6000;
        }
        QString CurrentDataFeed(ui->DataFeedcomboBox->currentText());
        if (CurrentDataFeed == "Yahoo")
        {
            if (ui->comboBoxRefresh->currentText() == "10s"){
                Ticker_Timer->start(10000);//10 000 = 10 seconds
                qDebug() <<"Timer as started - 10 seconds";
            }
            else if (ui->comboBoxRefresh->currentText() == "30s"){
                Ticker_Timer->start(30000);//30 000 = 30 seconds
                qDebug() <<"Timer as started - 30 seconds";
            }
            else if (ui->comboBoxRefresh->currentText() == "1m"){
                Ticker_Timer->start(60000);//60 000 = 60 seconds
                qDebug() <<"Timer as started - 60 seconds";
            }
            else if (ui->comboBoxRefresh->currentText() == "2m"){
                Ticker_Timer->start(120000);//120 000 = 120 seconds
                qDebug() <<"Timer as started - 120 seconds";
            }
            else if (ui->comboBoxRefresh->currentText() == "5m"){
                Ticker_Timer->start(300000);//300 000 = 5 minutes
                qDebug() <<"Timer as started -  minutes5";
            }
            else if (ui->comboBoxRefresh->currentText() == "15m"){
                Ticker_Timer->start(900000);//900000 = 15 minutes
                qDebug() <<"Timer as started - 15 minutes";
            }
            else if (ui->comboBoxRefresh->currentText() == "30m"){
                Ticker_Timer->start(1800000);//1 800 000 = 30 minutes
                qDebug() <<"Timer as started - 30 minutes";
            }
            else if (ui->comboBoxRefresh->currentText() == "1h"){
                Ticker_Timer->start(3600000);//3 600 000 = 1 hour
                qDebug() <<"Timer as started - 1 hour";
            }
            else if (ui->comboBoxRefresh->currentText() == "2h"){
                Ticker_Timer->start(7200000);//7 200 000 = 2 hours
                qDebug() <<"Timer as started - 2 hours";
            }
            else{
                Ticker_Timer->start(Time);//Automatic for the LED Panel
                qDebug() <<"Timer as started - Auto " <<Time;
            }
        }
        else
        {
            Ticker_Timer->start(432000000);//432000000 = once a day
        }
        SetupRequest();
        connect(ui->bout_connexion,SIGNAL(clicked()),this,SLOT(timerEnd()));
    }
}

/**
 * @fn TKRTAP::timerEnd()
 * @brief Timer functions to stop refreshing the stock prices
 */
void TKRTAP::timerEnd()
{
    Ticker_Timer->stop();
    connect(ui->bout_connexion,SIGNAL(clicked()),this,SLOT(timerStart()));
}



//RSS functions
/**
 * @brief Starts the RSS loading process
 */
void TKRTAP::startRSS(){
    ui->button_loadRSS->setEnabled(false);
    RSSlinklistmodel->sort(0, Qt::AscendingOrder);
    _rss_client->loadRSS(RSSlinklistmodel->stringList());
    _rss_client->fetch();
}

/**
 * @brief Receives the RSS results and displays the X most recent (default 5) in the RSS browser and
 * creates a string to be displayed on the physical LED matrix.
 * @param str_list List of all the sorted RSS results by date
 * @param link_rss List of all the links sorted by date
 * @param time_rss List of the rss published times
 */
void TKRTAP::updateTable(QStringList str_list, QStringList link_rss, QStringList time_rss){
    QString result;
    int rss_output_number;
    rss_output_number = ui->RSS_results_spinBox->value();
    ui->RSSBrowser->clear();
    _rss_link.clear();
    _rss_title.clear();
    _rss_time.clear();
    int i = 0;
    while(true){
        if(!_rss_title.contains(str_list.at(i))){
            if (str_list.at(i) == "Yahoo! Finance: RSS feed not found"){
                //Do nothing
            }
            else{
                result += str_list.at(i)+" / ";
                ui->RSSBrowser->addItem(time_rss.at(i)+char(32)+str_list.at(i));
                _rss_title.append(str_list.at(i));
                _rss_link.append(link_rss.at(i));
                _rss_time.append(time_rss.at(i));
            }
        }
        if(_rss_title.count() >= rss_output_number){
            break;
        }
        i++;
    }
    ui->button_loadRSS->setEnabled(true);
    ui->Line2->setText(result);
    setLigne2();
}

/**
 * @brief Opens the link of the RSS in the default browser of the user
 * @param item Selected item from the displayed RSS browser
 */
void TKRTAP::openRSSLink(QListWidgetItem* item){
    QDesktopServices::openUrl(QUrl( _rss_link.at(_rss_title.indexOf(item->text().mid(6))), QUrl::TolerantMode));
}

void TKRTAP::openStockChart(QString ticker){
    //Show Fin viz stock chart
    QString selectedStock(ticker);
    QString selectedStockLink;
    selectedStockLink = "http://www.finviz.com/chart.ashx?t=" + selectedStock + "&ty=c&ta=1&p=d&s=l";
    mDialog2 = new QuickStockChart(this,QUrl(selectedStockLink));
    mDialog2->show();

    //QDesktopServices::openUrl(QUrl(selectedStockLink, QUrl::TolerantMode));
}

/**
 * @fn TKRTAP::validate_tickers()
 * @brief Checks if the user input is valid then delete the input if it is not valid
 */
void TKRTAP::validate_tickers(){
    QString tested_character;
    QStringList tested_characters;
    tested_characters << "#"
                      << "2"
                      << "3"
                      << "4"
                      << "5"
                      << "6"
                      << "7"
                      << "8"
                      << "9"
                      << "0"
                      << "^"
                      << "¸"
                      << "<"
                      << ";"
                      << "`"
                      << ","
                      << "é"
                      << "|"
                      << "!"
                      << "%"
                      << "$"
                      << "%"
                      << "?"
                      << "&"
                      << "*"
                      << "("
                      << ")"
                      << "_"
                      << "+"
                      << "¨"
                      << ">"
                      << ":"
                      << "`"
                      << "'"
                      << "É"
                      << "±"
                      << "@"
                      << "£"
                      << "¢"
                      << "¤"
                      << "¬"
                      << "¦"
                      << "²"
                      << "³"
                      << "¼"
                      << "½"
                      << "¾"
                      << "["
                      << "]"
                      << "}"
                      << "{"
                      << "~"
                      << "¯"
                      << " "
                      << "{"
                      << "´";
    for (int i1 = 0; i1 < tested_characters.size(); ++i1){
        tested_character = tested_characters.at(i1);
        for (int i = 0; i < model->stringList().size(); ++i){
            bool Continue = true;
            if (model->stringList().at(i).contains(tested_character)){
                model->removeRow(i);
                Continue = false;
                qDebug () <<tested_character;
            }
            if (Continue == true){
                if (model->stringList().at(i).isEmpty()){
                    model->removeRow(i);
                }
            }
        }
    }
}

/**
 * @fn TKRTAP::on_listView_doubleClicked(const QModelIndex &index)
 * @brief When a ticker in the stock list is double clicked the quick stock chart dialog opens
 */
void TKRTAP::on_listView_doubleClicked(const QModelIndex &index)
{
    QString ticker;
    ticker = index.data().toString();
    openStockChart(ticker);
}
