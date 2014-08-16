#ifndef MARKETMAPVIEW_H
#define MARKETMAPVIEW_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QSettings>
#include <QDebug>
#include <QRect>
#include <QCloseEvent>

namespace Ui {
class MarketMapView;
}

class MarketMapView : public QDialog
{
    Q_OBJECT
private slots:
    void savePosition();
    void loadPosition();
    void closeEvent(QCloseEvent *event);


public:
    explicit MarketMapView(QWidget *parent = 0,QUrl MapUrl=QUrl("http://www.finviz.com/map.ashx?t=sec"));
    ~MarketMapView();

private:
    Ui::MarketMapView *ui;
};

#endif // MARKETMAPVIEW_H
