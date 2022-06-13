#pragma once

#include "Pump.h"
#include "Tanks.h"
#include "Timer.h"

struct PumpController
{
    PumpController(Pump* pump, Tank* source, Tank* drain, Timer* timer = nullptr)
        : pump{pump}
        , source{source}
        , drain{drain}
        , timer{timer}
    {
    }

    Pump* pump;

    Tank* source;
    Tank* drain;

    Timer* timer;
};
