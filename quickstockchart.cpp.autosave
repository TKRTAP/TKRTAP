/**
  * \file quickstockchart.cpp
  * \brief Implementation of the stock chart dialog window
  * \author Shariff Côté
  * \date 07/16/2014
*/

#include "quickstockchart.h"
#include "ui_quickstockchart.h"

QuickStockChart::QuickStockChart(QWidget *parent,QUrl QuickStockChartUrl) :
    QDialog(parent),
    ui(new Ui::QuickStockChart)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icons/img/tkrtapico"));
    setWindowTitle("Stock Chart");
    ui->QuickChartView->load(QuickStockChartUrl);
    loadPosition();
    this->setMaximumHeight(370);
    this->setMaximumWidth(720);
}

QuickStockChart::~QuickStockChart()
{
    delete ui;
}

void QuickStockChart::savePosition()
{
    //Save
    QSettings settings ("QS Tech", "TKRTAP");
    settings.beginGroup("QuickStockChartWindow");
    settings.setValue("positionQuickStockChart",this->geometry());

    settings.endGroup();

    qDebug() <<"QuickStockChart Position Saved";
}

void QuickStockChart::loadPosition()
{
    //Load;
    QSettings settingsQuickStockChart ("QS Tech", "TKRTAP");
    settingsQuickStockChart.beginGroup("QuickStockChartWindow");
    QRect QuickStockChartdefaultRect(8,30,521,251);
    QRect QuickStockChartrect = settingsQuickStockChart.value("positionQuickStockChart",QuickStockChartdefaultRect).toRect();
    setGeometry(QuickStockChartrect);
    settingsQuickStockChart.endGroup();

    qDebug() <<"QuickStockChart Position Loaded";
}

void QuickStockChart::closeEvent(QCloseEvent *event)
{
    savePosition();
    QDialog::closeEvent(event);
}
