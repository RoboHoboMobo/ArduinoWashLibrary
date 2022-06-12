#include "SensorsImpl.h"

/**
 * Functions for mocking FloatLevelSensor
 */

template <uint8_t mode, uint8_t key>
bool getFloatLevelSensorData(EncButton<mode, key>& arduinoButton)
{
#if ARDUINO == 1
    return arduinoButton.hold();
#endif

    return {};
}

template <uint8_t mode, uint8_t key>
uint8_t updateFloatLevelSensorData(EncButton<mode, key>& arduinoButton)
{
#if ARDUINO == 1
    return arduinoButton.tick();
#endif

    return {};
}
