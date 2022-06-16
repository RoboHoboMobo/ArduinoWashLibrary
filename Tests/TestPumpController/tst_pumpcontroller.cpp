#include <QtTest>

#include "Node.h"

#include "TestTank.h"

#include "MockTimerImpl.h"
#include "MockPinImpl.h"

class TestPumpController : public QObject
{
    Q_OBJECT

public:
    TestPumpController();
    ~TestPumpController();

private slots:
};

TestPumpController::TestPumpController()
{
}

TestPumpController::~TestPumpController()
{
}

QTEST_APPLESS_MAIN(TestPumpController)

#include "tst_pumpcontroller.moc"
