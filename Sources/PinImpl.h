#pragma once

#include "Common.h"

/**
 * Functions for mocking pins in Arduino
 */

/**
 * @brief Function for mocking digitalWrite(pin, value) in Arduino
 */
void writeDigitalPin(uint8_t pin, uint8_t value);

/**
 * @brief Function for mocking digitalRead(pin) in Arduino
 *
 * @return HIGH or LOW
 */
int readDigitalPin(uint8_t pin);

/**
 * @brief Function for mocking pinMode(pin, mode) in Arduino
 */
void setPinMode(uint8_t pin, uint8_t mode);

void switchPinOn(uint8_t pin);

void switchPinOff(uint8_t pin);
