TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Admin.cpp \
        AdminModel.cpp \
        AuthenticateUser.cpp \
        Channels.cpp \
        Customer.cpp \
        CustomerModel.cpp \
        DthServiceProvider.cpp \
        FileReader.cpp \
        Language.cpp \
        LanguageModel.cpp \
        MainDataModel.cpp \
        Package.cpp \
        PackageModel.cpp \
        PersonDetails.cpp \
        Program.cpp \
        SqlReader.cpp \
        main.cpp \
        sqlite3.c

HEADERS += \
    Admin.h \
    AdminModel.h \
    AuthenticateUser.h \
    Channels.h \
    Customer.h \
    CustomerModel.h \
    DthServiceProvider.h \
    FileReader.h \
    Language.h \
    LanguageModel.h \
    MainDataModel.h \
    Package.h \
    PackageModel.h \
    PersonDetails.h \
    Program.h \
    SqlReader.h \
    sqlite3.h \
    sqlite3ext.h
