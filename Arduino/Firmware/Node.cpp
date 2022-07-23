#include "Node.h"

Node::Node(Pump* pump, Tank* source, Tank* drain, Timer* timer, Node* prev, Node* next)
    : pump{pump}
    , source{source}
    , drain{drain}
    , timer{timer}
    , prev{prev}
    , next{next}
    , m_isLocked{}
{
#if ON_ARDUINO == 0
    assert(pump);
    assert(source);
    assert(drain);
#endif
}

Node::State Node::getState() const
{
    if (!timer)
        return pump->isOn() ? PumpOn : PumpOff;

    const bool isDone = timer->isDone();

    if (!pump->isOn())
        return isDone ? WaterIsReady : PumpOff;
    else
        return isDone ? Error : PumpOn;

    return Error;
}

bool Node::canPumping()
{
    return source->isDrainable() && drain->isFillable();
}

void Node::on()
{
    if (m_isLocked)
        return;

    pump->on();

    if (timer)
        timer->reset(timer->getDuration());
}

void Node::finish()
{
    if (m_isLocked)
        return;

    pump->off();

    if (timer)
        timer->start();
}

void Node::off()
{
    if (m_isLocked)
        return;

    pump->off();

    if (timer)
        timer->reset(timer->getDuration());
}

void Node::update()
{
    source->update();
    drain->update();

    if (timer)
        timer->update();
}

bool Node::isNeedEmergencyPumping()
{
    return drain->isNeedEmergencyPumping();
}

void Node::lock()
{
    m_isLocked = true;
}

void Node::unlock()
{
    m_isLocked = false;
}
