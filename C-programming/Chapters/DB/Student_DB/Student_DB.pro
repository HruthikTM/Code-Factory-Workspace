TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        crud.c \
        main.c \
        sqlite3.c

HEADERS += \
    Student.h \
    sqlite3.h \
    sqlite3ext.h
