TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ArduinoButtonImpl.cpp \
        PinImpl.cpp \
        Pump.cpp \
        Timer.cpp \
        TimerImpl.cpp \
        main.cpp

HEADERS += \
    ArduinoButton.h \
    ArduinoButtonImpl.h \
    Common.h \
    PinImpl.h \
    Pump.h \
    Sensors.h \
    Tanks.h \
    Timer.h \
    TimerImpl.h
