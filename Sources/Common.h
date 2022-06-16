#pragma once

#include <stdint.h>
#include <cassert>

#define ARDUINO 0

#if ARDUINO == 1
    #include "Arduino.h"
#endif

#if ARDUINO == 0
    #define INPUT           (0x0ul)
    #define OUTPUT          (0x1ul)
    #define INPUT_PULLUP    (0x2ul)
    #define INPUT_PULLDOWN  (0x4ul)

    #define LOW             (0x0ul)
    #define HIGH            (0x1ul)
#endif
