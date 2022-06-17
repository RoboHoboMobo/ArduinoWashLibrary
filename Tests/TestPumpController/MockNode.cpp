#include "MockNode.h"

Node::Node(Pump* pump, Tank* source, Tank* drain, Timer* timer, Node* prev, Node* next)
    : pump{pump}
    , source{source}
    , drain{drain}
    , timer{timer}
    , prev{prev}
    , next{next}
{
    assert(pump);
    assert(source);
    assert(drain);
}

Node::State Node::getState() const
{
    return {};
}

bool Node::canPumping()
{
    return {};
}

void Node::on()
{
}

void Node::finish()
{
}

void Node::off()
{
}

