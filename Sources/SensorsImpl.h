#include "ArduinoButton.h"

/**
 * Functions for mocking FloatLevelSensor
 */

template <uint8_t mode>
bool getFloatLevelSensorData(EncButton<mode>& arduinoButton);

template <uint8_t mode>
uint8_t updateFloatLevelSensorData(EncButton<mode>& arduinoButton);
