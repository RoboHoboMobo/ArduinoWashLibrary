#include "Cube.h"

#include "TankHelpers.h"

Cube::Cube(const uint8_t floatLevelSensorsPins[levelSensorsNum])
    : m_lowerLevelSensor(floatLevelSensorsPins[0])
    , m_upperLevelSensor(floatLevelSensorsPins[1])
    , m_levelSensors()
{
    m_levelSensors[0] = &m_lowerLevelSensor;
    m_levelSensors[1] = &m_upperLevelSensor;
}

Sensor* Cube::getLevelSensor(uint8_t number)
{
    if (number >= levelSensorsNum)
        return {};

    return m_levelSensors[number];
}

Sensor** Cube::getLevelSensors()
{
    return m_levelSensors;
}

uint8_t Cube::getLevelSensorsNum() const
{
    return levelSensorsNum;
}

Tank::Status Cube::getStatus()
{
    Status result{};

    switch (getFloatLevelSensorsDataMask(*this)) {
        case 0b00000000 :
            result = Empty;
            break;

        case 0b00000001 :
            result = NotFull;
            break;

        case 0b00000011 :
            result = Full;
            break;

        default:
            result = Error;
    }

    return result;
}

Sensor* Cube::getLowerLevelSensor()
{
    return &m_lowerLevelSensor;
}

Sensor* Cube::getUpperLevelSensor()
{
    return &m_upperLevelSensor;
}

bool Cube::isNeedEmergencyPumping()
{
    return {};
}
