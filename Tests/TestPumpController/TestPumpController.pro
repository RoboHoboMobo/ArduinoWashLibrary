QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_pumpcontroller.cpp \
    $$prefix/Tank.cpp \
    TestSensor.cpp \
    $$prefix/Timer.cpp \
    MockTimerImpl.cpp \
    $$prefix/Pump.cpp \
    MockPinImpl.cpp \
    TestTank.cpp

HEADERS += $$prefix/Tank.h \
    TestSensor.h \
    $$prefix/Timer.h \
    $$prefix/TimerImpl.h \
    MockTimerImpl.h \
    $$prefix/Pump.h \
    MockPinImpl.h \
    TestTank.h

