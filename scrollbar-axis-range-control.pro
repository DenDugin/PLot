#-------------------------------------------------
#
# Project created by QtCreator 2013-07-25T20:43:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = scrollbar-axis-range-control
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../qcustomplot.cpp \
    dialog.cpp \
    new_dialog.cpp \
    con_dialog.cpp

HEADERS  += mainwindow.h \
    ../../qcustomplot.h \
    dialog.h \
    new_dialog.h \
    con_dialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    new_dialog.ui \
    con_dialog.ui

CONFIG += qaxcontainer
