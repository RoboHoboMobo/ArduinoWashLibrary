#include "Timer.h"

#include "TimerImpl.h"

Timer::Timer(uint32_t duration, bool isDone)
    : m_state{Stopped}
    , m_begin{}
    , m_remain{isDone ? 0 : duration}
    , m_end{}
    , m_duration{duration}
{
}

Timer::State Timer::start()
{
    if (m_state == Stopped && m_remain > 0) {
        m_begin = updateTime();
        m_end = m_begin + m_remain;

        m_state = Running;
    }

    return m_state;
}

Timer::State Timer::stop()
{
    return m_state = Stopped;
}

Timer::State Timer::pause()
{
    if (m_state == Running)
        m_state = Paused;

    return m_state;
}

Timer::State Timer::resume()
{
    if (m_state == Paused)
        m_state = Running;

    return m_state;
}

void Timer::update()
{
    if (m_state == Running)
    {
        m_begin = updateTime();

        if (m_begin >= m_end) {
            m_remain = 0;
            m_state = Stopped;

            return;
        }

        m_remain = m_end - m_begin;
    }
    else if (m_state == Paused) {
        m_begin = updateTime();

        m_end = m_begin + m_remain;
    }
}

void Timer::reset(uint32_t newTime)
{
    m_state = Stopped;

    m_begin = 0;
    m_remain = newTime;
    m_end = 0;

    m_duration = newTime;
}

Timer::State Timer::getState() const
{
    return m_state;
}

uint32_t Timer::getRemainingTime() const
{
    return m_remain;
}

uint32_t Timer::getDuration() const
{
    return m_duration;
}

bool Timer::isDone() const
{
    return m_state == Stopped && m_remain == 0;
}
