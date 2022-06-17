TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Node.cpp \
        PinImpl.cpp \
        Pump.cpp \
        PumpLogic.cpp \
        PumpLogicHelpers.cpp \
        Sensors.cpp \
        SensorsImpl.cpp \
        Tank.cpp \
        Timer.cpp \
        TimerImpl.cpp \
        main.cpp

HEADERS += \
    ArduinoButton.h \
    Common.h \
    Node.h \
    PinImpl.h \
    Pump.h \
    PumpLogic.h \
    PumpLogicHelpers.h \
    Sensors.h \
    SensorsImpl.h \
    SensorsImplDef.h \
    States.h \
    Tank.h \
    Timer.h \
    TimerImpl.h
