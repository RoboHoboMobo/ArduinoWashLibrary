QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += \
    $$prefix/Tank.cpp \
    TestSensor.cpp \
    tst_tank.cpp

HEADERS += $$prefix/Tanks.h \
    TestSensor.h

