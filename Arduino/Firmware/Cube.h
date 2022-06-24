#pragma once

#include "Tank.h"

/**
 * @brief Класс куба
 */
class Cube : public Tank
{
public:
    static constexpr uint8_t levelSensorsNum = 2;

    Cube(const uint8_t (&floatLevelSensorsPins)[levelSensorsNum]);

    Sensor* getLevelSensor(uint8_t number) override;

    Sensor** getLevelSensors() override;

    uint8_t getLevelSensorsNum() const override;

    Status getStatus() override;

    Sensor* getLowerLevelSensor() override;

    Sensor* getUpperLevelSensor() override;

    bool isNeedEmergencyPumping() override;

private:
    FloatLevelSensor m_lowerLevelSensor;
    FloatLevelSensor m_upperLevelSensor;

    Sensor* m_levelSensors[levelSensorsNum];
};
