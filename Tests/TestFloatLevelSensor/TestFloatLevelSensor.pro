QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_floatlevelsensor.cpp \
    $$prefix/PinImpl.cpp

HEADERS += $$prefix/Sensors.h \
    $$prefix/ArduinoButton.h \
    $$prefix/PinImpl.h \
    $$prefix/SensorsImpl.h \
    MockSensorsImpl.tpp

