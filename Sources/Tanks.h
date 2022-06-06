#pragma once

#include "Sensors.h"

/**
 * @brief Base class for reservoirs
 */
struct Tank
{
    enum Status {
        NotFull = 0,
        Full,
        Error = 0xFF
    };

    BinarySensor* getLowerLevelSensor();
    BinarySensor* getUpperLevelSensor();

    Status getStatus() const;
    bool isFull() const;

    /**
     * @brief First one is the lowest sensor
     */
    BinarySensor* levelSensors;
    uint8_t levelSensorsNum;

    Status status;

protected:
    Tank(BinarySensor* levelSensors, uint8_t levelSensorsNum);
};
