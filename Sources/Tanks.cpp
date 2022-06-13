#include "Tanks.h"

/**
  * @class Tank
  */

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

/**
  * @class Cube
  */

Cube::Cube(Sensor** levelSensors, uint8_t sensorsNum)
    : m_levelSensors{reinterpret_cast<FloatLevelSensor**>(levelSensors)}
    , m_levelSensorsNum{sensorsNum}
{
}

Sensor* Cube::getLevelSensor(uint8_t number)
{
    if (m_levelSensorsNum == 0 || number >= m_levelSensorsNum)
        return nullptr;

    return m_levelSensors[number];
}

uint8_t Cube::getLevelSensorsNum() const
{
    return m_levelSensorsNum;
}

Sensor* Cube::getLowerLevelSensor()
{
    if (m_levelSensorsNum == 0)
        return nullptr;

    return m_levelSensors[0];
}

Sensor* Cube::getUpperLevelSensor()
{
    if (m_levelSensorsNum == 0)
        return nullptr;

    return m_levelSensors[m_levelSensorsNum - 1];
}

Tank::Status Cube::getStatus()
{
    if (getLevelSensorsNum() == 0)
        return Error;

    if (getLevelSensorsNum() == 1) {
        BinarySensor* sensor = static_cast<BinarySensor*>(getLowerLevelSensor());

        return sensor->getData() ? Full : NotFull;
    }

    /// Error if higher sensor is activated but lower isn't
    for (uint8_t i = 1; i < getLevelSensorsNum(); ++i) {
        BinarySensor* prevSensor = static_cast<BinarySensor*>(getLevelSensor(i - 1));
        BinarySensor* curSensor = static_cast<BinarySensor*>(getLevelSensor(i));

        if (!prevSensor->getData() && curSensor->getData())
            return Error;
    }

    return static_cast<BinarySensor*>(getUpperLevelSensor())->getData() ?
                Full : NotFull;
}
