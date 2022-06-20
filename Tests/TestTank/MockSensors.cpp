#include "MockSensors.h"

namespace {

std::vector<bool> mockSensorsData{};
size_t mockDataIndex{};

} // namespace

void MockSensors::setFloatLevelSensorsData(const std::vector<bool>& data)
{
    mockSensorsData = data;

    mockDataIndex = 0;
}

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
    return mockSensorsData.at(mockDataIndex++);
}

void FloatLevelSensor::update()
{
}
