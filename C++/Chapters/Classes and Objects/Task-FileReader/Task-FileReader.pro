TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Company.cpp \
        Csv_Reader.cpp \
        EmployeeDetails.cpp \
        FileReader.cpp \
        Sql_Reader.cpp \
        Txt_Reader.cpp \
        main.cpp \
        sqlite3.c

HEADERS += \
    Company.h \
    Csv_Reader.h \
    EmployeeDetails.h \
    FileReader.h \
    Sql_Reader.h \
    Txt_Reader.h \
    sqlite3.h \
    sqlite3ext.h
