QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_pumpcontroller.cpp \
    $$prefix/PumpController.cpp \
    $$prefix/PumpControllerHelpers.cpp \
    $$prefix/Tank.cpp \
    MockNode.cpp \
    MockPump.cpp \
    TestNode.cpp \
    TestTank.cpp \
    TestSensor.cpp

HEADERS += $$prefix/PumpController.h \
    $$prefix/PumpControllerHelpers.h \
    $$prefix/Node.h \
    $$prefix/Pump.h \
    $$prefix/Timer.h \
    $$prefix/Tank.h \
    $$prefix/Sensors.h \
    MockNode.h \
    MockPump.h \
    TestNode.h \
    TestTank.h \
    TestSensor.h


