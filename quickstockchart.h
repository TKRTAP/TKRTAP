/**
  * \file quickstockchart.h
  * \brief Implementation of the stock chart dialog window
  * \author Shariff Côté
  * \date 07/16/2014
*/

#ifndef QUICKSTOCKCHART_H
#define QUICKSTOCKCHART_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QSettings>
#include <QDebug>
#include <QRect>
#include <QCloseEvent>

namespace Ui {
class QuickStockChart;
}
/**
 * @brief The QuickStockChart class handles the display of the stock charts
 */
class QuickStockChart : public QDialog
{
    Q_OBJECT
private slots:
    void savePosition();   /**< @brief Saves the position of the dialog box*/
    void loadPosition();   /**< @brief Loads the position of the dialog box*/
    void closeEvent(QCloseEvent *event); /**< @brief Functions triggered when dialog box is closed*/

public:
    explicit QuickStockChart(QWidget *parent = 0,QUrl QuickStockChartUrl=QUrl("http://www.finviz.com/chart.ashx?t=SPY&ty=c&ta=1&p=d&s=l"));
    ~QuickStockChart();

private:
    Ui::QuickStockChart *ui;   /**< @brief Creating of the UI of the Market Map*/
};

#endif // QUICKSTOCKCHART_H
