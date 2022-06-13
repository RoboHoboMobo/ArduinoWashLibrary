#include <QtTest>

#include "Sensors.h"

#include "MockSensorsImpl.h"

class TestFloatLevelSensor : public QObject
{
    Q_OBJECT

public:
    TestFloatLevelSensor();
    ~TestFloatLevelSensor();

private slots:
    void test0();
    void getData();
    void update();
};

TestFloatLevelSensor::TestFloatLevelSensor()
{
}

TestFloatLevelSensor::~TestFloatLevelSensor()
{
}

void TestFloatLevelSensor::test0()
{
    FloatLevelSensor s(123);

    QCOMPARE(s.getPin(), 123u);
}

void TestFloatLevelSensor::getData()
{
    FloatLevelSensor s(123);

    MockSensorsImpl::setFloatLevelSensorData(true);

    QVERIFY(s.getData());
}

void TestFloatLevelSensor::update()
{
    FloatLevelSensor s(123);

    s.update();

    QVERIFY(MockSensorsImpl::isUpdated());
}

QTEST_APPLESS_MAIN(TestFloatLevelSensor)

#include "tst_floatlevelsensor.moc"
