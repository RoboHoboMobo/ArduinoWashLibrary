#pragma once

#include "ArduinoButton.h"

/**
 * Template functions implementation from SensorsImpl.h
 */

template <uint8_t type, uint8_t mode>
bool getFloatLevelSensorData(EncButton2<type, mode>& arduinoButton)
{
#if ON_ARDUINO == 1
    return arduinoButton.hold();
#endif

    return {};
}

template <uint8_t type, uint8_t mode>
uint8_t updateFloatLevelSensorData(EncButton2<type, mode>& arduinoButton)
{
#if ON_ARDUINO == 1
    return arduinoButton.tick();
#endif

    return {};
}

