#-------------------------------------------------
#
# Project created by QtCreator 2013-06-08T08:30:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Vhdl2LatexSch
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    entity.cpp \
    ios.cpp \
    input.cpp \
    output.cpp \
    filemanager.cpp

HEADERS  += mainwindow.h \
    entity.h \
    ios.h \
    input.h \
    output.h \
    filemanager.h

FORMS    += mainwindow.ui
