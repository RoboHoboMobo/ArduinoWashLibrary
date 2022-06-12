#include "Common.h"

#include "ArduinoButton.h"

/**
 * Functions for mocking FloatLevelSensor
 */

template <uint8_t mode, uint8_t key>
bool getFloatLevelSensorData(EncButton<mode, key>& arduinoButton);

template <uint8_t mode, uint8_t key>
uint8_t updateFloatLevelSensorData(EncButton<mode, key>& arduinoButton);
