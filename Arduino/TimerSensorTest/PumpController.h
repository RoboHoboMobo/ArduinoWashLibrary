#pragma once

#include "Node.h"

/**
 * @brief Класс контроллера логики работы насосов (связаный список)
 */
class PumpController
{
public:
    PumpController(Node* node = nullptr);

    /**
     * @brief Вставить узел перед первым
     */
    void pushFront(Node* node);

    /**
     * @brief Вставить узел после последнего
     */
    void pushBack(Node* node);

    /**
     * @brief Удалить первый узел
     */
    void popFront();

    /**
     * @brief Удалить последний узел
     */
    void popBack();

    /**
     * @brief Получить первый узел системы
     */
    Node* front();

    /**
     * @brief Получить последний узел системы
     */
    Node* back();

    /**
     * @brief Управление узлами
     */
    bool operate(bool needReverse = false);

    /**
     * @brief Обновить узлы
     */
    void update();

private:
    Node* m_head;
    Node* m_tail;
};
