#include "PumpControllerHelpers.h"

/**
 * @param head Первый узел системы (приямок)
 *
 * @return Флаг успешного выполнения
 */
bool manageNodes(Node* head, size_t nodesNum)
{
    if (!head || nodesNum == 1)
        return true;

    if (nodesNum == 2) {
        Node* current = head;
        Node* next = current->next;

        if (current->getState() == Node::Error || next->getState() == Node::Error)
            return false;

        const bool isNextPumpingAvailable = next->canPumping() &&
                current->getState() == Node::WaterIsReady;

        isNextPumpingAvailable ? next->on() : next->finish();

        if (next->isNeedEmergencyPumping() && next->canPumping())
            next->on();

        return true;
    }

    Node* prev = head;
    Node* current = head->next; // Начинаем со второго узла
    Node* next = current->next;

    while (next) {
        prev->update();
        current->update();
        next->update();

        if (current->getState() == Node::Error || next->getState() == Node::Error)
            return false;

        const bool isNextPumpingAvailable = next->canPumping() &&
                current->getState() == Node::WaterIsReady;

        isNextPumpingAvailable ? next->on() : next->finish();

        const bool isCurrentPumpingAvailable =  current->canPumping() &&
                prev->getState() == Node::WaterIsReady;

        if (!current->isNeedEmergencyPumping()) {
            isCurrentPumpingAvailable && next->getState() != Node::PumpOn ?
                        current->on() : current->finish();
        }

        if (next->isNeedEmergencyPumping() && next->canPumping())
            next->on();

        current = next;
        next = current->next;
        prev = current->prev;
    }

    return true;
}
