#include "TestSensor.h"

TestSensor::TestSensor(uint8_t pin)
    : m_pin{pin}
    , m_data{}
    , m_isUpdated{}
{
}

uint8_t TestSensor::getPin() const
{
    return m_pin;
}

void TestSensor::update()
{
    m_isUpdated = true;
}

bool TestSensor::getData()
{
    return m_data;
}

void TestSensor::setData(bool data)
{
    m_data = data;
}

bool TestSensor::isUpdated() const
{
    return m_isUpdated;
}
