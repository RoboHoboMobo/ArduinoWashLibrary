QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_tanks.cpp \
    $$prefix/Tanks.cpp \
    TestSensor.cpp

HEADERS += $$prefix/Tanks.h \
    TestSensor.h

