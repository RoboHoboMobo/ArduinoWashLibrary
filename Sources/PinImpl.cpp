#include "PinImpl.h"

void switchPinOn(uint8_t)
{
#if ARDUINO == 1
    digitalWrite(pin, HIGH);
#endif
}

void switchPinOff(uint8_t)
{
#if ARDUINO == 1
    digitalWrite(pin, LOW);
#endif
}
