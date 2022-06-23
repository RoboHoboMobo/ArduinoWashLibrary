#include "Concentrator.h"

#include "TankHelpers.h"

Concentrator::Concentrator(const uint8_t floatLevelSensorsPins[levelSensorsNum])
    : m_floatLevelSensor0(floatLevelSensorsPins[0])
    , m_floatLevelSensor1(floatLevelSensorsPins[1])
    , m_floatLevelSensor2(floatLevelSensorsPins[2])
    , m_floatLevelSensor3(floatLevelSensorsPins[3])
    , m_levelSensors()
{
    m_levelSensors[0] = &m_floatLevelSensor0;
    m_levelSensors[1] = &m_floatLevelSensor1;
    m_levelSensors[2] = &m_floatLevelSensor2;
    m_levelSensors[3] = &m_floatLevelSensor3;
}

Sensor* Concentrator::getLevelSensor(uint8_t number)
{
    if (number >= levelSensorsNum)
        return {};

    return m_levelSensors[number];
}

Sensor** Concentrator::getLevelSensors()
{
    return m_levelSensors;
}

uint8_t Concentrator::getLevelSensorsNum() const
{
    return levelSensorsNum;
}

Tank::Status Concentrator::getStatus()
{
    Status result{};

    switch (getLevelSensorsData()) {
        case 0b00000000 :
            result = Empty;
            break;

        case 0b00000001 :
        case 0b00000011 :
        case 0b00000111 :
            result = NotFull;
            break;

        case 0b00001111 :
            result = Full;
            break;

        default :
            result = Error;
            break;
    }

    return result;
}

Sensor* Concentrator::getLowerLevelSensor()
{
    return m_levelSensors[0];
}

Sensor* Concentrator::getUpperLevelSensor()
{
    return m_levelSensors[levelSensorsNum - 1];
}

bool Concentrator::isNeedEmergencyPumping()
{
    return getStatus() == Status::Empty;
}

uint8_t Concentrator::getLevelSensorsData()
{
    return getFloatLevelSensorsDataMask(*this);
}

