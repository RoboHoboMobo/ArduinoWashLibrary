#pragma once

#include "Common.h"

class Pump
{
public:
    Pump(uint8_t pin, bool isOn = false);

    void on();
    void off();

    bool isOn() const;

private:
    uint8_t m_pin;

    bool m_isOn;
};
