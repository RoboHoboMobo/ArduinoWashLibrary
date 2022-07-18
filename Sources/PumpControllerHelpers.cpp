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
            current->finish();
            next->on();

            current = next;
            next = current->next;

            continue;
        }

        if (currentState == Node::WaterIsReady && next->canPumping())
            next->on();
        else
            next->finish();

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

        if (current->isNeedEmergencyPumping() && !current->source->isEmpty()) {
            prev->finish();
            current->on();

            current = prev;
            prev = current->prev;

            continue;
        }

        if (current->next && current->next->getState() == Node::PumpOn) {
            current->finish();

            current = prev;
            prev = current->prev;

            continue;
        }

        if (prevState == Node::WaterIsReady && current->canPumping())
            current->on();
        else
            current->finish();

        current = prev;
        prev = current->prev;
    }

    return true;
}
