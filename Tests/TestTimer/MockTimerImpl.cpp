#include "MockTimerImpl.h"

namespace {

uint32_t mockTime{};

} // namespace

void MockTimerImpl::setTime(uint32_t time)
{
    mockTime = time;
}

uint32_t updateTime()
{
    return mockTime;
}
