TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Bio.cpp \
        Concentrator.cpp \
        Controller.cpp \
        Cube.cpp \
        Node.cpp \
        PinImpl.cpp \
        Primer.cpp \
        Pump.cpp \
        PumpController.cpp \
        PumpControllerHelpers.cpp \
        Sensors.cpp \
        SensorsImpl.cpp \
        Tank.cpp \
        TankHelpers.cpp \
        TestTank.cpp \
        Timer.cpp \
        TimerImpl.cpp \
        Well.cpp \
        main.cpp

HEADERS += \
    ArduinoButton.h \
    Bio.h \
    Common.h \
    Concentrator.h \
    Controller.h \
    Cube.h \
    Node.h \
    PinImpl.h \
    Primer.h \
    Pump.h \
    PumpController.h \
    PumpControllerHelpers.h \
    Sensors.h \
    SensorsImpl.h \
    SensorsImplDef.h \
    States.h \
    Tank.h \
    TankHelpers.h \
    TestTank.h \
    Timer.h \
    TimerImpl.h \
    Well.h
