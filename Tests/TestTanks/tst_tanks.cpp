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
    void getLevelSensorsNum();
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
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor* s[] = {&s0, &s1};

    Cube c(reinterpret_cast<Sensor**>(s));

    QCOMPARE(c.getLevelSensorsNum(), 0u);
    QVERIFY(!c.getLevelSensor(0));
}

void TestTanks::getLevelSensorIfNotNull()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor* s[] = {&s0, &s1};

    Cube c(reinterpret_cast<Sensor**>(s), 2);

    auto result = static_cast<TestSensor*>(c.getLevelSensor(1));

    QCOMPARE(c.getLevelSensorsNum(), 2u);
    QCOMPARE(result, s[1]);
    QCOMPARE(result->getPin(), s[1]->getPin());
}

void TestTanks::getLevelSensorsNum()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor* s[] = {&s0, &s1};

    Cube c(reinterpret_cast<Sensor**>(s), 2);

    QCOMPARE(c.getLevelSensorsNum(), 2u);
}

void TestTanks::getStatusIfNoSensors()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor* s[] = {&s0, &s1};

    Cube c(reinterpret_cast<Sensor**>(s), 0);

    QCOMPARE(c.getLevelSensorsNum(), 0u);
    QCOMPARE(c.getStatus(), Tank::Status::Error);
}

void TestTanks::getStatusIfOneSensor()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    s[0]->setData(true);

    Cube c(reinterpret_cast<Sensor**>(s), 1);

    QCOMPARE(c.getLevelSensorsNum(), 1u);
    QCOMPARE(c.getStatus(), Tank::Status::Full);
}

void TestTanks::getStatusIfNoSensorsActivated()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    Cube c(reinterpret_cast<Sensor**>(s), 3);

    QCOMPARE(c.getLevelSensorsNum(), 3u);
    QCOMPARE(c.getStatus(), Tank::Status::NotFull);
}

void TestTanks::getStatusIfOnlyMidSensorIsActivated()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    s[1]->setData(true);

    Cube c(reinterpret_cast<Sensor**>(s), 3);

    QCOMPARE(c.getLevelSensorsNum(), 3u);
    QCOMPARE(c.getStatus(), Tank::Status::Error);
}

void TestTanks::getStatusIfAllSensorsActivated()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    s[0]->setData(true);
    s[1]->setData(true);
    s[2]->setData(true);

    Cube c(reinterpret_cast<Sensor**>(s), 3);

    QCOMPARE(c.getLevelSensorsNum(), 3u);
    QCOMPARE(c.getStatus(), Tank::Status::Full);
}

void TestTanks::getLowerSensorIfNull()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    Cube c(reinterpret_cast<Sensor**>(s));

    QCOMPARE(c.getLevelSensorsNum(), 0u);
    QVERIFY(!c.getLowerLevelSensor());
}

void TestTanks::getLowerSensor()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    Cube c(reinterpret_cast<Sensor**>(s), 3);

    QCOMPARE(c.getLevelSensorsNum(), 3u);

    Sensor* result = c.getLowerLevelSensor();

    QCOMPARE(result, s[0]);
    QCOMPARE(result->getPin(), s[0]->getPin());
}

void TestTanks::getUpperSensorIfNull()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    Cube c(reinterpret_cast<Sensor**>(s));

    QCOMPARE(c.getLevelSensorsNum(), 0u);

    Sensor* result = c.getUpperLevelSensor();

    QVERIFY(!result);
}

void TestTanks::getUpperSensor()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    Cube c(reinterpret_cast<Sensor**>(s), 3);

    QCOMPARE(c.getLevelSensorsNum(), 3u);

    auto result = static_cast<TestSensor*>(c.getUpperLevelSensor());

    QCOMPARE(result, s[2]);
    QCOMPARE(result->getPin(), s[2]->getPin());
}

void TestTanks::isFullIfNotFull()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    Cube c(reinterpret_cast<Sensor**>(s), 3);

    QCOMPARE(c.getLevelSensorsNum(), 3u);
    QVERIFY(!c.isFull());
}

void TestTanks::isFullIfError()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    Cube c(reinterpret_cast<Sensor**>(s));

    QCOMPARE(c.getLevelSensorsNum(), 0u);
    QVERIFY(!c.isFull());
}

void TestTanks::isFullIfFull()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};
    s[0]->setData(true);
    s[1]->setData(true);
    s[2]->setData(true);

    Cube c(reinterpret_cast<Sensor**>(s), 3);

    QCOMPARE(c.getLevelSensorsNum(), 3u);
    QVERIFY(c.isFull());
}

void TestTanks::testUpdate()
{
    TestSensor s0(1);
    TestSensor s1(123);
    TestSensor s2(0);
    TestSensor* s[] = {&s0, &s1, &s2};

    Cube c(reinterpret_cast<Sensor**>(s), 3);

    QCOMPARE(c.getLevelSensorsNum(), 3u);

    c.update();

    QVERIFY(s[0]->isUpdated() && s[1]->isUpdated() && s[2]->isUpdated());
}

QTEST_APPLESS_MAIN(TestTanks)

#include "tst_tanks.moc"
