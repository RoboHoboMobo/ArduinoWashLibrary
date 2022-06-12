#include <QtTest>

#include "Tanks.h"

#include "TestSensor.h"

class TestTanks : public QObject
{
    Q_OBJECT

public:
    TestTanks();
    ~TestTanks();

private slots:
    void getLevelSensorIfNull();
    void getLevelSensorIfNotNull();
    void getSensorsNum();
    void getStatusIfNoSensors();
    void getStatusIfOneSensor();
    void getStatusIfNoSensorsActivated();
    void getStatusIfOnlyMidSensorIsActivated();
    void getStatusIfAllSensorsActivated();
    void getLowerSensorIfNull();
    void getLowerSensor();
    void getUpperSensorIfNull();
    void getUpperSensor();
    void isFullIfNotFull();
    void isFullIfError();
    void isFullIfFull();
    void testUpdate();
};

TestTanks::TestTanks()
{
}

TestTanks::~TestTanks()
{
}

void TestTanks::getLevelSensorIfNull()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123)};

    Tank<TestSensor> t(s);

    QCOMPARE(t.getSensorsNum(), 0u);
    QCOMPARE(t.getLevelSensor(0), nullptr);
}

void TestTanks::getLevelSensorIfNotNull()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123)};

    Tank<TestSensor, 2> t(s);

    TestSensor* result = t.getLevelSensor(1);

    QCOMPARE(t.getSensorsNum(), 2u);
    QCOMPARE(result, s + 1);
    QCOMPARE(result->getPin(), s[1].getPin());
}

void TestTanks::getSensorsNum()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123)};

    Tank<TestSensor, 2> t(s);

    QCOMPARE(t.getSensorsNum(), 2u);
}

void TestTanks::getStatusIfNoSensors()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 0> t(s);

    QCOMPARE(t.getSensorsNum(), 0u);
    QCOMPARE(t.getStatus(), TankStatus::Error);
}

void TestTanks::getStatusIfOneSensor()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};
    s[0].setData(true);

    Tank<TestSensor, 1> t(s);

    QCOMPARE(t.getSensorsNum(), 1u);
    QCOMPARE(t.getStatus(), TankStatus::Full);
}

void TestTanks::getStatusIfNoSensorsActivated()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 3> t(s);

    QCOMPARE(t.getSensorsNum(), 3u);
    QCOMPARE(t.getStatus(), TankStatus::NotFull);
}

void TestTanks::getStatusIfOnlyMidSensorIsActivated()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};
    s[1].setData(true);

    Tank<TestSensor, 3> t(s);

    QCOMPARE(t.getSensorsNum(), 3u);
    QCOMPARE(t.getStatus(), TankStatus::Error);
}

void TestTanks::getStatusIfAllSensorsActivated()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};
    s[0].setData(true);
    s[1].setData(true);
    s[2].setData(true);

    Tank<TestSensor, 3> t(s);

    QCOMPARE(t.getSensorsNum(), 3u);
    QCOMPARE(t.getStatus(), TankStatus::Full);
}

void TestTanks::getLowerSensorIfNull()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 0> t(s);

    QCOMPARE(t.getSensorsNum(), 0u);

    TestSensor* result = t.getLowerLevelSensor();

    QCOMPARE(result, nullptr);
}

void TestTanks::getLowerSensor()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 3> t(s);

    QCOMPARE(t.getSensorsNum(), 3u);

    TestSensor* result = t.getLowerLevelSensor();

    QCOMPARE(result, s);
    QCOMPARE(result->getPin(), s[0].getPin());
}

void TestTanks::getUpperSensorIfNull()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 0> t(s);

    QCOMPARE(t.getSensorsNum(), 0u);

    TestSensor* result = t.getUpperLevelSensor();

    QCOMPARE(result, nullptr);
}

void TestTanks::getUpperSensor()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 3> t(s);

    QCOMPARE(t.getSensorsNum(), 3u);

    TestSensor* result = t.getUpperLevelSensor();

    QCOMPARE(result, s + 2);
    QCOMPARE(result->getPin(), s[2].getPin());
}

void TestTanks::isFullIfNotFull()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 3> t(s);

    QCOMPARE(t.getSensorsNum(), 3u);
    QVERIFY(!t.isFull());
}

void TestTanks::isFullIfError()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 0> t(s);

    QCOMPARE(t.getSensorsNum(), 0u);
    QVERIFY(!t.isFull());
}

void TestTanks::isFullIfFull()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};
    s[0].setData(true);
    s[1].setData(true);
    s[2].setData(true);

    Tank<TestSensor, 3> t(s);

    QCOMPARE(t.getSensorsNum(), 3u);
    QVERIFY(t.isFull());
}

void TestTanks::testUpdate()
{
    TestSensor s[] = {TestSensor(1), TestSensor(123), TestSensor(0)};

    Tank<TestSensor, 3> t(s);

    QCOMPARE(t.getSensorsNum(), 3u);

    t.update();

    QVERIFY(s[0].isUpdated() && s[1].isUpdated() && s[2].isUpdated());
}

QTEST_APPLESS_MAIN(TestTanks)

#include "tst_tanks.moc"
