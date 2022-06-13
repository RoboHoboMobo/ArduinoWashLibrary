#include "ArduinoButton.h"

template <uint8_t mode>
bool getFloatLevelSensorData(EncButton<mode>& arduinoButton)
{
#if ARDUINO == 1
    return arduinoButton.hold();
#endif

    return {};
}

template <uint8_t mode>
uint8_t updateFloatLevelSensorData(EncButton<mode>& arduinoButton)
{
#if ARDUINO == 1
    return arduinoButton.tick();
#endif

    return {};
}

