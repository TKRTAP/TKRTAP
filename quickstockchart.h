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

class QuickStockChart : public QDialog
{
    Q_OBJECT
private slots:
    void savePosition();
    void loadPosition();
    void closeEvent(QCloseEvent *event);

public:
    explicit QuickStockChart(QWidget *parent = 0,QUrl QuickStockChartUrl=QUrl("http://www.finviz.com/chart.ashx?t=SPY&ty=c&ta=1&p=d&s=l"));
    ~QuickStockChart();

private:
    Ui::QuickStockChart *ui;
};

#endif // QUICKSTOCKCHART_H
