#include "PumpLogicHelpers.h"

/**
 * @param head Первый узел системы (приямок)
 *
 * @return Флаг успешного выполнения
 */
bool manageNodes(Node* head)
{
    Node* current = head;
    Node* next = current->next;

    while (next) {
        Node::State currentState = current->getState();
        Node::State nextState = next->getState();

        if (currentState == Node::Error || nextState == Node::Error)
            return false;

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
    Node* current = tail;
    Node* prev = current->prev;

    while (prev) {
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

        if (prevState == Node::WaterIsReady && current->canPumping())
            current->on();
        else
            current->finish();

        current = prev;
        prev = current->prev;
    }

    return true;
}
