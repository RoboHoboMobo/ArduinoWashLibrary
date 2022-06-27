#include <QtTest>

#include "Pump.h"

#include "MockPinImpl.h"

class TestPump : public QObject
{
    Q_OBJECT

public:
    TestPump();
    ~TestPump();

private slots:
    void initPump();
    void switchFromOffToOff();
    void switchFromOffToOn();
    void switchFromOnToOff();
    void switchFromOnToOn();

    void switchOffManualPump();
    void switchOnManualPump();
};

TestPump::TestPump()
{
}

TestPump::~TestPump()
{
}

void TestPump::initPump()
{
    MockPinImpl::reset();

    Pump p(123);

    QCOMPARE(p.getPin(), 123u);

    QCOMPARE(MockPinImpl::getPin(), 123u);
    QVERIFY(!MockPinImpl::getPinCurrentState());
}

void TestPump::switchFromOffToOff()
{
    MockPinImpl::reset();

    Pump p(123, false);

    p.off();

    QCOMPARE(p.getPin(), 123u);
    QVERIFY(!p.isOn());

    QCOMPARE(MockPinImpl::getPin(), p.getPin());
    QVERIFY(!MockPinImpl::getPinCurrentState());
}

void TestPump::switchFromOffToOn()
{
    MockPinImpl::reset();

    Pump p(123, false);

    p.on();

    QCOMPARE(p.getPin(), 123u);
    QVERIFY(p.isOn());

    QCOMPARE(MockPinImpl::getPin(), p.getPin());
    QVERIFY(MockPinImpl::getPinCurrentState());
}

void TestPump::switchFromOnToOff()
{
    MockPinImpl::reset();

    Pump p(123, true);

    p.off();

    QCOMPARE(p.getPin(), 123u);
    QVERIFY(!p.isOn());

    QCOMPARE(MockPinImpl::getPin(), p.getPin());
    QVERIFY(!MockPinImpl::getPinCurrentState());
}

void TestPump::switchFromOnToOn()
{
    MockPinImpl::reset();

    Pump p(123, true);

    p.on();

    QCOMPARE(p.getPin(), 123u);
    QVERIFY(p.isOn());

    QCOMPARE(MockPinImpl::getPin(), p.getPin());
    QVERIFY(MockPinImpl::getPinCurrentState());
}

void TestPump::switchOffManualPump()
{
    MockPinImpl::reset();

    Pump p;

    p.off();

    QCOMPARE(p.getPin(), 0u);
    QVERIFY(!p.isOn());

    QVERIFY(!MockPinImpl::getPinCurrentState());
}

void TestPump::switchOnManualPump()
{
    MockPinImpl::reset();

    Pump p;

    p.on();

    QCOMPARE(p.getPin(), 0u);
    QVERIFY(p.isOn());

    QVERIFY(!MockPinImpl::getPinCurrentState());
}

QTEST_APPLESS_MAIN(TestPump)

#include "tst_pump.moc"
