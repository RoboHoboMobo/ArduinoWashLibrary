#include <QtTest>

#include "Pump.h"

// #include "MockPumpImpl.h"

class TestPump : public QObject
{
    Q_OBJECT

public:
    TestPump();
    ~TestPump();

private slots:
};

TestPump::TestPump()
{
}

TestPump::~TestPump()
{
}

QTEST_APPLESS_MAIN(TestPump)

#include "tst_pump.moc"
