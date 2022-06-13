#include "Sensors.h"

FloatLevelSensor::FloatLevelSensor(uint8_t pin)
    : m_btn{INPUT_PULLUP, pin}
{
}

uint8_t FloatLevelSensor::getPin() const
{
    return m_btn._S1;
}

bool FloatLevelSensor::getData()
{
    return getFloatLevelSensorData(m_btn);
}

void FloatLevelSensor::update()
{
    updateFloatLevelSensorData(m_btn);
}
