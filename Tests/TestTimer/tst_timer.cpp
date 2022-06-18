#include <QtTest>

#include "Timer.h"

#include "MockTimerImpl.h"

class TestTimer : public QObject
{
    Q_OBJECT

public:
    TestTimer();
    ~TestTimer();

private slots:
    void init();

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

    void isDoneIfNotStarted();
    void isDoneIfRunning();
    void isDoneIfPaused();
    void isDoneIfStoppendAndTimeIsOut();
};

TestTimer::TestTimer()
{
}

TestTimer::~TestTimer()
{
}

void TestTimer::init()
{
    Timer t(123);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::startIfStoppedAndHasRemain()
{
    Timer t(123);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123u);

    MockTimerImpl::setTime(1000);

    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::startIfStoppedWithoutRemain()
{
    Timer t(0);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 0u);

    t.start();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 0u);
}

void TestTimer::startIfRunning()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::startIfPaused()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.start();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::stopIfStopped()
{
    Timer t(123);
    t.stop();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::stopIfRunning()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.stop();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::stopIfPaused()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.stop();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::resumeIfStopped()
{
    Timer t(123);
    t.resume();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::resumeIfRunning()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.resume();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::resumeIfPaused()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.resume();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::pauseIfStopped()
{
    Timer t(123);
    t.pause();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::pauseIfRunning()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::pauseIfPaused()
{
    Timer t(123);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.pause();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::updateIfStopped()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);
    t.update();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::updateIfRunningAndHasRemain()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    MockTimerImpl::setTime(1122);
    t.update();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 1u);
}

void TestTimer::updateIfRunningWithoutRemain()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);
    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    MockTimerImpl::setTime(2000);
    t.update();

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 0u);
}

void TestTimer::updateIfPaused()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);

    t.start();
    t.pause();

    MockTimerImpl::setTime(2000);
    t.update();

    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::testReset()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);

    t.start();

    MockTimerImpl::setTime(1100u);
    t.update();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 23u);

    t.reset(234u);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 234u);
}

void TestTimer::startAfterReset()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);

    t.start();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    t.reset(234u);

    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 234u);

    MockTimerImpl::setTime(2000);

    t.start();

    MockTimerImpl::setTime(2200);

    t.update();

    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 34u);
}

void TestTimer::isDoneIfNotStarted()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);

    t.update();

    QVERIFY(!t.isDone());
    QCOMPARE(t.getRemainingTime(), 123u);

    MockTimerImpl::setTime(2000);

    t.update();

    QVERIFY(!t.isDone());
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::isDoneIfRunning()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);

    t.start();

    QVERIFY(!t.isDone());
    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    MockTimerImpl::setTime(1100);

    t.start();

    QVERIFY(!t.isDone());
    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);
}

void TestTimer::isDoneIfPaused()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);

    t.start();

    QVERIFY(!t.isDone());
    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    MockTimerImpl::setTime(1100);

    t.update();
    t.pause();

    QVERIFY(!t.isDone());
    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 23u);

    t.update();

    QVERIFY(!t.isDone());
    QVERIFY(t.getState() == Timer::State::Paused);
    QCOMPARE(t.getRemainingTime(), 23u);
}

void TestTimer::isDoneIfStoppendAndTimeIsOut()
{
    Timer t(123);

    MockTimerImpl::setTime(1000);

    t.start();

    QVERIFY(!t.isDone());
    QVERIFY(t.getState() == Timer::State::Running);
    QCOMPARE(t.getRemainingTime(), 123u);

    MockTimerImpl::setTime(2000);

    t.update();

    QVERIFY(t.isDone());
    QVERIFY(t.getState() == Timer::State::Stopped);
    QCOMPARE(t.getRemainingTime(), 0u);
}

QTEST_APPLESS_MAIN(TestTimer)

#include "tst_timer.moc"
