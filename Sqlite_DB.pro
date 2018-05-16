#-------------------------------------------------
#
# Project created by QtCreator 2018-05-16T03:14:05
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sqlite_DB
TEMPLATE = app
INCLUDEPATH += .


SOURCES += main.cpp\
        login.cpp \
    photoinfo.cpp

HEADERS  += login.h \
    photoinfo.h

FORMS    += login.ui \
    photoinfo.ui

RESOURCES += \
    sqlite_db.qrc
