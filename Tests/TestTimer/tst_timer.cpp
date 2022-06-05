#include <QtTest>

#include "Timer.h"

#include "MockTimerHelpers.h"

class TestTimer : public QObject
{
    Q_OBJECT

public:
    TestTimer();
    ~TestTimer();

private slots:
    void Init();

    void startIfStoppedAndHasRemain();
    void startIfStoppedWithoutRemain();
    void startIfRunning();
    void startIfPaused();

    void stopIfStopped();
    void stopIfRunning();
    void stopIfPaused();

    void resumeIfStopped();
    void resumeIfRunning();
    void resumeIfPaused();

    void pauseIfStopped();
    void pauseIfRunning();
    void pauseIfPaused();

    void updateIfStopped();
    void updateIfRunningAndHasRemain();
    void updateIfRunningWithoutRemain();
    void updateIfPaused();

    void testReset();
    void startAfterReset();
};

TestTimer::TestTimer()
{
}

TestTimer::~TestTimer()
{
}

void TestTimer::Init()
{
    Timer t(123);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::startIfStoppedAndHasRemain()
{
    Timer t(123);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123);

    MockTimerHelpers::setTime(1000);

    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::startIfStoppedWithoutRemain()
{
    Timer t(0);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 0);

    t.start();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 0);
}

void TestTimer::startIfRunning()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::startIfPaused()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123);

    t.start();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::stopIfStopped()
{
    Timer t(123);
    t.stop();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::stopIfRunning()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.stop();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::stopIfPaused()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123);

    t.stop();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::resumeIfStopped()
{
    Timer t(123);
    t.resume();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::resumeIfRunning()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.resume();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::resumeIfPaused()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123);

    t.resume();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::pauseIfStopped()
{
    Timer t(123);
    t.pause();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::pauseIfRunning()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::pauseIfPaused()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::updateIfStopped()
{
    Timer t(123);

    MockTimerHelpers::setTime(1000);
    t.update();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::updateIfRunningAndHasRemain()
{
    Timer t(123);

    MockTimerHelpers::setTime(1000);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    MockTimerHelpers::setTime(1122);
    t.update();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 1);
}

void TestTimer::updateIfRunningWithoutRemain()
{
    Timer t(123);

    MockTimerHelpers::setTime(1000);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    MockTimerHelpers::setTime(2000);
    t.update();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 0);
}

void TestTimer::updateIfPaused()
{
    Timer t(123);

    MockTimerHelpers::setTime(1000);

    t.start();
    t.pause();

    MockTimerHelpers::setTime(2000);
    t.update();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123);
}

void TestTimer::testReset()
{
    Timer t(123);

    MockTimerHelpers::setTime(1000);

    t.start();

    MockTimerHelpers::setTime(1100);
    t.update();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 23);

    t.reset(234);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 234);
}

void TestTimer::startAfterReset()
{
    Timer t(123);

    MockTimerHelpers::setTime(1000);

    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123);

    t.reset(234);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 234);

    MockTimerHelpers::setTime(2000);

    t.start();

    MockTimerHelpers::setTime(2200);

    t.update();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 34);
}

QTEST_APPLESS_MAIN(TestTimer)

#include "tst_timer.moc"
