#pragma once

#include "Tank.h"

/**
 * @brief Класс тестового резервуара с двумя датчиками уровня
 */
class TestTank : public Tank
{
public:
    TestTank(uint8_t lowerSensorPin, uint8_t upperSensorPin);

    Sensor* getLevelSensor(uint8_t number) override;

    Sensor** getLevelSensors() override;

    uint8_t getLevelSensorsNum() const override;

    Status getStatus() override;

    Sensor* getLowerLevelSensor() override;

    Sensor* getUpperLevelSensor() override;

    bool isNeedEmergencyPumping() override;

private:
    static constexpr uint8_t m_levelSensorsNum{2};
    FloatLevelSensor m_lowerLevelSensor;
    FloatLevelSensor m_upperLevelSensor;

    Sensor* m_levelSensors[m_levelSensorsNum];
};
