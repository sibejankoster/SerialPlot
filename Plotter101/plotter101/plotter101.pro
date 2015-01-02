#-------------------------------------------------
#
# Project created by QtCreator 2015-01-02T07:39:29
#
#-------------------------------------------------

QT       += core serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plotter101
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ../qcustomplot.cpp

HEADERS  += widget.h \
    ../qcustomplot.h

