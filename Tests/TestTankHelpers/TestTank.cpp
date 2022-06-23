#include "TestTank.h"

TestTank::TestTank()
    : m_s0(0)
    , m_s1(123)
    , m_s2(1)
    , m_s3(2)
    , m_sensors{}
{
    m_sensors[0] = &m_s0;
    m_sensors[1] = &m_s1;
    m_sensors[2] = &m_s2;
    m_sensors[3] = &m_s3;
}

Sensor* TestTank::getLevelSensor(uint8_t number)
{
    if (number >= m_levelSensorsNum)
        return {};

    return m_sensors[number];
}

Sensor** TestTank::getLevelSensors()
{
    return m_sensors;
}

uint8_t TestTank::getLevelSensorsNum() const
{
    return m_levelSensorsNum;
}

Sensor* TestTank::getLowerLevelSensor()
{
    return &m_s0;
}

Sensor* TestTank::getUpperLevelSensor()
{
    return &m_s3;
}

Tank::Status TestTank::getStatus()
{
    return {};
}

bool TestTank::isNeedEmergencyPumping()
{
    return {};
}

void TestTank::setSensorsData(const std::vector<bool>& data)
{
    m_s0.setData(data.at(0));
    m_s1.setData(data.at(1));
    m_s2.setData(data.at(2));
    m_s3.setData(data.at(3));
}
