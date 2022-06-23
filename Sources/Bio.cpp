#include "Bio.h"

#include "TankHelpers.h"

Bio::Bio(const uint8_t floatLevelSensorsPins[levelSensorsNum])
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

Sensor* Bio::getLevelSensor(uint8_t number)
{
    if (number >= levelSensorsNum)
        return {};

    return m_levelSensors[number];
}

Sensor** Bio::getLevelSensors()
{
    return m_levelSensors;
}

uint8_t Bio::getLevelSensorsNum() const
{
    return levelSensorsNum;
}

Tank::Status Bio::getStatus()
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

Sensor* Bio::getLowerLevelSensor()
{
    return m_levelSensors[0];
}

Sensor* Bio::getUpperLevelSensor()
{
    return m_levelSensors[levelSensorsNum - 1];
}

bool Bio::isNeedEmergencyPumping()
{
    return {};
}

uint8_t Bio::getLevelSensorsData()
{
    return getFloatLevelSensorsDataMask(*this);
}
