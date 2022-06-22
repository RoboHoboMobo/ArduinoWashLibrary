#include "TestTank.h"

namespace {
TestSensor s0{0};
TestSensor s1{123};
TestSensor s2{1};
const uint8_t levelSensorsNum{3};
Sensor* sensors[levelSensorsNum] = {&s0, &s1, &s2};
}

Sensor* TestTank::getLevelSensor(uint8_t number)
{
    if (number >= levelSensorsNum)
        return nullptr;

    if (number == 0)
        return &s0;
    else if (number == 1)
        return &s1;
    else if (number == 2)
        return &s2;

    return nullptr;
}

Sensor** TestTank::getLevelSensors()
{
    return sensors;
}

uint8_t TestTank::getLevelSensorsNum() const
{
    return levelSensorsNum;
}

Sensor* TestTank::getLowerLevelSensor()
{
    return &s0;
}

Sensor* TestTank::getUpperLevelSensor()
{
    return &s2;
}

Tank::Status TestTank::getStatus()
{
    return m_status;
}

void TestTank::setStatus(Tank::Status s)
{
    m_status = s;
}

void TestTank::setIsDrainable(bool flag)
{
    m_isDrainable = flag;
}

void TestTank::setIsFillable(bool flag)
{
    m_isFillable = flag;
}

bool TestTank::isDrainable()
{
    return m_isDrainable;
}

bool TestTank::isFillable()
{
    return m_isFillable;
}

bool TestTank::isNeedEmergencyPumping()
{
    return {};
}
