#pragma once

#include "Common.h"

/**
 * @brief Base class for reservoirs
 */
template<typename SensorType>
class Tank
{
public:
    enum Status {
        NotFull = 0,
        Full,
        Error = 0xFF
    };

    Tank(SensorType* levelSensors, uint8_t levelSensorsNum);

    SensorType* getLevelSensor(uint8_t number);
    uint8_t getSensorsNum() const;
    Status getStatus() const;

    SensorType* getLowerLevelSensor();
    SensorType* getUpperLevelSensor();

    bool isFull() const;

    void update();

private:
    /**
     * @brief First one is the lowest sensor
     */
    SensorType* m_levelSensors;
    uint8_t m_levelSensorsNum;
    Status m_status;
};

template<typename T>
Tank<T>::Tank(T* levelSensors, uint8_t levelSensorsNum)
    : m_levelSensors{levelSensors}
    , m_levelSensorsNum{levelSensorsNum}
    , m_status{}
{
    m_status = getStatus();
}

template <typename T>
T* Tank<T>::getLevelSensor(uint8_t number)
{
    if (number >= m_levelSensorsNum)
        return nullptr;

    return m_levelSensors[m_levelSensorsNum - 1];
}

template <typename T>
uint8_t Tank<T>::getSensorsNum() const
{
    return m_levelSensorsNum;
}

template <typename T>
typename Tank<T>::Status Tank<T>::getStatus() const
{
    if (m_levelSensorsNum == 0)
        return Status::Error;

    if (m_levelSensorsNum == 1)
        return m_levelSensors->getData() ? Status::Full : Status::NotFull;

    /// Error if higher sensor is activated but lower isn't
    for (uint8_t i = 1; i < m_levelSensorsNum; ++i)
        if (!m_levelSensors[i - 1].getData() && m_levelSensors[i].getData())
            return Status::Error;

    return m_levelSensors[m_levelSensorsNum - 1].getData() ?
            Status::Full : Status::NotFull;
}

template <typename T>
T* Tank<T>::getLowerLevelSensor()
{
    if (m_levelSensorsNum == 0)
        return nullptr;

    return m_levelSensors;
}

template <typename T>
T* Tank<T>::getUpperLevelSensor()
{
    if (m_levelSensorsNum == 0)
        return nullptr;

    return m_levelSensors[m_levelSensorsNum - 1];
}

template <typename T>
bool Tank<T>::isFull() const
{
    return getStatus() == Status::Full;
}

template <typename T>
void Tank<T>::update()
{
    for (uint8_t i = 0; i < m_levelSensorsNum; ++i)
        m_levelSensors[i].update();
}
