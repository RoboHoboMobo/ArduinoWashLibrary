#include "TestTank.h"

namespace {
TestSensor s0{0};
TestSensor s1{123};
TestSensor s2{1};
uint8_t levelSensorsNum{3};
Tank::Status status{};
}

bool Tank::isFull()
{
    return getStatus() == Full;
}

void Tank::update()
{
    uint8_t n = getLevelSensorsNum();

    for (uint8_t i = 0; i < n; ++i)
        getLevelSensor(i)->update();
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
    return status;
}

void TestTank::setStatus(Tank::Status s)
{
    status = s;
}
