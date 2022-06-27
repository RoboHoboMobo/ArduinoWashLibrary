#include "Pump.h"

#include "PinImpl.h"

Pump::Pump()
    : m_pin{}
    , m_isManual{true}
    , m_isOn{}
{
}

Pump::Pump(uint8_t pin, bool isOn)
    : m_pin{pin}
    , m_isManual{}
    , m_isOn{isOn}
{
    setPinMode(pin, OUTPUT);

    m_isOn ? switchPinOn(m_pin) : switchPinOff(m_pin);
}

void Pump::on()
{
    if (m_isOn)
        return;

    if (!m_isManual)
        switchPinOn(m_pin);

    m_isOn = true;
}

void Pump::off()
{
    if (!m_isOn)
        return;

    if (!m_isManual)
        switchPinOff(m_pin);

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
