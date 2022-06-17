#include "PumpController.h"

#include "PumpControllerHelpers.h"

PumpController::PumpController(Node* node)
    : m_head{node}
    , m_tail{node}
{
}

void PumpController::pushFront(Node* node)
{
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
    m_head = m_head->next;

    m_head->prev = {};
}

void PumpController::popBack()
{
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
    if (needReverse)
        return manageNodesReverse(m_tail);

    return manageNodes(m_head);
}
