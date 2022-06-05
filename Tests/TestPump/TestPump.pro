QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_pump.cpp \
    $$prefix/Pump.cpp \
    $$prefix/PinImpl.cpp

HEADERS += $$prefix/Pump.h \
    $$prefix/PinImpl.h
