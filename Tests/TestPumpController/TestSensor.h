#pragma once

#include "Sensors.h"

class TestSensor : public BinarySensor
{
public:
    TestSensor(uint8_t pin);

    uint8_t getPin() const override;
    void update() override;
    bool getData() override;

    void setData(bool data);
    bool isUpdated() const;

private:
    uint8_t m_pin;
    bool m_data;
    bool m_isUpdated;
};
