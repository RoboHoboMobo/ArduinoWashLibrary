#pragma once

#include "ArduinoButton.h"

/**
 * Functions for mocking FloatLevelSensor
 */

template <uint8_t type, uint8_t mode>
bool getFloatLevelSensorData(EncButton2<type, mode>& arduinoButton);

template <uint8_t type, uint8_t mode>
uint8_t updateFloatLevelSensorData(EncButton2<type, mode>& arduinoButton);
