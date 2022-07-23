#pragma once

#include "Pump.h"
#include "Tank.h"
#include "Timer.h"

/**
 * @brief Класс узла логики работы насосов
 */
struct Node
{
    enum State {
        PumpOff = 0,  ///< Насос не работает (очистка воды)
        PumpOn,       ///< Насос работает
        WaterIsReady, ///< Вода очищена (отстоялась)

        Error = 0xFF
    };

    /**
     * @brief Узел состоит из резервуара-истока, резервуара-стока, мотора,
     * перекачивающего из истока в сток, и таймера, отсчитывающего время после перекачки
     */
    Node(Pump* pump, Tank* source, Tank* drain, Timer* timer = nullptr,
         Node* prev = nullptr, Node* next = nullptr);

    virtual State getState() const;

    Pump* pump;
    Tank* source;
    Tank* drain;
    Timer* timer;

    Node* prev;
    Node* next;

    /**
     * @brief Возвращает флаг - готов ли узел к перекачке
     */
    bool canPumping();

    /**
     * @brief Запустить узел в работу
     */
    void on();

    /**
     * @brief Закончить перекачку
     */
    void finish();

    /**
     * @brief Отключить узел
     */
    void off();

    /**
     * @brief Обновить узел
     */
    void update();

    /**
     * @brief Возвращает флаг - нужна ли экстренная перекачка в резервуар-сток узла
     */
    bool isNeedEmergencyPumping();

    /**
     * @brief Заблокировать узел для дальнейших изменений
     */
    void lock();

    /**
     * @brief Разблокировать узел
     */
    void unlock();

    bool isLocked() const;

private:
    bool m_isLocked;
};
