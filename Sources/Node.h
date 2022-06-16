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
        PumpOff = 0, ///< Насос не работает
        PumpOn,      ///< Насос работает
        Retention,   ///< Очистка (отстаивание) воды

        Error = 0xFF
    };

    /**
     * @brief Узел состоит из резервуара-истока, резервуара-стока, мотора,
     * перекачивающего из истока в сток, и таймера, отсчитывающего время после перекачки
     */
    Node(Pump* pump, Tank* source, Tank* drain, Timer* timer = nullptr,
         Node* next = nullptr);

    State getState() const;

    Pump* pump;
    Tank* source;
    Tank* drain;
    Timer* timer;

    Node* next;

    /**
     * @brief Возвращает флаг - готов ли узел к перекачке
     */
    bool isReadyForPumping();

    /**
     * @brief Запустить узел в работу
     */
    void on();

    /**
     * @brief Отключить узел
     */
    void off();
};
