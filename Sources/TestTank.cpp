#include "TestTank.h"

/**
 * @class TestTank
 */
TestTank::TestTank(uint8_t lowerSensorPin, uint8_t upperSensorPin)
    : m_lowerLevelSensor{lowerSensorPin}
    , m_upperLevelSensor{upperSensorPin}
    , m_levelSensors{}
{
    m_levelSensors[0] = &m_lowerLevelSensor;
    m_levelSensors[1] = &m_upperLevelSensor;
}

Sensor* TestTank::getLevelSensor(uint8_t number)
{
    if (number == 0)
        return &m_lowerLevelSensor;

    if (number == 1)
        return &m_upperLevelSensor;

    return {};
}

Sensor** TestTank::getLevelSensors()
{
    return m_levelSensors;
}

uint8_t TestTank::getLevelSensorsNum() const
{
    return m_levelSensorsNum;
}

Tank::Status TestTank::getStatus()
{
    const bool lowerSensorData = m_lowerLevelSensor.getData();
    const bool upperSensorData = m_upperLevelSensor.getData();

    if (!lowerSensorData && !upperSensorData)
        return Empty;
    else if (lowerSensorData && !upperSensorData)
        return NotFull;
    else if (lowerSensorData && upperSensorData)
        return Full;

    return Error;
}

Sensor* TestTank::getLowerLevelSensor()
{
    return &m_lowerLevelSensor;
}

Sensor* TestTank::getUpperLevelSensor()
{
    return &m_upperLevelSensor;
}
