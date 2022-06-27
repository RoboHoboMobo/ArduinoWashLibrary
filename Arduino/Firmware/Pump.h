#pragma once

#include "Common.h"

/**
 * @brief Класс насоса
 */
class Pump
{
public:
    /**
     * @brief Конструктор для ручного насоса (не управляется алгоритмом)
     */
    Pump();

    /**
     * @brief Конструктор управляемого насоса
     */
    Pump(uint8_t pin, bool isOn = false);

    /**
     * @brief Включить насос
     */
    void on();

    /**
     * @brief Выключить насос
     */
    void off();

    /**
     * @brief Возвращает номер пина
     */
    uint8_t getPin() const;

    /**
     * @brief Возвращает флаг включенности насоса
     */
    bool isOn() const;

private:
    const uint8_t m_pin;
    const bool m_isManual;

    bool m_isOn;
};
