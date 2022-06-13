#pragma once

#include "Sensors.h"

/**
 * @brief Base class for reservoirs
 */
class Tank
{
public:
    enum Status
    {
        NotFull = 0,
        Full,
        Error = 0xFF
    };

    virtual Sensor* getLevelSensor(uint8_t number) = 0;
    virtual uint8_t getLevelSensorsNum() const = 0;
    virtual Status getStatus() = 0;

    virtual Sensor* getLowerLevelSensor() = 0;
    virtual Sensor* getUpperLevelSensor() = 0;

    bool isFull();
    void update();
};

/**
 * @brief The Cube class
 */
class Cube : public Tank
{
public:
    Cube(Sensor** levelSensors, uint8_t sensorsNum = 0);

    Sensor* getLevelSensor(uint8_t number) override;
    uint8_t getLevelSensorsNum() const override;
    Status getStatus() override;

    Sensor* getLowerLevelSensor() override;
    Sensor* getUpperLevelSensor() override;

private:
    /**
     * @brief First one is the lowest sensor
     */
    FloatLevelSensor** m_levelSensors;
    uint8_t m_levelSensorsNum;
};
