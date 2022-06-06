#include "Sensors.h"

/**
 * Sensor
 */

Sensor::Sensor(uint8_t pin)
    : m_pin{pin}
{
}

uint8_t Sensor::getPin() const
{
    return m_pin;
}
