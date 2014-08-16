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
