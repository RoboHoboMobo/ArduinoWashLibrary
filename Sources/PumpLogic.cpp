#include "PumpLogic.h"

#include "PumpLogicHelpers.h"

PumpLogic::PumpLogic(Node* node)
    : m_head{node}
    , m_tail{node}
{
}

void PumpLogic::pushFront(Node* node)
{
    m_head->prev = node;
    node->next = m_head;

    m_head = node;
}

void PumpLogic::pushBack(Node* node)
{
    m_tail->next = node;
    node->prev = m_tail;

    m_tail = node;
}

void PumpLogic::popFront()
{
    m_head = m_head->next;

    m_head->prev = {};
}

void PumpLogic::popBack()
{
    m_tail = m_tail->prev;

    m_tail->next = {};
}

Node* PumpLogic::front()
{
    return m_head;
}

Node* PumpLogic::back()
{
    return m_tail;
}

/**
 * @param Флаг того, что нужно управлять с последнего узла
 *
 * @return Флаг того, что обход узлов выполнился без ошибок
 */
bool PumpLogic::operate(bool needReverse)
{
    if (needReverse)
        return manageNodesReverse(m_tail);

    return manageNodes(m_head);
}
