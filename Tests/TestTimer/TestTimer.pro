QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_timer.cpp \
    $$prefix/Timer.cpp \
    MockTimerHelpers.cpp

HEADERS += $$prefix/Timer.h \
    $$prefix/TimerHelpers.h \
    MockTimerHelpers.h
