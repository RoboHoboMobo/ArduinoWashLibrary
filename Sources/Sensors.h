#pragma once

#include "SensorsImpl.h"

/**
 * @brief FloatLevelSensor
 */
template <uint8_t KEY>
class FloatLevelSensor
{
public:
    uint8_t getPin() const;
    bool getData();
    void update();

private:
    EncButton<EB_TICK, KEY> m_btn;
};

template <uint8_t KEY>
uint8_t FloatLevelSensor<KEY>::getPin() const
{
    return KEY;
}

template <uint8_t KEY>
bool FloatLevelSensor<KEY>::getData()
{
    return getFloatLevelSensorData(m_btn);
}

template <uint8_t KEY>
void FloatLevelSensor<KEY>::update()
{
    updateFloatLevelSensorData(m_btn);
}
