#pragma once

#include "Common.h"

void switchPinOn(uint8_t pin);

void switchPinOff(uint8_t pin);

int readDigitalPin(uint8_t pin);

void setPinMode(uint8_t pin, uint8_t mode);
