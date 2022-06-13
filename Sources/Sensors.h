#pragma once

#include "SensorsImpl.h"

/**
 * @brief FloatLevelSensor
 */
class FloatLevelSensor
{
public:
    FloatLevelSensor(uint8_t pin);

    uint8_t getPin() const;
    bool getData();
    void update();

private:
    EncButton<EB_TICK> m_btn;
};
