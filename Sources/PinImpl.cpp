#include "PinImpl.h"

void switchPinOn(uint8_t pin)
{
#if ARDUINO == 1
    digitalWrite(pin, HIGH);
#endif
}

void switchPinOff(uint8_t pin)
{
#if ARDUINO == 1
    digitalWrite(pin, LOW);
#endif
}

int readDigitalPin(uint8_t pin)
{
#if ARDUINO == 1
    return digitalRead(pin);
#endif

    return 0;
}

void setPinMode(uint8_t pin, uint8_t mode)
{
#if ARDUINO == 1
    return pinMode(pin, mode);
#endif
}
