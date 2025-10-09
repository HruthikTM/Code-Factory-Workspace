TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        EliteInsurance.cpp \
        HealthInsurance.cpp \
        PolicyInterface.cpp \
        PremiumInsurance.cpp \
        main.cpp

HEADERS += \
    EliteInsurance.h \
    HealthInsurance.h \
    PolicyInterface.h \
    PremiumInsurance.h
