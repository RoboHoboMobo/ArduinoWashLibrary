#include "PinImpl.h"

void writeDigitalPin(uint8_t pin, uint8_t value)
{
#if ON_ARDUINO == 1
    digitalWrite(pin, value);
#endif
}

int readDigitalPin(uint8_t pin)
{
#if ON_ARDUINO == 1
    return digitalRead(pin);
#endif

    return 0;
}

void setPinMode(uint8_t pin, uint8_t mode)
{
#if ON_ARDUINO == 1
    return pinMode(pin, mode);
#endif
}

void switchPinOn(uint8_t pin)
{
    writeDigitalPin(pin, HIGH);
}

void switchPinOff(uint8_t pin)
{
    writeDigitalPin(pin, LOW);
}
