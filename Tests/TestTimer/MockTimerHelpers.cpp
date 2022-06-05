#include "MockTimerHelpers.h"

namespace {

uint32_t mockTime{};

} // namespace

void MockTimerHelpers::setTime(uint32_t time)
{
    mockTime = time;
}

uint32_t updateTime()
{
    return mockTime;
}
