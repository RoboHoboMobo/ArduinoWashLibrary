#pragma once

#include <stdint.h>

/**
 * @brief Function for mocking millis() in Arduino
 *
 * @return Current time in milliseconds
 */
uint32_t updateTime();
