TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Node.cpp \
        PinImpl.cpp \
        Pump.cpp \
        PumpController.cpp \
        PumpControllerHelpers.cpp \
        Sensors.cpp \
        SensorsImpl.cpp \
        Tank.cpp \
        TestTank.cpp \
        Timer.cpp \
        TimerImpl.cpp \
        main.cpp

HEADERS += \
    ArduinoButton.h \
    Common.h \
    Node.h \
    PinImpl.h \
    Pump.h \
    PumpController.h \
    PumpControllerHelpers.h \
    Sensors.h \
    SensorsImpl.h \
    SensorsImplDef.h \
    States.h \
    Tank.h \
    TestTank.h \
    Timer.h \
    TimerImpl.h
