TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Admin.cpp \
        AuthenticateUser.cpp \
        Channels.cpp \
        Customer.cpp \
        DTHServiceProvider.cpp \
        FileReader.cpp \
        Languages.cpp \
        Package.cpp \
        PersonDetails.cpp \
        Programs.cpp \
        SqlReader.cpp \
        main.cpp \
        sqlite3.c

HEADERS += \
    Admin.h \
    AuthenticateUser.h \
    Channels.h \
    Customer.h \
    DTHServiceProvider.h \
    FileReader.h \
    Languages.h \
    Package.h \
    PersonDetails.h \
    Programs.h \
    SqlReader.h \
    sqlite3.h \
    sqlite3ext.h
