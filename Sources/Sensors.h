#pragma once

#include "Common.h"

/**
 * @brief Base class for sensors
 */
class Sensor
{
public:
    uint8_t getPin() const;

protected:
    Sensor(uint8_t pin);

private:
    uint8_t m_pin;
};

/**
 * @brief Adapter class for sensors with bool data
 */
class BinarySensor : public Sensor
{
public:
    virtual bool getData() = 0;
};

/**
 * @brief Adapter class for sensors with int data
 */
class IntegerSensor : public Sensor
{
public:
    virtual int32_t getData() = 0;
};

