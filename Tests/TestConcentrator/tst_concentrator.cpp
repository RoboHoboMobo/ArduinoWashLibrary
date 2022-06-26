#include <QtTest>

#include "Concentrator.h"

#include "MockSensors.h"

class TestConcentrator : public QObject
{
    Q_OBJECT

public:
    TestConcentrator();
    ~TestConcentrator();

private slots:
    void testGetLevelSensor();
    void testGetStatusIfEmpty();
    void testGetStatusIfNotFull();
    void testGetStatusIfFull();
    void testGetStatusIfError();
    void testIsNeedEmergencyPumpingIfEmpty();
    void testIsNeedEmergencyPumpingIfNotEmpty();
};

TestConcentrator::TestConcentrator()
{
}

TestConcentrator::~TestConcentrator()
{
}

void TestConcentrator::testGetLevelSensor()
{
    const uint8_t pins[] = {0, 123, 1, 2};

    Concentrator c({0, 123, 1, 2});

    Sensor* result = c.getLevelSensor(0);

    QVERIFY(result);
    QCOMPARE(result->getPin(), 0);

    result = c.getLevelSensor(1);

    QVERIFY(result);
    QCOMPARE(result->getPin(), 123);

    result = c.getLevelSensor(2);

    QVERIFY(result);
    QCOMPARE(result->getPin(), 1);

    result = c.getLevelSensor(3);

    QVERIFY(result);
    QCOMPARE(result->getPin(), 2);

    result = c.getLevelSensor(4);

    QVERIFY(!result);
}

void TestConcentrator::testGetStatusIfEmpty()
{
    const uint8_t pins[] = {0, 123, 1, 2};

    Concentrator c(pins);

    MockSensors::setFloatLevelSensorsData({0, 0, 0, 0});

    Tank::Status result = c.getStatus();

    QVERIFY(result == Tank::Empty);
}

void TestConcentrator::testGetStatusIfNotFull()
{
    const uint8_t pins[] = {0, 123, 1, 2};

    Concentrator c(pins);

    MockSensors::setFloatLevelSensorsData({1, 0, 0, 0});

    Tank::Status result = c.getStatus();

    QVERIFY(result == Tank::NotFull);

    MockSensors::setFloatLevelSensorsData({1, 1, 0, 0});

    result = c.getStatus();

    QVERIFY(result == Tank::NotFull);

    MockSensors::setFloatLevelSensorsData({1, 1, 1, 0});

    result = c.getStatus();

    QVERIFY(result == Tank::NotFull);
}

void TestConcentrator::testGetStatusIfFull()
{
    const uint8_t pins[] = {0, 123, 1, 2};

    Concentrator c(pins);

    MockSensors::setFloatLevelSensorsData({1, 1, 1, 1});

    Tank::Status result = c.getStatus();

    QVERIFY(result == Tank::Full);
}

void TestConcentrator::testGetStatusIfError()
{
    const uint8_t pins[] = {0, 123, 1, 2};

    Concentrator c(pins);

    MockSensors::setFloatLevelSensorsData({0, 1, 0, 0});

    Tank::Status result = c.getStatus();

    QVERIFY(result == Tank::Error);
}

void TestConcentrator::testIsNeedEmergencyPumpingIfEmpty()
{
    const uint8_t pins[] = {0, 123, 1, 2};

    Concentrator c(pins);

    MockSensors::setFloatLevelSensorsData({1, 0, 0, 0});

    QVERIFY(c.isNeedEmergencyPumping());
}

void TestConcentrator::testIsNeedEmergencyPumpingIfNotEmpty()
{
    const uint8_t pins[] = {0, 123, 1, 2};

    Concentrator c(pins);

    MockSensors::setFloatLevelSensorsData({1, 1, 0, 0});

    QVERIFY(!c.isNeedEmergencyPumping());
}

QTEST_APPLESS_MAIN(TestConcentrator)

#include "tst_concentrator.moc"
