/**
  * \file main.cpp
  * \brief Implementation of the main GUI class
  * \author Shariff Côté and Quentin Barry-Marcheterre
  * \date 07/16/2014
*/

#include "tkrtap.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("QS Tech");
    a.setOrganizationDomain("tkrtap.net");
    a.setApplicationName("TKRTAP");

    TKRTAP w;

    w.show();

    return a.exec();
}
