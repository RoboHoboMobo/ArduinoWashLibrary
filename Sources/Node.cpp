#include "Node.h"

Node::Node(Pump* pump, Tank* source, Tank* drain, Timer* timer, Node* next)
    : pump{pump}
    , source{source}
    , drain{drain}
    , timer{timer}
    , next{next}
{
    assert(pump);
    assert(source);
    assert(drain);
}

Node::State Node::getState() const
{
    if (!timer)
        return pump->isOn() ? PumpOn : PumpOff;

    const bool isDone = timer->isDone();

    if (!pump->isOn())
        return isDone ? PumpOff : Retention;
    else
        return isDone ? Error : PumpOn;

    return Error;
}

bool Node::isReadyForPumping()
{
    return source->isDrainable() && drain->isFillable();
}

void Node::on()
{
    pump->on();

    if (timer)
        timer->reset(timer->getDuration());
}

void Node::off()
{
    pump->off();

    if (timer)
        timer->start();
}

