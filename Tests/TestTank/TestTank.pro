QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_tank.cpp \
    $$prefix/TestTank.cpp \
    $$prefix/Tank.cpp \
    $$prefix/PinImpl.cpp \
    MockSensors.cpp

HEADERS += $$prefix/TestTank.h \
    $$prefix/Tank.h \
    $$prefix/Sensors.h \
    $$prefix/PinImpl.h \
    $$prefix/ArduinoButton.h \
    MockSensors.h
