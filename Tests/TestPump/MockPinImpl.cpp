#include "MockPinImpl.h"

namespace {

uint8_t pin{};
bool isOn{};

} // namespace

uint8_t MockPinImpl::getPin()
{
    return pin;
}

bool MockPinImpl::getPinCurrentState()
{
    return isOn;
}

void MockPinImpl::reset()
{
    pin = 0;
    isOn = {};
}

void setPinMode(uint8_t, uint8_t)
{
}

void switchPinOn(uint8_t p)
{
    pin = p;
    isOn = true;
}

void switchPinOff(uint8_t p)
{
    pin = p;
    isOn = false;
}
