#pragma once

#include "SensorsImpl.h"

class Sensor
{
public:
    virtual uint8_t getPin() const = 0;
    virtual void update() = 0;
};

class BinarySensor : public Sensor
{
public:
    virtual bool getData() = 0;
};

/**
 * @brief FloatLevelSensor
 */
class FloatLevelSensor : public BinarySensor
{
public:
    FloatLevelSensor(uint8_t pin);

    uint8_t getPin() const override;
    bool getData() override;
    void update() override;

private:
    EncButton<EB_TICK> m_btn;
};
