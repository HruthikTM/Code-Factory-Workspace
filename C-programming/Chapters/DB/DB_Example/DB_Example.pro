TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt sql

SOURCES += \
        main.c \
        sqlite3.c

HEADERS += \
    sqlite3.h \
    sqlite3ext.h
