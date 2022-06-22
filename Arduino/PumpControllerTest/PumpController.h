#pragma once

#include "Node.h"

/**
 * @brief Класс контроллера логики работы насосов (связаный список)
 */
class PumpController
{
public:
    /**
     * @brief Режим работы насосов
     */
    enum Mode {
       DefaultMode = 0,
       NightMode
    };

    PumpController(Node* node = nullptr, Mode mode = DefaultMode);

    /**
     * @brief Выбрать режим работы насосов
     */
    void setMode(Mode mode);

    /**
     * @brief Возвращет текущий режим работы контроллера
     */
    Mode getCurrentMode() const;

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

    /**
     * @brief Выключить все насосы
     */
    void switchPumpsOff();

private:
    Mode m_mode;
    Node* m_head;
    Node* m_tail;
};
