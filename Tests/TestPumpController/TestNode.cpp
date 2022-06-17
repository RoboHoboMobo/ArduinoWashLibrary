#include "TestNode.h"

TestNode::TestNode(Pump* pump, Tank* source, Tank* drain, Timer* timer,
                   Node* prev, Node* next)
    : Node{pump, source, drain, timer, prev, next}
    , mockState{}
    , mockCanPumping{}
    , mockIsOn{}
    , mockIsFinished{}
    , mockIsOff{}
{
}

void TestNode::setGetState(Node::State state)
{
    mockState = state;
}

void TestNode::setCanPumping(bool flag)
{
    mockCanPumping = flag;
}

bool TestNode::isOn()
{
    return mockIsOn;
}

bool TestNode::isFinished()
{
    return mockIsFinished;
}

bool TestNode::isOff()
{
    return mockIsOff;
}

void TestNode::reset()
{
    mockState = {};
    mockCanPumping = {};
    mockIsFinished = {};
    mockIsOn = {};
    mockIsOff = {};
}

Node::State TestNode::getState() const
{
    return mockState;
}

bool TestNode::canPumping()
{
    return mockCanPumping;
}

void TestNode::on()
{
    mockIsOn = true;

    mockState = Node::PumpOn;
}

void TestNode::finish()
{
    mockIsFinished = true;

    mockState = Node::PumpOff;
}

void TestNode::off()
{
    mockIsOff = true;

    mockState = Node::PumpOff;
}


