TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Company.cpp \
        Employee.cpp \
        External_Employee.cpp \
        FullTime_Employee.cpp \
        PartTime_Employee.cpp \
        main.cpp

HEADERS += \
    Company.h \
    Employee.h \
    External_Employee.h \
    FullTime_Employee.h \
    PartTime_Employee.h
