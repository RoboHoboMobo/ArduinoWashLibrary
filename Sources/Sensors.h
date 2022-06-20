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
    FloatLevelSensor(uint8_t pin, bool isPulledUp = true);

    uint8_t getPin() const override;
    bool getData() override;
    void update() override;

private:
    EncButton2<EB_BTN> m_btn;
};
