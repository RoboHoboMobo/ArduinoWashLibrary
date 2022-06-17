#include <QtTest>

#include "PumpController.h"

#include "TestNode.h"

#include "TestTank.h"

class TestPumpController : public QObject
{
    Q_OBJECT

public:
    TestPumpController();
    ~TestPumpController();

private slots:
    void testReverse000();
    void testReverse001();
    void testReverse010();
    void testReverse011();
    void testReverse100();
    void testReverse101();
    void testReverse110();
    void testReverse111();
};

TestPumpController::TestPumpController()
{
}

TestPumpController::~TestPumpController()
{
}

void TestPumpController::testReverse000()
{
    TestTank t0;
    TestTank t1;
    TestTank t2;
    TestTank t3;
    TestTank t4;

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    TestNode n0{&p01, &t0, &t1};
    TestNode n1{&p12, &t1, &t2};
    TestNode n2{&p23, &t2, &t3};
    TestNode n3{&p34, &t3, &t4};

    PumpController pc;
    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    n0.reset();
    n1.reset();
    n2.reset();
    n3.reset();

    n0.setGetState(Node::WaterIsReady);
    n0.setCanPumping(true);

    n1.setGetState(Node::WaterIsReady);
    n1.setCanPumping(true);

    n2.setGetState(Node::WaterIsReady);
    n2.setCanPumping(true);

    n3.setGetState(Node::WaterIsReady);
    n3.setCanPumping(true);

    pc.operate(true);

    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testReverse001()
{
    TestTank t0;
    TestTank t1;
    TestTank t2;
    TestTank t3;
    TestTank t4;

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    TestNode n0{&p01, &t0, &t1};
    TestNode n1{&p12, &t1, &t2};
    TestNode n2{&p23, &t2, &t3};
    TestNode n3{&p34, &t3, &t4};

    PumpController pc;
    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    n0.reset();
    n1.reset();
    n2.reset();
    n3.reset();

    n0.setGetState(Node::WaterIsReady);
    n0.setCanPumping(true);

    n1.setGetState(Node::WaterIsReady);
    n1.setCanPumping(true);

    n2.setGetState(Node::WaterIsReady);
    n2.setCanPumping(true);

    n3.setGetState(Node::PumpOn);
    n3.setCanPumping(true);

    pc.operate(true);

    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testReverse010()
{
    TestTank t0;
    TestTank t1;
    TestTank t2;
    TestTank t3;
    TestTank t4;

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    TestNode n0{&p01, &t0, &t1};
    TestNode n1{&p12, &t1, &t2};
    TestNode n2{&p23, &t2, &t3};
    TestNode n3{&p34, &t3, &t4};

    PumpController pc;
    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    n0.reset();
    n1.reset();
    n2.reset();
    n3.reset();

    n0.setGetState(Node::WaterIsReady);
    n0.setCanPumping(true);

    n1.setGetState(Node::WaterIsReady);
    n1.setCanPumping(true);

    n2.setGetState(Node::PumpOn);
    n2.setCanPumping(true);

    n3.setGetState(Node::WaterIsReady);
    n3.setCanPumping(true);

    pc.operate(true);

    QVERIFY(n1.getState() == Node::PumpOff);
    QVERIFY(n2.getState() == Node::PumpOn);
    QVERIFY(n3.getState() == Node::PumpOff);
}

void TestPumpController::testReverse011()
{
    TestTank t0;
    TestTank t1;
    TestTank t2;
    TestTank t3;
    TestTank t4;

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    TestNode n0{&p01, &t0, &t1};
    TestNode n1{&p12, &t1, &t2};
    TestNode n2{&p23, &t2, &t3};
    TestNode n3{&p34, &t3, &t4};

    PumpController pc;
    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    n0.reset();
    n1.reset();
    n2.reset();
    n3.reset();

    n0.setGetState(Node::WaterIsReady);
    n0.setCanPumping(true);

    n1.setGetState(Node::WaterIsReady);
    n1.setCanPumping(true);

    n2.setGetState(Node::PumpOn);
    n2.setCanPumping(true);

    n3.setGetState(Node::PumpOn);
    n3.setCanPumping(true);

    pc.operate(true);

    QVERIFY(n1.getState() == Node::PumpOff);
    QVERIFY(n2.getState() == Node::PumpOn);
    QVERIFY(n3.getState() == Node::PumpOff);
}

void TestPumpController::testReverse100()
{
    TestTank t0;
    TestTank t1;
    TestTank t2;
    TestTank t3;
    TestTank t4;

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    TestNode n0{&p01, &t0, &t1};
    TestNode n1{&p12, &t1, &t2};
    TestNode n2{&p23, &t2, &t3};
    TestNode n3{&p34, &t3, &t4};

    PumpController pc;
    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    n0.reset();
    n1.reset();
    n2.reset();
    n3.reset();

    n0.setGetState(Node::WaterIsReady);
    n0.setCanPumping(true);

    n1.setGetState(Node::PumpOn);
    n1.setCanPumping(true);

    n2.setGetState(Node::WaterIsReady);
    n2.setCanPumping(true);

    n3.setGetState(Node::WaterIsReady);
    n3.setCanPumping(true);

    pc.operate(true);

    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testReverse101()
{
    TestTank t0;
    TestTank t1;
    TestTank t2;
    TestTank t3;
    TestTank t4;

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    TestNode n0{&p01, &t0, &t1};
    TestNode n1{&p12, &t1, &t2};
    TestNode n2{&p23, &t2, &t3};
    TestNode n3{&p34, &t3, &t4};

    PumpController pc;
    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    n0.reset();
    n1.reset();
    n2.reset();
    n3.reset();

    n0.setGetState(Node::WaterIsReady);
    n0.setCanPumping(true);

    n1.setGetState(Node::PumpOn);
    n1.setCanPumping(true);

    n2.setGetState(Node::WaterIsReady);
    n2.setCanPumping(true);

    n3.setGetState(Node::PumpOn);
    n3.setCanPumping(true);

    pc.operate(true);

    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::PumpOn);
}

void TestPumpController::testReverse110()
{
    TestTank t0;
    TestTank t1;
    TestTank t2;
    TestTank t3;
    TestTank t4;

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    TestNode n0{&p01, &t0, &t1};
    TestNode n1{&p12, &t1, &t2};
    TestNode n2{&p23, &t2, &t3};
    TestNode n3{&p34, &t3, &t4};

    PumpController pc;
    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    n0.reset();
    n1.reset();
    n2.reset();
    n3.reset();

    n0.setGetState(Node::WaterIsReady);
    n0.setCanPumping(true);

    n1.setGetState(Node::PumpOn);
    n1.setCanPumping(true);

    n2.setGetState(Node::PumpOn);
    n2.setCanPumping(true);

    n3.setGetState(Node::WaterIsReady);
    n3.setCanPumping(true);

    pc.operate(true);

    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::PumpOff);
}

void TestPumpController::testReverse111()
{
    TestTank t0;
    TestTank t1;
    TestTank t2;
    TestTank t3;
    TestTank t4;

    Pump p01(0);
    Pump p12(1);
    Pump p23(2);
    Pump p34(3);

    TestNode n0{&p01, &t0, &t1};
    TestNode n1{&p12, &t1, &t2};
    TestNode n2{&p23, &t2, &t3};
    TestNode n3{&p34, &t3, &t4};

    PumpController pc;
    pc.pushBack(&n0);
    pc.pushBack(&n1);
    pc.pushBack(&n2);
    pc.pushBack(&n3);

    n0.reset();
    n1.reset();
    n2.reset();
    n3.reset();

    n0.setGetState(Node::WaterIsReady);
    n0.setCanPumping(true);

    n1.setGetState(Node::PumpOn);
    n1.setCanPumping(true);

    n2.setGetState(Node::PumpOn);
    n2.setCanPumping(true);

    n3.setGetState(Node::PumpOn);
    n3.setCanPumping(true);

    pc.operate(true);

    QVERIFY(n1.getState() == Node::PumpOn);
    QVERIFY(n2.getState() == Node::PumpOff);
    QVERIFY(n3.getState() == Node::PumpOff);
}

QTEST_APPLESS_MAIN(TestPumpController)

#include "tst_pumpcontroller.moc"
