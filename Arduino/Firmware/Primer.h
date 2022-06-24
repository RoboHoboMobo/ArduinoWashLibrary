#pragma once

#include "Tank.h"

/**
 * @brief Класс первака
 */
class Primer : public Tank
{
public:
    static constexpr uint8_t levelSensorsNum = 2;

    Primer(const uint8_t (&floatLevelSensorsPins)[levelSensorsNum]);

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
