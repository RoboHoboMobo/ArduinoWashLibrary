#pragma once

#include "PumpController.h"

/**
 * @brief Класс контроллера логики работы системы
 */
class Controller
{
public:
    enum State
    {
        On = 0,
        Error = 0xFF
    };

    Controller(PumpController* pc, uint8_t errorLampPin, uint8_t bioRecirculationPin);

    /**
     * @brief Выбрать состояние системы
     */
    void setState(State state);

    /**
     * @brief Возвращает состояние системы
     */
    State getState() const;

    /**
     * @brief Выбрать режим работы
     */
    void setMode(PumpController::Mode mode);

    /**
     * @brief Возвращет режим работы
     */
    PumpController::Mode getMode() const;

    /**
     * @brief Управление системой
     */
    void operate();

    /**
     * @brief Обновить узлы
     */
    void update();

private:
    State m_state;
    PumpController* m_pc;
    const uint8_t m_errorLamp;
    const uint8_t m_bioRecirculation;
};
