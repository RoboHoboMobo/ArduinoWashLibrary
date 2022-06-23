#include <QtTest>

#include "TankHelpers.h"

#include "TestTank.h"

class TestTankHelpers : public QObject
{
    Q_OBJECT

public:
    TestTankHelpers();
    ~TestTankHelpers();

private slots:
    void test0();
};

TestTankHelpers::TestTankHelpers()
{
}

TestTankHelpers::~TestTankHelpers()
{
}

void TestTankHelpers::test0()
{
    TestTank t;

    t.setSensorsData({0, 0, 0, 0});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 0u);

    t.setSensorsData({1, 0, 0, 0});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 1u);

    t.setSensorsData({0, 1, 0, 0});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 2u);

    t.setSensorsData({1, 1, 0, 0});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 3u);

    t.setSensorsData({0, 0, 1, 0});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 4u);

    t.setSensorsData({1, 0, 1, 0});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 5u);

    t.setSensorsData({0, 1, 1, 0});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 6u);

    t.setSensorsData({1, 1, 1, 0});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 7u);

    t.setSensorsData({0, 0, 0, 1});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 8u);

    t.setSensorsData({1, 0, 0, 1});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 9u);

    t.setSensorsData({0, 1, 0, 1});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 10u);

    t.setSensorsData({1, 1, 0, 1});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 11u);

    t.setSensorsData({0, 0, 1, 1});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 12u);

    t.setSensorsData({1, 0, 1, 1});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 13u);

    t.setSensorsData({0, 1, 1, 1});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 14u);

    t.setSensorsData({1, 1, 1, 1});

    QCOMPARE(getFloatLevelSensorsDataMask(t), 15u);
}

QTEST_APPLESS_MAIN(TestTankHelpers)

#include "tst_tankhelpers.moc"
