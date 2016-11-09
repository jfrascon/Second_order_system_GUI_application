#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T17:47:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = second_order_system_step_response_plot
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    SecondOrderSystem.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    SecondOrderSystem.h \
    qcustomplot.h

FORMS    += mainwindow.ui
