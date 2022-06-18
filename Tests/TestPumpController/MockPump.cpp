#include "MockPump.h"

Pump::Pump(uint8_t pin, bool isOn)
    : m_pin{pin}
    , m_isOn{isOn}
{
}

void Pump::on()
{
    m_isOn = true;
}

void Pump::off()
{
    m_isOn = false;
}

uint8_t Pump::getPin() const
{
    return m_pin;
}

bool Pump::isOn() const
{
    return m_isOn;
}

