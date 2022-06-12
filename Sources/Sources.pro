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
    ArduinoButton.h \
    Common.h \
    PinImpl.h \
    Pump.h \
    Sensors.h \
    SensorsImpl.h \
    SensorsImpl.tpp \
    Tanks.h \
    Timer.h \
    TimerImpl.h
