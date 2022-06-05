#include "TimerImpl.h"

uint32_t updateTime()
{
#if ARDUINO == 1
    return millis();
#endif

    return 0;
}
