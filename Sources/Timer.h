#pragma once

#include <stdint.h>

class Timer
{
public:

    enum State
    {
        Stopped = 0,
        Running,
        Paused
    };

    Timer(uint32_t duration);

    State start();
    State stop();
    State pause();
    State resume();

    void update();
    void reset(uint32_t newTime = 0);

    State getState() const;
    uint32_t getRemainingTime() const;

private:
    State m_state;

    uint32_t m_begin;
    uint32_t m_remain;
    uint32_t m_end;
};
