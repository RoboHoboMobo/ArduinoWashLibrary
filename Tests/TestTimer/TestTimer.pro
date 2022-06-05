QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

prefix = $$PWD/../../Sources

INCLUDEPATH += $$prefix

SOURCES += tst_timer.cpp \
    $$prefix/Timer.cpp \
    MockTimerImpl.cpp

HEADERS += $$prefix/Timer.h \
    MockTimerImpl.h
