QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_concentrator.cpp \
    $$prefix/Concentrator.cpp \
    $$prefix/Tank.cpp \
    $$prefix/TankHelpers.cpp \
    $$prefix/PinImpl.cpp \
    MockSensors.cpp

HEADERS += $$prefix/Concentrator.h \
    $$prefix/Tank.h \
    $$prefix/TankHelpers.h \
    $$prefix/PinImpl.h \
    MockSensors.h
