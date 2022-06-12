#include <QtTest>

#include "Sensors.h"

#include "MockSensorsImpl.tpp"

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
    FloatLevelSensor<123> s;

    QCOMPARE(s.getPin(), 123u);
}

void TestFloatLevelSensor::getData()
{
    FloatLevelSensor<123> s;

    MockSensorsImpl::setFloatLevelSensorData(true);

    QVERIFY(s.getData());
}

void TestFloatLevelSensor::update()
{
    FloatLevelSensor<123> s;

    s.update();

    QVERIFY(MockSensorsImpl::isUpdated());
}

QTEST_APPLESS_MAIN(TestFloatLevelSensor)

#include "tst_floatlevelsensor.moc"
