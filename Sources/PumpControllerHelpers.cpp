#include "PumpControllerHelpers.h"

/**
 * @param head Первый узел системы (приямок)
 *
 * @return Флаг успешного выполнения
 */
bool manageNodes(Node* head)
{
    if (!head)
        return true;

    Node* current = head;
    Node* next = current->next;

    while (next) {
        current->update();
        next->update();

        Node::State currentState = current->getState();
        Node::State nextState = next->getState();

        if (currentState == Node::Error || nextState == Node::Error)
            return false;

        if (next->isNeedEmergencyPumping() && !next->source->isEmpty()) {
            current->off();
            next->on();
        }
        else {
            if (currentState == Node::WaterIsReady && next->canPumping())
                next->on();
            else
                next->finish();
        }

        current = next;
        next = current->next;
    }

    return true;
}

/**
 * @param tail Последний узел системы (концентратор)
 *
 * @return Флаг успешного выполнения
 */
bool manageNodesReverse(Node* tail)
{
    if (!tail)
        return true;

    Node* current = tail;
    Node* prev = current->prev;

    while (prev) {
        current->update();
        prev->update();

        Node::State currentState = current->getState();
        Node::State prevState = prev->getState();

        if (currentState == Node::Error || prevState == Node::Error)
            return false;

        if (current->next && current->next->getState() == Node::PumpOn) {
            current->finish();

            current = prev;
            prev = current->prev;

            continue;
        }

        if (current->isNeedEmergencyPumping() && !current->source->isEmpty()) {
            prev->off();
            current->on();
        }
        else {
            if (prevState == Node::WaterIsReady && current->canPumping())
                current->on();
            else
                current->finish();
        }

        current = prev;
        prev = current->prev;
    }

    return true;
}
