/**
  * \file marketmapview.cpp
  * \brief Implementation of the Market Map dialog window
  * \author Shariff Côté
  * \date 07/16/2014
*/

#include "marketmapview.h"
#include "ui_marketmapview.h"

/**
 * @brief Constructor
 * @param parent The parent widget
 * @param MapUrl ULR to display
 */
MarketMapView::MarketMapView(QWidget *parent,QUrl MapUrl) :
    QDialog(parent),
    ui(new Ui::MarketMapView)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icons/img/tkrtapico"));
    setWindowTitle("Market Map");
    ui->MarketMapWebView->load(MapUrl);
    loadPosition();
    this->setMaximumWidth(615);
    this->setMaximumHeight(335);
    this->setMinimumWidth(615);
    this->setMinimumHeight(335);
}

MarketMapView::~MarketMapView()
{
    delete ui;
}

void MarketMapView::savePosition()
{
    //Save
    QSettings settings ("QS Tech", "TKRTAP");
    settings.beginGroup("MarketMapWindow");
    settings.setValue("positionMarketMap",this->geometry());

    settings.endGroup();

    qDebug() <<"MarketMap Position Loaded";
}

void MarketMapView::loadPosition()
{
    //Load;
    QSettings settingsMarketMap ("QS Tech", "TKRTAP");
    settingsMarketMap.beginGroup("MarketMapWindow");
    QRect MarketMapdefaultRect(8,30,615,335);
    QRect MarketMaprect = settingsMarketMap.value("positionMarketMap",MarketMapdefaultRect).toRect();
    setGeometry(MarketMaprect);
    settingsMarketMap.endGroup();

    qDebug() <<"MarketMap Position Loaded";
}

void MarketMapView::closeEvent(QCloseEvent *event)
{
    savePosition();
    QDialog::closeEvent(event);
}
