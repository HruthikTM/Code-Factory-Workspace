TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Child.cpp \
        GrandParent.cpp \
        Parent.cpp \
        main.cpp

HEADERS += \
    Child.h \
    GrandParent.h \
    Parent.h
