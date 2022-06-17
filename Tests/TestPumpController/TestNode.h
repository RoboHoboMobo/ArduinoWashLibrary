#pragma once

#include "Node.h"

class TestNode : public Node
{
public:
    TestNode(Pump* pump, Tank* source, Tank* drain, Timer* timer = nullptr,
             Node* prev = nullptr, Node* next = nullptr);

    void setGetState(Node::State);
    void setCanPumping(bool);
    bool isOn();
    bool isFinished();
    bool isOff();

    void reset();

    State getState() const override;
    bool canPumping() override;
    void on() override;
    void finish() override;
    void off() override;

private:
    Node::State mockState;
    bool mockCanPumping;
    bool mockIsOn;
    bool mockIsFinished;
    bool mockIsOff;
};
