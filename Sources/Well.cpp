#include "Well.h"

Sensor* Well::getLevelSensor(uint8_t)
{
    return {};
}

Sensor** Well::getLevelSensors()
{
    return {};
}

uint8_t Well::getLevelSensorsNum() const
{
    return {};
}

Tank::Status Well::getStatus()
{
    return NotFull;
}

Sensor* Well::getLowerLevelSensor()
{
    return {};
}

Sensor* Well::getUpperLevelSensor()
{
    return {};
}

bool Well::isDrainable()
{
    return true;
}

bool Well::isFillable()
{
    return true;
}

bool Well::isNeedEmergencyPumping()
{
    return {};
}
