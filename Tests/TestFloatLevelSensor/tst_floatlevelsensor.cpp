#include <QtTest>

#include "Sensors.h"

#include "MockArduinoButtonImpl.h"

class TestFloatLevelSensor : public QObject
{
    Q_OBJECT

public:
    TestFloatLevelSensor();
    ~TestFloatLevelSensor();

private slots:
    void test0();
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

    MockArduinoButtonImpl::setIsButtonHold(true);

    QCOMPARE(s.getPin(), 123u);
    QVERIFY(s.getData());
}

QTEST_APPLESS_MAIN(TestFloatLevelSensor)

#include "tst_floatlevelsensor.moc"
