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

        if (next->isNeedEmergencyPumping()) {
            if (next->source->isDrainable()) {
                current->finish();

                next->on();
                next->lock();

                current = next;
                next = current->next;

                continue;
            }
            else {
                next->unlock();
                next->finish();
            }
        }

        if (currentState == Node::WaterIsReady && next->canPumping()) {
            next->on();
            next->lock();
        }
        else {
            next->unlock();
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

        if (current->isNeedEmergencyPumping()) {
            if (current->source->isDrainable()) {
                prev->finish();

                current->on();
                current->lock();

                current = prev;
                prev = current->prev;

                continue;
            }
            else {
                current->unlock();
                current->finish();
            }
        }

        if (current->next && current->next->getState() == Node::PumpOn) {
            if (current->isLocked()) {
                current->unlock();
                current->finish();
                current->lock();
            }
            else
                current->finish();

            current = prev;
            prev = current->prev;

            continue;
        }

        if (current->canPumping() && prevState == Node::WaterIsReady) {
            current->on();
            current->lock();
        }
        else {
            current->unlock();
            current->finish();
        }

        current = prev;
        prev = current->prev;
    }

    return true;
}
