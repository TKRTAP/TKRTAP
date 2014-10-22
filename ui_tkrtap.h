/********************************************************************************
** Form generated from reading UI file 'tkrtap.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TKRTAP_H
#define UI_TKRTAP_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TKRTAP
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QFrame *Logoframe;
    QLabel *label_8;
    QFrame *LogoNButtonsFrame;
    QPushButton *Spreadsheet;
    QPushButton *Other;
    QPushButton *Analysis;
    QPushButton *SEC;
    QPushButton *FinStat;
    QPushButton *Econ;
    QPushButton *Screener;
    QPushButton *Charts;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bout_connexion;
    QPushButton *AllButton;
    QTabWidget *Tabs;
    QWidget *tab_Stocks;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QListView *listView;
    QListWidget *PricesListWidget;
    QVBoxLayout *verticalLayout_4;
    QPushButton *AddButton;
    QPushButton *DelButton;
    QPushButton *SaveButton;
    QPushButton *LoadButton;
    QGroupBox *DataFeedgroupBox;
    QComboBox *DataFeedcomboBox;
    QGroupBox *groupBox;
    QComboBox *comboBoxRefresh;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_RSS;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *AddStockRSSButton;
    QListView *RSSlistView;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_add_link;
    QPushButton *button_remove_link;
    QPushButton *button_clear_RSS_links;
    QPushButton *Save_Button_RSS;
    QPushButton *Load_Button_RSS;
    QComboBox *RSScomboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpinBox *RSS_results_spinBox;
    QPushButton *button_loadRSS;
    QSpacerItem *verticalSpacer;
    QWidget *tab_Links;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLineEdit *ChartsButtonTextEdit;
    QLineEdit *linkEditCharts;
    QLineEdit *ScreenerButtonTextEdit;
    QLineEdit *linkEditScreener;
    QLineEdit *EconButtonTextEdit;
    QLineEdit *linkEditEcon;
    QLineEdit *FinStatButtonTextEdit;
    QLineEdit *linkEditFinStat;
    QLineEdit *SECButtonTextEdit;
    QLineEdit *linkEditSEC;
    QLineEdit *AnalysisButtonTextEdit;
    QLineEdit *linkEditAnalysis;
    QLineEdit *MarkmapButtonTextEdit;
    QLineEdit *linkEditOther;
    QLineEdit *SpreadsheetButtonTextEdit;
    QLineEdit *linkEditSpreadsheet;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QLabel *Portslabel;
    QComboBox *comboBoxPorts;
    QLabel *Toplinetextlabel;
    QLabel *ToplinebgLabel;
    QLabel *BottomlinetextLabel;
    QLabel *BottomlinebgLabel;
    QLabel *TopLineLabel;
    QLabel *BottomLineLabel;
    QLabel *AuthTokenLabel;
    QPushButton *AuthTokenpushButton;
    QTextEdit *textEdit;
    QLabel *label_3;
    QComboBox *comboBoxScrollSpeed;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *Line1;
    QLineEdit *Line2;
    QLineEdit *lineEditAuthToken;
    QComboBox *comboBoxToplinetext;
    QComboBox *comboBoxToplinebg;
    QComboBox *comboBoxBottomlinetext;
    QComboBox *comboBoxBottomlinebg;
    QSpacerItem *verticalSpacer_5;
    QListWidget *RSSBrowser;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *TKRTAP)
    {
        if (TKRTAP->objectName().isEmpty())
            TKRTAP->setObjectName(QStringLiteral("TKRTAP"));
        TKRTAP->resize(677, 450);
        TKRTAP->setMinimumSize(QSize(677, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/img/tkrtapico.png"), QSize(), QIcon::Normal, QIcon::Off);
        TKRTAP->setWindowIcon(icon);
        TKRTAP->setWindowOpacity(1);
        TKRTAP->setAutoFillBackground(false);
        TKRTAP->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 8pt \"Arial Black\";"));
        TKRTAP->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        TKRTAP->setTabShape(QTabWidget::Rounded);
        actionExit = new QAction(TKRTAP);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(TKRTAP);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        Logoframe = new QFrame(centralWidget);
        Logoframe->setObjectName(QStringLiteral("Logoframe"));
        Logoframe->setMinimumSize(QSize(131, 31));
        Logoframe->setFrameShape(QFrame::StyledPanel);
        Logoframe->setFrameShadow(QFrame::Raised);
        label_8 = new QLabel(Logoframe);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(true);
        label_8->setGeometry(QRect(0, 0, 121, 31));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/Logos/img/logo2.png")));
        label_8->setScaledContents(true);

        verticalLayout_9->addWidget(Logoframe);

        LogoNButtonsFrame = new QFrame(centralWidget);
        LogoNButtonsFrame->setObjectName(QStringLiteral("LogoNButtonsFrame"));
        LogoNButtonsFrame->setMinimumSize(QSize(131, 251));
        LogoNButtonsFrame->setFrameShape(QFrame::StyledPanel);
        LogoNButtonsFrame->setFrameShadow(QFrame::Raised);
        Spreadsheet = new QPushButton(LogoNButtonsFrame);
        Spreadsheet->setObjectName(QStringLiteral("Spreadsheet"));
        Spreadsheet->setGeometry(QRect(0, 220, 131, 31));
        Other = new QPushButton(LogoNButtonsFrame);
        Other->setObjectName(QStringLiteral("Other"));
        Other->setGeometry(QRect(0, 190, 131, 31));
        Analysis = new QPushButton(LogoNButtonsFrame);
        Analysis->setObjectName(QStringLiteral("Analysis"));
        Analysis->setGeometry(QRect(0, 160, 131, 31));
        SEC = new QPushButton(LogoNButtonsFrame);
        SEC->setObjectName(QStringLiteral("SEC"));
        SEC->setGeometry(QRect(0, 130, 131, 31));
        FinStat = new QPushButton(LogoNButtonsFrame);
        FinStat->setObjectName(QStringLiteral("FinStat"));
        FinStat->setGeometry(QRect(0, 100, 131, 31));
        Econ = new QPushButton(LogoNButtonsFrame);
        Econ->setObjectName(QStringLiteral("Econ"));
        Econ->setGeometry(QRect(0, 70, 131, 31));
        Screener = new QPushButton(LogoNButtonsFrame);
        Screener->setObjectName(QStringLiteral("Screener"));
        Screener->setGeometry(QRect(0, 40, 131, 31));
        Charts = new QPushButton(LogoNButtonsFrame);
        Charts->setObjectName(QStringLiteral("Charts"));
        Charts->setGeometry(QRect(0, 10, 131, 31));
        Charts->raise();
        Screener->raise();
        Econ->raise();
        FinStat->raise();
        SEC->raise();
        Analysis->raise();
        Other->raise();
        Spreadsheet->raise();

        verticalLayout_9->addWidget(LogoNButtonsFrame);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_4);


        horizontalLayout_5->addLayout(verticalLayout_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        bout_connexion = new QPushButton(centralWidget);
        bout_connexion->setObjectName(QStringLiteral("bout_connexion"));
        bout_connexion->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(bout_connexion);

        AllButton = new QPushButton(centralWidget);
        AllButton->setObjectName(QStringLiteral("AllButton"));
        AllButton->setFlat(false);

        horizontalLayout_4->addWidget(AllButton);


        verticalLayout_8->addLayout(horizontalLayout_4);

        Tabs = new QTabWidget(centralWidget);
        Tabs->setObjectName(QStringLiteral("Tabs"));
        Tabs->setMinimumSize(QSize(410, 261));
        Tabs->setStyleSheet(QStringLiteral("selection-background-color: rgb(0, 0, 0);"));
        Tabs->setTabShape(QTabWidget::Triangular);
        tab_Stocks = new QWidget();
        tab_Stocks->setObjectName(QStringLiteral("tab_Stocks"));
        gridLayout_5 = new QGridLayout(tab_Stocks);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        listView = new QListView(tab_Stocks);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMinimumSize(QSize(95, 0));
        listView->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(listView);

        PricesListWidget = new QListWidget(tab_Stocks);
        PricesListWidget->setObjectName(QStringLiteral("PricesListWidget"));
        PricesListWidget->setMinimumSize(QSize(285, 0));
        PricesListWidget->setFrameShape(QFrame::WinPanel);
        PricesListWidget->setAlternatingRowColors(false);
        PricesListWidget->setSelectionMode(QAbstractItemView::NoSelection);

        horizontalLayout_3->addWidget(PricesListWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        AddButton = new QPushButton(tab_Stocks);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(10);
        AddButton->setFont(font);
        AddButton->setLayoutDirection(Qt::LeftToRight);
        AddButton->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/img/add.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon1);
        AddButton->setIconSize(QSize(10, 10));
        AddButton->setFlat(true);

        verticalLayout_4->addWidget(AddButton);

        DelButton = new QPushButton(tab_Stocks);
        DelButton->setObjectName(QStringLiteral("DelButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/img/delete.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DelButton->setIcon(icon2);
        DelButton->setIconSize(QSize(10, 10));
        DelButton->setFlat(true);

        verticalLayout_4->addWidget(DelButton);

        SaveButton = new QPushButton(tab_Stocks);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/img/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SaveButton->setIcon(icon3);
        SaveButton->setIconSize(QSize(10, 10));
        SaveButton->setFlat(true);

        verticalLayout_4->addWidget(SaveButton);

        LoadButton = new QPushButton(tab_Stocks);
        LoadButton->setObjectName(QStringLiteral("LoadButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/img/load.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LoadButton->setIcon(icon4);
        LoadButton->setIconSize(QSize(10, 10));
        LoadButton->setFlat(true);

        verticalLayout_4->addWidget(LoadButton);

        DataFeedgroupBox = new QGroupBox(tab_Stocks);
        DataFeedgroupBox->setObjectName(QStringLiteral("DataFeedgroupBox"));
        DataFeedgroupBox->setMinimumSize(QSize(105, 45));
        DataFeedgroupBox->setMaximumSize(QSize(105, 45));
        DataFeedcomboBox = new QComboBox(DataFeedgroupBox);
        DataFeedcomboBox->setObjectName(QStringLiteral("DataFeedcomboBox"));
        DataFeedcomboBox->setGeometry(QRect(10, 20, 81, 21));

        verticalLayout_4->addWidget(DataFeedgroupBox);

        groupBox = new QGroupBox(tab_Stocks);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 45));
        comboBoxRefresh = new QComboBox(groupBox);
        comboBoxRefresh->setObjectName(QStringLiteral("comboBoxRefresh"));
        comboBoxRefresh->setGeometry(QRect(10, 20, 81, 21));

        verticalLayout_4->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_4);


        gridLayout_5->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        Tabs->addTab(tab_Stocks, QString());
        tab_RSS = new QWidget();
        tab_RSS->setObjectName(QStringLiteral("tab_RSS"));
        gridLayout_4 = new QGridLayout(tab_RSS);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        AddStockRSSButton = new QPushButton(tab_RSS);
        AddStockRSSButton->setObjectName(QStringLiteral("AddStockRSSButton"));
        AddStockRSSButton->setStyleSheet(QStringLiteral("font: 87 7pt \"Arial Black\";"));

        verticalLayout_3->addWidget(AddStockRSSButton);

        RSSlistView = new QListView(tab_RSS);
        RSSlistView->setObjectName(QStringLiteral("RSSlistView"));
        RSSlistView->setStyleSheet(QStringLiteral("font: 87 7pt \"Arial\";"));

        verticalLayout_3->addWidget(RSSlistView);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        button_add_link = new QPushButton(tab_RSS);
        button_add_link->setObjectName(QStringLiteral("button_add_link"));
        button_add_link->setFont(font);
        button_add_link->setLayoutDirection(Qt::LeftToRight);
        button_add_link->setAutoFillBackground(false);
        button_add_link->setIcon(icon1);
        button_add_link->setIconSize(QSize(10, 10));
        button_add_link->setFlat(true);

        verticalLayout_2->addWidget(button_add_link);

        button_remove_link = new QPushButton(tab_RSS);
        button_remove_link->setObjectName(QStringLiteral("button_remove_link"));
        button_remove_link->setIcon(icon2);
        button_remove_link->setIconSize(QSize(10, 10));
        button_remove_link->setFlat(true);

        verticalLayout_2->addWidget(button_remove_link);

        button_clear_RSS_links = new QPushButton(tab_RSS);
        button_clear_RSS_links->setObjectName(QStringLiteral("button_clear_RSS_links"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/img/clear2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        button_clear_RSS_links->setIcon(icon5);
        button_clear_RSS_links->setIconSize(QSize(10, 10));
        button_clear_RSS_links->setFlat(true);

        verticalLayout_2->addWidget(button_clear_RSS_links);

        Save_Button_RSS = new QPushButton(tab_RSS);
        Save_Button_RSS->setObjectName(QStringLiteral("Save_Button_RSS"));
        Save_Button_RSS->setIcon(icon3);
        Save_Button_RSS->setIconSize(QSize(10, 10));
        Save_Button_RSS->setFlat(true);

        verticalLayout_2->addWidget(Save_Button_RSS);

        Load_Button_RSS = new QPushButton(tab_RSS);
        Load_Button_RSS->setObjectName(QStringLiteral("Load_Button_RSS"));
        Load_Button_RSS->setIcon(icon4);
        Load_Button_RSS->setIconSize(QSize(10, 10));
        Load_Button_RSS->setFlat(true);

        verticalLayout_2->addWidget(Load_Button_RSS);

        RSScomboBox = new QComboBox(tab_RSS);
        RSScomboBox->setObjectName(QStringLiteral("RSScomboBox"));

        verticalLayout_2->addWidget(RSScomboBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(tab_RSS);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);

        RSS_results_spinBox = new QSpinBox(tab_RSS);
        RSS_results_spinBox->setObjectName(QStringLiteral("RSS_results_spinBox"));
        RSS_results_spinBox->setMinimum(1);
        RSS_results_spinBox->setValue(5);

        horizontalLayout_6->addWidget(RSS_results_spinBox);


        verticalLayout_2->addLayout(horizontalLayout_6);

        button_loadRSS = new QPushButton(tab_RSS);
        button_loadRSS->setObjectName(QStringLiteral("button_loadRSS"));
        button_loadRSS->setEnabled(true);

        verticalLayout_2->addWidget(button_loadRSS);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout_4->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        Tabs->addTab(tab_RSS, QString());
        tab_Links = new QWidget();
        tab_Links->setObjectName(QStringLiteral("tab_Links"));
        gridLayout_2 = new QGridLayout(tab_Links);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 3, -1);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        ChartsButtonTextEdit = new QLineEdit(tab_Links);
        ChartsButtonTextEdit->setObjectName(QStringLiteral("ChartsButtonTextEdit"));
        ChartsButtonTextEdit->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        ChartsButtonTextEdit->setFrame(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, ChartsButtonTextEdit);

        linkEditCharts = new QLineEdit(tab_Links);
        linkEditCharts->setObjectName(QStringLiteral("linkEditCharts"));
        linkEditCharts->setMaximumSize(QSize(700, 16777215));
        linkEditCharts->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        linkEditCharts->setFrame(true);
        linkEditCharts->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(0, QFormLayout::FieldRole, linkEditCharts);

        ScreenerButtonTextEdit = new QLineEdit(tab_Links);
        ScreenerButtonTextEdit->setObjectName(QStringLiteral("ScreenerButtonTextEdit"));
        ScreenerButtonTextEdit->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        ScreenerButtonTextEdit->setFrame(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, ScreenerButtonTextEdit);

        linkEditScreener = new QLineEdit(tab_Links);
        linkEditScreener->setObjectName(QStringLiteral("linkEditScreener"));
        linkEditScreener->setMaximumSize(QSize(700, 16777215));
        linkEditScreener->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));

        formLayout->setWidget(1, QFormLayout::FieldRole, linkEditScreener);

        EconButtonTextEdit = new QLineEdit(tab_Links);
        EconButtonTextEdit->setObjectName(QStringLiteral("EconButtonTextEdit"));
        EconButtonTextEdit->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        EconButtonTextEdit->setFrame(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, EconButtonTextEdit);

        linkEditEcon = new QLineEdit(tab_Links);
        linkEditEcon->setObjectName(QStringLiteral("linkEditEcon"));
        linkEditEcon->setMaximumSize(QSize(700, 16777215));
        linkEditEcon->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));

        formLayout->setWidget(2, QFormLayout::FieldRole, linkEditEcon);

        FinStatButtonTextEdit = new QLineEdit(tab_Links);
        FinStatButtonTextEdit->setObjectName(QStringLiteral("FinStatButtonTextEdit"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(7);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(10);
        FinStatButtonTextEdit->setFont(font1);
        FinStatButtonTextEdit->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        FinStatButtonTextEdit->setFrame(false);

        formLayout->setWidget(3, QFormLayout::LabelRole, FinStatButtonTextEdit);

        linkEditFinStat = new QLineEdit(tab_Links);
        linkEditFinStat->setObjectName(QStringLiteral("linkEditFinStat"));
        linkEditFinStat->setMaximumSize(QSize(700, 16777215));
        linkEditFinStat->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));

        formLayout->setWidget(3, QFormLayout::FieldRole, linkEditFinStat);

        SECButtonTextEdit = new QLineEdit(tab_Links);
        SECButtonTextEdit->setObjectName(QStringLiteral("SECButtonTextEdit"));
        SECButtonTextEdit->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        SECButtonTextEdit->setFrame(false);

        formLayout->setWidget(4, QFormLayout::LabelRole, SECButtonTextEdit);

        linkEditSEC = new QLineEdit(tab_Links);
        linkEditSEC->setObjectName(QStringLiteral("linkEditSEC"));
        linkEditSEC->setMaximumSize(QSize(700, 16777215));
        linkEditSEC->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));

        formLayout->setWidget(4, QFormLayout::FieldRole, linkEditSEC);

        AnalysisButtonTextEdit = new QLineEdit(tab_Links);
        AnalysisButtonTextEdit->setObjectName(QStringLiteral("AnalysisButtonTextEdit"));
        AnalysisButtonTextEdit->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        AnalysisButtonTextEdit->setFrame(false);

        formLayout->setWidget(5, QFormLayout::LabelRole, AnalysisButtonTextEdit);

        linkEditAnalysis = new QLineEdit(tab_Links);
        linkEditAnalysis->setObjectName(QStringLiteral("linkEditAnalysis"));
        linkEditAnalysis->setMaximumSize(QSize(700, 16777215));
        linkEditAnalysis->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));

        formLayout->setWidget(5, QFormLayout::FieldRole, linkEditAnalysis);

        MarkmapButtonTextEdit = new QLineEdit(tab_Links);
        MarkmapButtonTextEdit->setObjectName(QStringLiteral("MarkmapButtonTextEdit"));
        MarkmapButtonTextEdit->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        MarkmapButtonTextEdit->setFrame(false);

        formLayout->setWidget(6, QFormLayout::LabelRole, MarkmapButtonTextEdit);

        linkEditOther = new QLineEdit(tab_Links);
        linkEditOther->setObjectName(QStringLiteral("linkEditOther"));
        linkEditOther->setMaximumSize(QSize(700, 16777215));
        linkEditOther->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));

        formLayout->setWidget(6, QFormLayout::FieldRole, linkEditOther);

        SpreadsheetButtonTextEdit = new QLineEdit(tab_Links);
        SpreadsheetButtonTextEdit->setObjectName(QStringLiteral("SpreadsheetButtonTextEdit"));
        SpreadsheetButtonTextEdit->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));
        SpreadsheetButtonTextEdit->setFrame(false);

        formLayout->setWidget(7, QFormLayout::LabelRole, SpreadsheetButtonTextEdit);

        linkEditSpreadsheet = new QLineEdit(tab_Links);
        linkEditSpreadsheet->setObjectName(QStringLiteral("linkEditSpreadsheet"));
        linkEditSpreadsheet->setMaximumSize(QSize(700, 16777215));
        linkEditSpreadsheet->setStyleSheet(QLatin1String("background-color: rgb(50, 50, 50);\n"
"color: rgb(220, 220, 220);\n"
"font: 87 7pt \"Arial Black\";"));

        formLayout->setWidget(7, QFormLayout::FieldRole, linkEditSpreadsheet);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab_Links);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        label->setFont(font2);
        label->setStyleSheet(QLatin1String("font: 7pt \"MS Shell Dlg 2\";\n"
"font: italic 8pt \"MS Shell Dlg 2\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 0, 1, 1);

        Tabs->addTab(tab_Links, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(3);
        Portslabel = new QLabel(tab);
        Portslabel->setObjectName(QStringLiteral("Portslabel"));

        gridLayout->addWidget(Portslabel, 0, 0, 1, 1);

        comboBoxPorts = new QComboBox(tab);
        comboBoxPorts->setObjectName(QStringLiteral("comboBoxPorts"));
        comboBoxPorts->setMaximumSize(QSize(76, 16777215));

        gridLayout->addWidget(comboBoxPorts, 0, 1, 1, 1);

        Toplinetextlabel = new QLabel(tab);
        Toplinetextlabel->setObjectName(QStringLiteral("Toplinetextlabel"));

        gridLayout->addWidget(Toplinetextlabel, 2, 0, 1, 1);

        ToplinebgLabel = new QLabel(tab);
        ToplinebgLabel->setObjectName(QStringLiteral("ToplinebgLabel"));

        gridLayout->addWidget(ToplinebgLabel, 3, 0, 1, 1);

        BottomlinetextLabel = new QLabel(tab);
        BottomlinetextLabel->setObjectName(QStringLiteral("BottomlinetextLabel"));

        gridLayout->addWidget(BottomlinetextLabel, 4, 0, 1, 1);

        BottomlinebgLabel = new QLabel(tab);
        BottomlinebgLabel->setObjectName(QStringLiteral("BottomlinebgLabel"));
        BottomlinebgLabel->setMinimumSize(QSize(0, 0));
        BottomlinebgLabel->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(BottomlinebgLabel, 5, 0, 1, 1);

        TopLineLabel = new QLabel(tab);
        TopLineLabel->setObjectName(QStringLiteral("TopLineLabel"));

        gridLayout->addWidget(TopLineLabel, 6, 0, 1, 1);

        BottomLineLabel = new QLabel(tab);
        BottomLineLabel->setObjectName(QStringLiteral("BottomLineLabel"));

        gridLayout->addWidget(BottomLineLabel, 7, 0, 1, 1);

        AuthTokenLabel = new QLabel(tab);
        AuthTokenLabel->setObjectName(QStringLiteral("AuthTokenLabel"));

        gridLayout->addWidget(AuthTokenLabel, 8, 0, 1, 1);

        AuthTokenpushButton = new QPushButton(tab);
        AuthTokenpushButton->setObjectName(QStringLiteral("AuthTokenpushButton"));
        AuthTokenpushButton->setMinimumSize(QSize(155, 23));
        AuthTokenpushButton->setFlat(false);

        gridLayout->addWidget(AuthTokenpushButton, 9, 2, 1, 1);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(211, 36));
        textEdit->setMaximumSize(QSize(16777215, 36));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 9, 0, 1, 2);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        comboBoxScrollSpeed = new QComboBox(tab);
        comboBoxScrollSpeed->setObjectName(QStringLiteral("comboBoxScrollSpeed"));
        comboBoxScrollSpeed->setMaximumSize(QSize(76, 16777215));

        gridLayout->addWidget(comboBoxScrollSpeed, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        Line1 = new QLineEdit(tab);
        Line1->setObjectName(QStringLiteral("Line1"));

        gridLayout->addWidget(Line1, 6, 1, 1, 4);

        Line2 = new QLineEdit(tab);
        Line2->setObjectName(QStringLiteral("Line2"));

        gridLayout->addWidget(Line2, 7, 1, 1, 4);

        lineEditAuthToken = new QLineEdit(tab);
        lineEditAuthToken->setObjectName(QStringLiteral("lineEditAuthToken"));

        gridLayout->addWidget(lineEditAuthToken, 8, 1, 1, 4);

        comboBoxToplinetext = new QComboBox(tab);
        comboBoxToplinetext->setObjectName(QStringLiteral("comboBoxToplinetext"));
        comboBoxToplinetext->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(comboBoxToplinetext, 2, 1, 1, 1);

        comboBoxToplinebg = new QComboBox(tab);
        comboBoxToplinebg->setObjectName(QStringLiteral("comboBoxToplinebg"));

        gridLayout->addWidget(comboBoxToplinebg, 3, 1, 1, 1);

        comboBoxBottomlinetext = new QComboBox(tab);
        comboBoxBottomlinetext->setObjectName(QStringLiteral("comboBoxBottomlinetext"));

        gridLayout->addWidget(comboBoxBottomlinetext, 4, 1, 1, 1);

        comboBoxBottomlinebg = new QComboBox(tab);
        comboBoxBottomlinebg->setObjectName(QStringLiteral("comboBoxBottomlinebg"));

        gridLayout->addWidget(comboBoxBottomlinebg, 5, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_5, 1, 0, 1, 1);

        Tabs->addTab(tab, QString());

        verticalLayout_8->addWidget(Tabs);


        horizontalLayout_5->addLayout(verticalLayout_8);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        RSSBrowser = new QListWidget(centralWidget);
        RSSBrowser->setObjectName(QStringLiteral("RSSBrowser"));
        RSSBrowser->setMinimumSize(QSize(0, 107));
        RSSBrowser->setMaximumSize(QSize(16777215, 175));

        gridLayout_3->addWidget(RSSBrowser, 1, 0, 1, 1);

        TKRTAP->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TKRTAP);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 677, 21));
        TKRTAP->setMenuBar(menuBar);
        QWidget::setTabOrder(AllButton, Charts);
        QWidget::setTabOrder(Charts, Screener);
        QWidget::setTabOrder(Screener, Econ);
        QWidget::setTabOrder(Econ, FinStat);
        QWidget::setTabOrder(FinStat, SEC);
        QWidget::setTabOrder(SEC, Analysis);
        QWidget::setTabOrder(Analysis, Other);
        QWidget::setTabOrder(Other, Spreadsheet);
        QWidget::setTabOrder(Spreadsheet, AddButton);
        QWidget::setTabOrder(AddButton, DelButton);
        QWidget::setTabOrder(DelButton, SaveButton);
        QWidget::setTabOrder(SaveButton, LoadButton);
        QWidget::setTabOrder(LoadButton, listView);
        QWidget::setTabOrder(listView, Tabs);
        QWidget::setTabOrder(Tabs, button_add_link);
        QWidget::setTabOrder(button_add_link, button_remove_link);
        QWidget::setTabOrder(button_remove_link, button_clear_RSS_links);
        QWidget::setTabOrder(button_clear_RSS_links, button_loadRSS);
        QWidget::setTabOrder(button_loadRSS, AddStockRSSButton);
        QWidget::setTabOrder(AddStockRSSButton, RSSlistView);
        QWidget::setTabOrder(RSSlistView, ChartsButtonTextEdit);
        QWidget::setTabOrder(ChartsButtonTextEdit, ScreenerButtonTextEdit);
        QWidget::setTabOrder(ScreenerButtonTextEdit, EconButtonTextEdit);
        QWidget::setTabOrder(EconButtonTextEdit, FinStatButtonTextEdit);
        QWidget::setTabOrder(FinStatButtonTextEdit, SECButtonTextEdit);
        QWidget::setTabOrder(SECButtonTextEdit, AnalysisButtonTextEdit);
        QWidget::setTabOrder(AnalysisButtonTextEdit, MarkmapButtonTextEdit);
        QWidget::setTabOrder(MarkmapButtonTextEdit, SpreadsheetButtonTextEdit);
        QWidget::setTabOrder(SpreadsheetButtonTextEdit, linkEditCharts);
        QWidget::setTabOrder(linkEditCharts, linkEditScreener);
        QWidget::setTabOrder(linkEditScreener, linkEditEcon);
        QWidget::setTabOrder(linkEditEcon, linkEditFinStat);
        QWidget::setTabOrder(linkEditFinStat, linkEditSEC);
        QWidget::setTabOrder(linkEditSEC, linkEditAnalysis);
        QWidget::setTabOrder(linkEditAnalysis, linkEditOther);
        QWidget::setTabOrder(linkEditOther, linkEditSpreadsheet);
        QWidget::setTabOrder(linkEditSpreadsheet, Line1);
        QWidget::setTabOrder(Line1, Line2);

        retranslateUi(TKRTAP);
        QObject::connect(actionExit, SIGNAL(triggered()), TKRTAP, SLOT(close()));

        Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TKRTAP);
    } // setupUi

    void retranslateUi(QMainWindow *TKRTAP)
    {
        TKRTAP->setWindowTitle(QApplication::translate("TKRTAP", "TKRTAP", 0));
        actionExit->setText(QApplication::translate("TKRTAP", "Exit", 0));
        label_8->setText(QString());
        Spreadsheet->setText(QApplication::translate("TKRTAP", "Spreadsheet", 0));
        Other->setText(QApplication::translate("TKRTAP", "Market Maps", 0));
        Analysis->setText(QApplication::translate("TKRTAP", "Analysis", 0));
        SEC->setText(QApplication::translate("TKRTAP", "SEC Filings", 0));
        FinStat->setText(QApplication::translate("TKRTAP", "Financial Statements", 0));
        Econ->setText(QApplication::translate("TKRTAP", "Economic Indicators", 0));
        Screener->setText(QApplication::translate("TKRTAP", "Screener", 0));
        Charts->setText(QApplication::translate("TKRTAP", "Charts", 0));
        Charts->setShortcut(QString());
        bout_connexion->setText(QApplication::translate("TKRTAP", "CONNECT", 0));
        AllButton->setText(QApplication::translate("TKRTAP", "TRIGGER ALL", 0));
        AddButton->setText(QApplication::translate("TKRTAP", "Add Stock", 0));
        DelButton->setText(QApplication::translate("TKRTAP", "Delete Stock", 0));
        SaveButton->setText(QApplication::translate("TKRTAP", "Save", 0));
        LoadButton->setText(QApplication::translate("TKRTAP", "Load", 0));
        DataFeedgroupBox->setTitle(QApplication::translate("TKRTAP", "Data Feed", 0));
        DataFeedcomboBox->clear();
        DataFeedcomboBox->insertItems(0, QStringList()
         << QApplication::translate("TKRTAP", "Yahoo", 0)
         << QApplication::translate("TKRTAP", "Quandl", 0)
         << QApplication::translate("TKRTAP", "Yahoo", 0)
        );
        groupBox->setTitle(QApplication::translate("TKRTAP", "Refresh Rate", 0));
        comboBoxRefresh->clear();
        comboBoxRefresh->insertItems(0, QStringList()
         << QApplication::translate("TKRTAP", "10s", 0)
         << QApplication::translate("TKRTAP", "30s", 0)
         << QApplication::translate("TKRTAP", "1m", 0)
         << QApplication::translate("TKRTAP", "2m", 0)
         << QApplication::translate("TKRTAP", "5m", 0)
         << QApplication::translate("TKRTAP", "15m", 0)
         << QApplication::translate("TKRTAP", "30m", 0)
         << QApplication::translate("TKRTAP", "1h", 0)
         << QApplication::translate("TKRTAP", "2h", 0)
         << QApplication::translate("TKRTAP", "Auto", 0)
        );
        Tabs->setTabText(Tabs->indexOf(tab_Stocks), QApplication::translate("TKRTAP", "Stocks", 0));
        AddStockRSSButton->setText(QApplication::translate("TKRTAP", "Add RSS Feeds of your stocks", 0));
        button_add_link->setText(QApplication::translate("TKRTAP", "Add Link", 0));
        button_remove_link->setText(QApplication::translate("TKRTAP", "Delete Link", 0));
        button_clear_RSS_links->setText(QApplication::translate("TKRTAP", "Clear", 0));
        Save_Button_RSS->setText(QApplication::translate("TKRTAP", "Save", 0));
        Load_Button_RSS->setText(QApplication::translate("TKRTAP", "Load", 0));
        RSScomboBox->clear();
        RSScomboBox->insertItems(0, QStringList()
         << QApplication::translate("TKRTAP", "Yahoo", 0)
         << QApplication::translate("TKRTAP", "Financial Content", 0)
        );
        label_2->setText(QApplication::translate("TKRTAP", "# Outputs", 0));
        button_loadRSS->setText(QApplication::translate("TKRTAP", "Load", 0));
        Tabs->setTabText(Tabs->indexOf(tab_RSS), QApplication::translate("TKRTAP", "RSS", 0));
        ChartsButtonTextEdit->setText(QApplication::translate("TKRTAP", "Stock Charts", 0));
        linkEditCharts->setText(QApplication::translate("TKRTAP", "http://www.freestockcharts.com/", 0));
        ScreenerButtonTextEdit->setText(QApplication::translate("TKRTAP", "Screener", 0));
        linkEditScreener->setText(QApplication::translate("TKRTAP", "http://www.finviz.com/screener.ashx", 0));
        EconButtonTextEdit->setText(QApplication::translate("TKRTAP", "Economic Indicators", 0));
        linkEditEcon->setText(QApplication::translate("TKRTAP", "http://www.tradingeconomics.com/", 0));
        FinStatButtonTextEdit->setText(QApplication::translate("TKRTAP", "Financial Statements", 0));
        linkEditFinStat->setText(QApplication::translate("TKRTAP", "http://www.morningstar.ca/", 0));
        SECButtonTextEdit->setText(QApplication::translate("TKRTAP", "SEC Filings", 0));
        linkEditSEC->setText(QApplication::translate("TKRTAP", "http://www.seclive.com/", 0));
        AnalysisButtonTextEdit->setText(QApplication::translate("TKRTAP", "Analysis", 0));
        linkEditAnalysis->setText(QApplication::translate("TKRTAP", "http://seekingalpha.com/", 0));
        MarkmapButtonTextEdit->setText(QApplication::translate("TKRTAP", "Market Maps", 0));
        linkEditOther->setText(QApplication::translate("TKRTAP", "http://www.finviz.com/map.ashx?t=sec", 0));
        SpreadsheetButtonTextEdit->setText(QApplication::translate("TKRTAP", "Spreadsheet", 0));
        linkEditSpreadsheet->setText(QApplication::translate("TKRTAP", "https://docs.google.com/spreadsheet/ccc?key=0Avxn4t2r6luCdDNtazB6Mk9Lei1HMGgwV3duMlphanc&usp=sharing", 0));
        label->setText(QApplication::translate("TKRTAP", "*The labels are editable.", 0));
        Tabs->setTabText(Tabs->indexOf(tab_Links), QApplication::translate("TKRTAP", "Links", 0));
        Portslabel->setText(QApplication::translate("TKRTAP", "Ports", 0));
        Toplinetextlabel->setText(QApplication::translate("TKRTAP", "Top line text color", 0));
        ToplinebgLabel->setText(QApplication::translate("TKRTAP", "Top line background color", 0));
        BottomlinetextLabel->setText(QApplication::translate("TKRTAP", "Bottom line text color", 0));
        BottomlinebgLabel->setText(QApplication::translate("TKRTAP", "Bottom line background color", 0));
        TopLineLabel->setText(QApplication::translate("TKRTAP", "Top line text", 0));
        BottomLineLabel->setText(QApplication::translate("TKRTAP", "Bottom line text", 0));
        AuthTokenLabel->setText(QApplication::translate("TKRTAP", "Quandl Auth Token", 0));
        AuthTokenpushButton->setText(QApplication::translate("TKRTAP", "Get a Quandl Auth Token", 0));
        textEdit->setHtml(QApplication::translate("TKRTAP", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial Black'; font-size:8pt; font-weight:80; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:7pt;\">If you refresh using Quandl more than 50 times per day you need an auth token.</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("TKRTAP", "Scroll Speed", 0));
        comboBoxScrollSpeed->clear();
        comboBoxScrollSpeed->insertItems(0, QStringList()
         << QApplication::translate("TKRTAP", "Fast", 0)
         << QApplication::translate("TKRTAP", "Medium", 0)
         << QApplication::translate("TKRTAP", "Slow", 0)
        );
        Tabs->setTabText(Tabs->indexOf(tab), QApplication::translate("TKRTAP", "Output", 0));
    } // retranslateUi

};

namespace Ui {
    class TKRTAP: public Ui_TKRTAP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TKRTAP_H
