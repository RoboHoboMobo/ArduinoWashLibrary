#include "PumpController.h"

#include "PumpControllerHelpers.h"

PumpController::PumpController(Node* node, Mode mode)
    : m_mode{mode}
    , m_head{node}
    , m_tail{node}
{
}

void PumpController::setMode(Mode mode)
{
    if (mode != m_mode)
        m_mode = mode;
}

PumpController::Mode PumpController::getCurrentMode() const
{
    return m_mode;
}

void PumpController::pushFront(Node* node)
{
    if (!node)
        return;

    if (!m_head && !m_tail)
    {
        m_tail = node;
        m_head = node;

        return;
    }

    if (!m_head) {
        m_head = node;

        return;
    }

    m_head->prev = node;
    node->next = m_head;

    m_head = node;
}

void PumpController::pushBack(Node* node)
{
    if (!node)
        return;

    if (!m_head && !m_tail)
    {
        m_tail = node;
        m_head = node;

        return;
    }

    if (!m_tail) {
        m_tail = node;

        return;
    }

    m_tail->next = node;
    node->prev = m_tail;

    m_tail = node;
}

void PumpController::popFront()
{
    if (!m_head)
        return;

    m_head = m_head->next;

    m_head->prev = {};
}

void PumpController::popBack()
{
    if (!m_tail)
        return;

    m_tail = m_tail->prev;

    m_tail->next = {};
}

Node* PumpController::front()
{
    return m_head;
}

Node* PumpController::back()
{
    return m_tail;
}

/**
 * @param Флаг того, что нужно управлять с последнего узла
 *
 * @return Флаг того, что обход узлов выполнился без ошибок
 */
bool PumpController::operate(bool needReverse)
{
    if (!m_head || !m_tail)
        return true;

    switch (m_mode) {
        case DefaultMode : {
            if (needReverse)
                return manageNodesReverse(m_tail);

            return manageNodes(m_head);
        }
            break;

        case NightMode : {
            switchPumpsOff();

            return true;
        }
            break;
    }

    return {};
}

void PumpController::update()
{
    Node* current = m_head;

    while (current) {
        current->update();

        current = current->next;
    }
}

void PumpController::switchPumpsOff()
{
    if (!m_head || !m_tail)
        return;

    Node* current = m_head->next; // Первый насос - ручной, поэтому начинаем со второго

    while (current) {
        current->off();
        current = current->next;
    }
}
