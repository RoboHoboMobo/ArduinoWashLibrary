#pragma once

#include "Sensors.h"

/**
 * @brief Base class for reservoirs
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
    virtual bool isFillable();  ///< Можно наполнять

    /**
     * @brief Возвращает флаг заполненности резервуара
     */
    bool isFull();

    /**
     * @brief Обновляет показания датчиков в резервуаре
     */
    void update();
};
