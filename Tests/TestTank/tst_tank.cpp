#include <QtTest>

#include "TestTank.h"

#include "MockSensors.h"

class TestTestTank : public QObject
{
    Q_OBJECT

public:
    TestTestTank();
    ~TestTestTank();

private slots:
    void testGetLevelSensor();
    void testGetLevelSensors();
    void testGetStatus();
};

TestTestTank::TestTestTank()
{
}

TestTestTank::~TestTestTank()
{
}

void TestTestTank::testGetLevelSensor()
{
    TestTank t(123, 0);

    const Sensor* result = t.getLevelSensor(0);

    QCOMPARE(result->getPin(), 123u);

    result = t.getLevelSensor(1);

    QCOMPARE(result->getPin(), 0u);

    result = t.getLevelSensor(2);

    QVERIFY(!result);
}

void TestTestTank::testGetLevelSensors()
{
    TestTank t(123, 0);

    Sensor** result = t.getLevelSensors();

    QVERIFY(result);
    QVERIFY(result[0]);
    QCOMPARE(result[0]->getPin(), 123u);
    QVERIFY(result[1]);
    QCOMPARE(result[1]->getPin(), 0u);
}

void TestTestTank::testGetStatus()
{
    TestTank t(123, 0);

    MockSensors::setFloatLevelSensorsData({false, false});

    QCOMPARE(t.getStatus(), Tank::Empty);

    MockSensors::setFloatLevelSensorsData({true, false});

    QCOMPARE(t.getStatus(), Tank::NotFull);

    MockSensors::setFloatLevelSensorsData({true, true});

    QCOMPARE(t.getStatus(), Tank::Full);

    MockSensors::setFloatLevelSensorsData({false, true});

    QCOMPARE(t.getStatus(), Tank::Error);
}

QTEST_APPLESS_MAIN(TestTestTank)

#include "tst_tank.moc"
