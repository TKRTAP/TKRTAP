/********************************************************************************
** Form generated from reading UI file 'marketmapview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKETMAPVIEW_H
#define UI_MARKETMAPVIEW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MarketMapView
{
public:
    QWebView *MarketMapWebView;

    void setupUi(QDialog *MarketMapView)
    {
        if (MarketMapView->objectName().isEmpty())
            MarketMapView->setObjectName(QStringLiteral("MarketMapView"));
        MarketMapView->resize(427, 348);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MarketMapView->sizePolicy().hasHeightForWidth());
        MarketMapView->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/img/tkrtapico.png"), QSize(), QIcon::Normal, QIcon::Off);
        MarketMapView->setWindowIcon(icon);
        MarketMapWebView = new QWebView(MarketMapView);
        MarketMapWebView->setObjectName(QStringLiteral("MarketMapWebView"));
        MarketMapWebView->setGeometry(QRect(0, -100, 501, 481));
        MarketMapWebView->setUrl(QUrl(QStringLiteral("about:blank")));
        MarketMapWebView->setZoomFactor(0.6);

        retranslateUi(MarketMapView);

        QMetaObject::connectSlotsByName(MarketMapView);
    } // setupUi

    void retranslateUi(QDialog *MarketMapView)
    {
        MarketMapView->setWindowTitle(QApplication::translate("MarketMapView", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class MarketMapView: public Ui_MarketMapView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKETMAPVIEW_H
