/**
  * \file marketmapview.h
  * \brief Implementation of the Market Map dialog window
  * \author Shariff Côté
  * \date 07/16/2014
*/

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
    void savePosition();  /**< @brief Saves the position of the dialog box*/
    void loadPosition();  /**< @brief Loads the position of the dialog box*/
    void closeEvent(QCloseEvent *event);  /**< @brief Functions triggered when dialog box is closed*/


public:
    explicit MarketMapView(QWidget *parent = 0,QUrl MapUrl=QUrl("http://www.finviz.com/map.ashx?t=sec"));
    ~MarketMapView();

private:
    Ui::MarketMapView *ui; /**< @brief Creating of the UI of the Market Map*/
};

#endif // MARKETMAPVIEW_H
