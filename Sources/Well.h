#pragma once

#include "Tank.h"

/**
 * @brief Класс приямка
 */
class Well : public Tank
{
public:
    Sensor* getLevelSensor(uint8_t) override;

    Sensor** getLevelSensors() override;

    uint8_t getLevelSensorsNum() const override;

    Status getStatus() override;

    Sensor* getLowerLevelSensor() override;

    Sensor* getUpperLevelSensor() override;

    bool isDrainable() override;

    bool isFillable() override;

    bool isNeedEmergencyPumping() override;
};
