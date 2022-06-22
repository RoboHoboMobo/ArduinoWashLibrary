#pragma once

#include "Sensors.h"

/**
 * @brief Базовый класс резервуара
 */
class Tank
{
public:
    enum Status
    {
        Empty = 0,
        NotFull,
        Full,
        Error = 0xFF
    };

    /**
     * @brief Возвращает датчик согласно его номеру (отсчет начинается снизу)
     */
    virtual Sensor* getLevelSensor(uint8_t number) = 0;

    /**
     * @brief Возвращает массив указателей на датчики
     */
    virtual Sensor** getLevelSensors() = 0;

    /**
     * @brief Возвращает число датчиков уровня в резервуаре
     */
    virtual uint8_t getLevelSensorsNum() const = 0;

    /**
     * @brief Возвращает состояние резервуара
     */
    virtual Status getStatus() = 0;

    /**
     * @brief Возвращает самый нижний датчик уровня в резервуаре
     */
    virtual Sensor* getLowerLevelSensor() = 0;

    /**
     * @brief Возвращает самый верхний датчик уровня в резервуаре
     */
    virtual Sensor* getUpperLevelSensor() = 0;

    /**
     * @brief Возвращает флаг - можно ли откачивать из резервуара
     */
    virtual bool isDrainable();

    /**
     * @brief Возвращает флаг - можно ли закачивать в резервуар
     */
    virtual bool isFillable();

    /**
     * @brief Возвращает флаг пустоты резервуара
     */
    bool isEmpty();

    /**
     * @brief Возвращает флаг заполненности резервуара
     */
    bool isFull();

    /**
     * @brief Обновляет показания датчиков в резервуаре
     */
    void update();

    /**
     * @brief Возвращает флаг - нужна ли экстренная перекачка (без ожидания таймера)
     */
    virtual bool isNeedEmergencyPumping() = 0;
};
