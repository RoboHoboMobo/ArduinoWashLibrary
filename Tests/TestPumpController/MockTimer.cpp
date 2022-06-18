#include "MockTimer.h"

Timer::Timer(uint32_t remain)
    : m_state{Stopped}
    , m_begin{}
    , m_remain{remain}
    , m_end{}
    , m_duration{}
{
}

Timer::State Timer::start()
{
    if (m_state == Stopped && m_remain > 0)
        m_state = Running;

    return m_state;
}

Timer::State Timer::stop()
{
    return m_state = Stopped;
}

Timer::State Timer::pause()
{
    return {};
}

Timer::State Timer::resume()
{
    return {};
}

void Timer::update()
{
}

void Timer::reset(uint32_t)
{
    m_state = Stopped;

    m_remain = 999;
}

Timer::State Timer::getState() const
{
    return m_state;
}

uint32_t Timer::getRemainingTime() const
{
    return {};
}

uint32_t Timer::getDuration() const
{
    return 999;
}

bool Timer::isDone() const
{
    return m_state == Stopped && m_remain == 0;
}
