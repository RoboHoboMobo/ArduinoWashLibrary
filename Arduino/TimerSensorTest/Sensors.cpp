#include "Sensors.h"

FloatLevelSensor::FloatLevelSensor(uint8_t pin, bool isPulledUp)
    : m_btn(isPulledUp ? INPUT_PULLUP : INPUT, pin)
{
}

uint8_t FloatLevelSensor::getPin() const
{
    return m_btn.getPin(0);
}

bool FloatLevelSensor::getData()
{
    return getFloatLevelSensorData(m_btn);
}

void FloatLevelSensor::update()
{
    updateFloatLevelSensorData(m_btn);
}
