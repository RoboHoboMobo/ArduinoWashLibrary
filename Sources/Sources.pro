TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        PinImpl.cpp \
        Pump.cpp \
        Timer.cpp \
        TimerImpl.cpp \
        main.cpp

HEADERS += \
    Common.h \
    PinImpl.h \
    Pump.h \
    Timer.h \
    TimerImpl.h
