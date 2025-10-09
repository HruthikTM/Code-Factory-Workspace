TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        CardPayment.cpp \
        CashPayment.cpp \
        GenerateBill.cpp \
        PaymentGateway.cpp \
        UPIPayment.cpp \
        main.cpp

HEADERS += \
    CardPayment.h \
    CashPayment.h \
    GenerateBill.h \
    PaymentGateway.h \
    UPIPayment.h
