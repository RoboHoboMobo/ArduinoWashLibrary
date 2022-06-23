#pragma once

#include "Tank.h"

/**
 * @brief Класс концентратора
 */
class Concentrator : public Tank
{
public:
    static constexpr uint8_t levelSensorsNum = 4;

    Concentrator(const uint8_t floatLevelSensorsPins[levelSensorsNum]);

    Sensor* getLevelSensor(uint8_t number) override;

    Sensor** getLevelSensors() override;

    uint8_t getLevelSensorsNum() const override;

    Status getStatus() override;

    Sensor* getLowerLevelSensor() override;

    Sensor* getUpperLevelSensor() override;

    bool isNeedEmergencyPumping() override;

    /**
     * @brief Возвращает значения датчиков уровня в виде битовой маски
     */
    uint8_t getLevelSensorsData();

private:
    FloatLevelSensor m_floatLevelSensor0;
    FloatLevelSensor m_floatLevelSensor1;
    FloatLevelSensor m_floatLevelSensor2;
    FloatLevelSensor m_floatLevelSensor3;

    Sensor* m_levelSensors[levelSensorsNum];
};
