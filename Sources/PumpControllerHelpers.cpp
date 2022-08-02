#include "PumpControllerHelpers.h"

/**
 * @param head Первый узел системы (приямок)
 *
 * @return Флаг успешного выполнения
 */
bool manageNodes(Node* head, size_t nodesNum)
{
    if (!head)
        return true;

    if (nodesNum < 3) // TODO: Отдельный алгоритм для двух узлов
        return true;

    Node* prev = head;
    Node* current = head->next; // Начинаем со второго узла
    Node* next = current->next;

    while (next) {
        prev->update();
        current->update();
        next->update();

        const bool canNextPumping = next->canPumping() &&
                current->getState() == Node::WaterIsReady;

        if (canNextPumping)
            next->on();
        else
            next->finish();

        const bool canCurrentPumping =  current->canPumping() &&
                prev->getState() == Node::WaterIsReady;

        if (!current->isNeedEmergencyPumping()) {
            if (canCurrentPumping && next->getState() != Node::PumpOn)
                current->on();
            else
                current->finish();
        }

        if (next->isNeedEmergencyPumping() && next->canPumping())
            next->on();

        current = next;
        next = current->next;
        prev = current->prev;
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
