/********************************************************************************
** Form generated from reading UI file 'quickstockchart.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUICKSTOCKCHART_H
#define UI_QUICKSTOCKCHART_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_QuickStockChart
{
public:
    QFormLayout *formLayout;
    QWebView *QuickChartView;

    void setupUi(QDialog *QuickStockChart)
    {
        if (QuickStockChart->objectName().isEmpty())
            QuickStockChart->setObjectName(QStringLiteral("QuickStockChart"));
        QuickStockChart->resize(496, 270);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/img/tkrtapico.png"), QSize(), QIcon::Normal, QIcon::Off);
        QuickStockChart->setWindowIcon(icon);
        QuickStockChart->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        formLayout = new QFormLayout(QuickStockChart);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        QuickChartView = new QWebView(QuickStockChart);
        QuickChartView->setObjectName(QStringLiteral("QuickChartView"));
        QuickChartView->setUrl(QUrl(QStringLiteral("about:blank")));
        QuickChartView->setZoomFactor(1);

        formLayout->setWidget(0, QFormLayout::LabelRole, QuickChartView);


        retranslateUi(QuickStockChart);

        QMetaObject::connectSlotsByName(QuickStockChart);
    } // setupUi

    void retranslateUi(QDialog *QuickStockChart)
    {
        QuickStockChart->setWindowTitle(QApplication::translate("QuickStockChart", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class QuickStockChart: public Ui_QuickStockChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUICKSTOCKCHART_H
