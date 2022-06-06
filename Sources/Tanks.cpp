#include "Tanks.h"

Tank::Tank(BinarySensor* levelSensors, uint8_t levelSensorsNum)
    : levelSensors{levelSensors}
    , levelSensorsNum{levelSensorsNum}
    , status{}
{
    status = getStatus();
}

BinarySensor* Tank::getLowerLevelSensor()
{
    if (levelSensorsNum == 0)
        return 0;

    return levelSensors;
}

BinarySensor* Tank::getUpperLevelSensor()
{
    if (levelSensorsNum == 0)
        return 0;

    return levelSensors + levelSensorsNum - 1;
}

Tank::Status Tank::getStatus() const
{
    if (levelSensorsNum == 0)
        return Status::Error;

    if (levelSensorsNum == 1)
        return levelSensors->getData() ? Status::Full : Status::NotFull;

    /// Error if higher sensor is activated but lower isn't
    for (uint8_t i = 1; i < levelSensorsNum; ++i)
        if (!levelSensors[i - 1].getData() && levelSensors[i].getData())
            return Status::Error;

    return levelSensors[levelSensorsNum - 1].getData() ? Status::Full : Status::NotFull;
}

bool Tank::isFull() const
{
    return getStatus() == Status::Full;
}
