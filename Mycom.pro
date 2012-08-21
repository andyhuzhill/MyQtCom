#-------------------------------------------------
#
# Project created by QtCreator 2012-07-09T22:57:17
#
#-------------------------------------------------

QT       += core gui static

TARGET = Mycom
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/qextserialport.cpp \
    src/qextserialport_unix.cpp

HEADERS  += mainwindow.h \
    src/qextserialport.h \
    src/qextserialport_global.h \
    src/qextserialport_p.h

FORMS    += mainwindow.ui

OTHER_FILES +=
