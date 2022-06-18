#include <QtTest>

#include "PumpController.h"

#include "TestTank.h"

#include "MockTimer.h"

class TestPumpController : public QObject
{
    Q_OBJECT

public:
    TestPumpController();
    ~TestPumpController();

private slots:
    void testForward1000();
    void testForward1001();
    void testForward1010();
    void testForward1011();
    void testForward1100();
    void testForward1101();
    void testForward1110();
    void testForward1111();

    void testReverse0000();
    void testReverse0001();
    void testReverse0010();
    void testReverse0011();
    void testReverse0100();
    void testReverse0101();
    void testReverse0110();
    void testReverse0111();
};

TestPumpController::TestPumpController()
{
}

TestPumpController::~TestPumpController()
{
}

void TestPumpController::testForward1000()
{
    PumpController pc;

    TestTank tank0;

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    p01.on();

    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    Timer t0(999);
    Timer t1(0);
    Timer t2(0);
    Timer t3(0);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate();

    QVERIFY(n0.getState() == Node::PumpOn);
    QVERIFY(n1.getState() == Node::WaterIsReady);
    QVERIFY(n2.getState() == Node::PumpOn);
    QVERIFY(n3.getState() == Node::WaterIsReady);
}

void TestPumpController::testForward1001()
{
    PumpController pc;

    TestTank tank0;

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    p01.on();

    Pump p12(1);
    Pump p23(2);
    Pump p34(3);
    p34.on();

    Timer t0(999);
    Timer t1(0);
    Timer t2(0);
    Timer t3(999);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate();

    QVERIFY(n0.getState() == Node::PumpOn);
    QVERIFY(n1.getState() == Node::WaterIsReady);
    QVERIFY(n2.getState() == Node::PumpOn);
    QVERIFY(n3.getState() == Node::PumpOff);
}

void TestPumpController::testForward1010()
{
    PumpController pc;

    TestTank tank0;

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    p01.on();

    Pump p12(1);

    Pump p23(2);
    p23.on();

    Pump p34(3);

    Timer t0(999);
    Timer t1(0);
    Timer t2(999);
    Timer t3(0);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate();

    QVERIFY(n0.getState() == Node::PumpOn);
    QVERIFY(n1.getState() == Node::WaterIsReady);
    QVERIFY(n2.getState() == Node::PumpOn);
    QVERIFY(n3.getState() == Node::WaterIsReady);
}

void TestPumpController::testForward1011()
{
    PumpController pc;

    TestTank tank0;

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    p01.on();

    Pump p12(1);

    Pump p23(2);
    p23.on();

    Pump p34(3);
    p34.on();

    Timer t0(999);
    Timer t1(0);
    Timer t2(999);
    Timer t3(999);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate();

    QVERIFY(n0.getState() == Node::PumpOn);
    QVERIFY(n1.getState() == Node::WaterIsReady);
    QVERIFY(n2.getState() == Node::PumpOn);
    QVERIFY(n3.getState() == Node::PumpOff);
}

void TestPumpController::testForward1100()
{
    PumpController pc;

    TestTank tank0;

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    p01.on();

    Pump p12(1);
    p12.on();

    Pump p23(2);
    Pump p34(3);

    Timer t0(999);
    Timer t1(999);
    Timer t2(0);
    Timer t3(0);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate();

    QVERIFY(n0.getState() == Node::PumpOn);
    QVERIFY(n1.getState() == Node::PumpOff);
    QVERIFY(n2.getState() == Node::WaterIsReady);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testForward1101()
{
    PumpController pc;

    TestTank tank0;

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    p01.on();

    Pump p12(1);
    p12.on();

    Pump p23(2);
    Pump p34(3);
    p34.on();

    Timer t0(999);
    Timer t1(999);
    Timer t2(0);
    Timer t3(999);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate();

    QVERIFY(n0.getState() == Node::PumpOn);
    QVERIFY(n1.getState() == Node::PumpOff);
    QVERIFY(n2.getState() == Node::WaterIsReady);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testForward1110()
{
    PumpController pc;

    TestTank tank0;

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    p01.on();

    Pump p12(1);
    p12.on();

    Pump p23(2);
    p23.on();

    Pump p34(3);

    Timer t0(999);
    Timer t1(999);
    Timer t2(999);
    Timer t3(000);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate();

    QVERIFY(n0.getState() == Node::PumpOn);
    QVERIFY(n1.getState() == Node::PumpOff);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::WaterIsReady);
}

void TestPumpController::testForward1111()
{
    PumpController pc;

    TestTank tank0;

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    p01.on();

    Pump p12(1);
    p12.on();

    Pump p23(2);
    p23.on();

    Pump p34(3);
    p34.on();

    Timer t0(999);
    Timer t1(999);
    Timer t2(999);
    Timer t3(999);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate();

    QVERIFY(n0.getState() == Node::PumpOn);
    QVERIFY(n1.getState() == Node::PumpOff);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::PumpOff);
}

