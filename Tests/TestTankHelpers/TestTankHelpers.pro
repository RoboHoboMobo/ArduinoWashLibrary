QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_tankhelpers.cpp \
    $$prefix/TankHelpers.cpp \
    $$prefix/Tank.cpp \
    TestTank.cpp \
    TestSensor.cpp

HEADERS += $$prefix/TankHelpers.h \
    $$prefix/Tank.h \
    TestTank.h \
    TestSensor.h
