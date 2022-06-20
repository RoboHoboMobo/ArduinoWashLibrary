#pragma once

#include <stdint.h>

#define ON_ARDUINO 0

#if ON_ARDUINO == 1
    #include "Arduino.h"
#else
    #include <cassert>
#endif

#if ON_ARDUINO == 0
    #define INPUT           (0x0ul)
    #define OUTPUT          (0x1ul)
    #define INPUT_PULLUP    (0x2ul)

    #define LOW             (0x0ul)
    #define HIGH            (0x1ul)
#endif