void TestPumpController::testReverse0000()
{
    PumpController pc;

    TestTank tank0;
    tank0.setIsDrainable(true);
    tank0.setIsFillable(true);

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    Timer t0(0);
    Timer t1(0);
    Timer t2(0);
    Timer t3(0);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate(true);

    QVERIFY(n0.getState() == Node::WaterIsReady);
    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::WaterIsReady);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testReverse0001()
{
    PumpController pc;

    TestTank tank0;
    tank0.setIsDrainable(true);
    tank0.setIsFillable(true);

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);
    p34.on();

    Timer t0(0);
    Timer t1(0);
    Timer t2(0);
    Timer t3(999);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate(true);

    QVERIFY(n0.getState() == Node::WaterIsReady);
    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::WaterIsReady);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testReverse0010()
{
    PumpController pc;

    TestTank tank0;
    tank0.setIsDrainable(true);
    tank0.setIsFillable(true);

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    p23.on();

    Pump p34(3);

    Timer t0(0);
    Timer t1(0);
    Timer t2(999);
    Timer t3(0);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate(true);

    QVERIFY(n0.getState() == Node::WaterIsReady);
    QVERIFY(n1.getState() == Node::WaterIsReady);
    QVERIFY(n2.getState() == Node::PumpOn);
    QVERIFY(n3.getState() == Node::WaterIsReady);
}

void TestPumpController::testReverse0011()
{
    PumpController pc;

    TestTank tank0;
    tank0.setIsDrainable(true);
    tank0.setIsFillable(true);

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    p23.on();

    Pump p34(3);
    p34.on();

    Timer t0(0);
    Timer t1(0);
    Timer t2(999);
    Timer t3(999);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate(true);

    QVERIFY(n0.getState() == Node::WaterIsReady);
    QVERIFY(n1.getState() == Node::WaterIsReady);
    QVERIFY(n2.getState() == Node::PumpOn);
    QVERIFY(n3.getState() == Node::PumpOff);
}

void TestPumpController::testReverse0100()
{
    PumpController pc;

    TestTank tank0;
    tank0.setIsDrainable(true);
    tank0.setIsFillable(true);

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    Pump p12(1);
    p12.on();

    Pump p23(2);
    Pump p34(3);

    Timer t0(0);
    Timer t1(999);
    Timer t2(0);
    Timer t3(0);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate(true);

    QVERIFY(n0.getState() == Node::WaterIsReady);
    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::WaterIsReady);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testReverse0101()
{
    PumpController pc;

    TestTank tank0;
    tank0.setIsDrainable(true);
    tank0.setIsFillable(true);

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    Pump p12(1);
    p12.on();

    Pump p23(2);
    Pump p34(3);
    p34.on();

    Timer t0(0);
    Timer t1(999);
    Timer t2(0);
    Timer t3(999);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate(true);

    QVERIFY(n0.getState() == Node::WaterIsReady);
    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::WaterIsReady);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testReverse0110()
{
    PumpController pc;

    TestTank tank0;
    tank0.setIsDrainable(true);
    tank0.setIsFillable(true);

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    Pump p12(1);
    p12.on();

    Pump p23(2);
    p23.on();

    Pump p34(3);

    Timer t0(0);
    Timer t1(999);
    Timer t2(999);
    Timer t3(0);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate(true);

    QVERIFY(n0.getState() == Node::WaterIsReady);
    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::WaterIsReady);
}

void TestPumpController::testReverse0111()
{
    PumpController pc;

    TestTank tank0;
    tank0.setIsDrainable(true);
    tank0.setIsFillable(true);

    TestTank tank1;
    tank1.setIsDrainable(true);
    tank1.setIsFillable(true);

    TestTank tank2;
    tank2.setIsDrainable(true);
    tank2.setIsFillable(true);

    TestTank tank3;
    tank3.setIsDrainable(true);
    tank3.setIsFillable(true);

    TestTank tank4;
    tank4.setIsDrainable(true);
    tank4.setIsFillable(true);

    Pump p01(0);
    Pump p12(1);
    p12.on();

    Pump p23(2);
    p23.on();

    Pump p34(3);
    p34.on();

    Timer t0(0);
    Timer t1(999);
    Timer t2(999);
    Timer t3(999);

    Node n0{&p01, &tank0, &tank1, &t0};
    Node n1{&p12, &tank1, &tank2, &t1};
    Node n2{&p23, &tank2, &tank3, &t2};
    Node n3{&p34, &tank3, &tank4, &t3};

    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    pc.operate(true);

    QVERIFY(n0.getState() == Node::WaterIsReady);
    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::PumpOff);
}

QTEST_APPLESS_MAIN(TestPumpController)

#include "tst_pumpcontroller.moc"
