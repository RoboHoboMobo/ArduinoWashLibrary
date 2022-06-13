TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        PinImpl.cpp \
        Pump.cpp \
        Sensors.cpp \
        SensorsImpl.cpp \
        Tanks.cpp \
        Timer.cpp \
        TimerImpl.cpp \
        main.cpp

HEADERS += \
    ArduinoButton.h \
    Common.h \
    PinImpl.h \
    Pump.h \
    PumpController.h \
    Sensors.h \
    SensorsImpl.h \
    SensorsImplDef.h \
    Tanks.h \
    Timer.h \
    TimerImpl.h
