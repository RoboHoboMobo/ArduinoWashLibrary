QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_pumpcontroller.cpp \
    $$prefix/PumpController.cpp \
    $$prefix/PumpControllerHelpers.cpp \
    $$prefix/Node.cpp \
    MockPump.cpp \
    $$prefix/Tank.cpp \
    TestTank.cpp \
    TestSensor.cpp \
    MockTimer.cpp

HEADERS += $$prefix/PumpController.h \
    $$prefix/PumpControllerHelpers.h \
    $$prefix/Node.h \
    MockPump.h \
    $$prefix/Tank.h \
    TestTank.h \
    TestSensor.h \
    $$prefix/Timer.h \
    MockTimer.h


