TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Channels.cpp \
        FileReader.cpp \
        Programs.cpp \
        Service_Provider.cpp \
        Sql_Reader.cpp \
        main.cpp \
        sqlite3.c

HEADERS += \
    Channels.h \
    FileReader.h \
    Programs.h \
    Service_Provider.h \
    Sql_Reader.h \
    sqlite3.h \
    sqlite3ext.h
