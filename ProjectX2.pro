#-------------------------------------------------
#
# Project created by QtCreator 2014-06-15T10:45:31
#
#-------------------------------------------------

QT       += core gui webkitwidgets serialport network
RC_FILE = tkrtap.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectX2
TEMPLATE = app


SOURCES += main.cpp\
        tkrtap.cpp \
    marketmapview.cpp \
    matricergb.cpp \
    quickstockchart.cpp \
    rssclient.cpp \
    jsonquery.cpp

HEADERS  += tkrtap.h \
    marketmapview.h \
    matricergb.h \
    quickstockchart.h \
    datetime_utils.hpp \
    rssclient.h \
    strtk.hpp \
    jsonquery.h

FORMS    += tkrtap.ui \
    marketmapview.ui \
    quickstockchart.ui

RESOURCES += \
    tkrtap.qrc

DEFINES += strtk_no_tr1_or_boost
