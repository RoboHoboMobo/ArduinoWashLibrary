#include <QtTest>

#include "PumpController.h"

#include "TestTank.h"

#include "MockTimerImpl.h"
#include "MockPinImpl.h"

class TestPumpController : public QObject
{
    Q_OBJECT

public:
    TestPumpController();
    ~TestPumpController();

private slots:
    void test0();
};

TestPumpController::TestPumpController()
{
}

TestPumpController::~TestPumpController()
{
}

void TestPumpController::test0()
{
    TestTank source;
    TestTank drain;
    Pump p(2);
    Timer t(1000);

    PumpController pc(&p, &source, &drain, &t);

    source.setStatus(Tank::Full);
    MockTimerImpl::setTime(0);

    if (source.isFull())
        t.start();

    QVERIFY(t.getRemainingTime() == 1000);

    MockTimerImpl::setTime(500);

    QVERIFY(t.getRemainingTime() == 1000);

    t.update();

    QVERIFY(t.getRemainingTime() == 500);

    MockTimerImpl::setTime(1500);

    t.update();

    QVERIFY(t.getRemainingTime() == 0);

    if (t.getRemainingTime() == 0)
        p.on();

    QVERIFY(MockPinImpl::getPin() == p.getPin());
    QVERIFY(MockPinImpl::getPinCurrentState());
}

QTEST_APPLESS_MAIN(TestPumpController)

#include "tst_pumpcontroller.moc"
