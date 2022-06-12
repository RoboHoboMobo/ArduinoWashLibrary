#pragma once

#include "Common.h"

enum TankStatus
{
    NotFull = 0,
    Full,
    Error = 0xFF
};

/**
 * @brief Base class for reservoirs
 */
template<typename SensorType, uint8_t sensorsNum = 0>
class Tank
{
public:
    Tank(SensorType* levelSensors);

    SensorType* getLevelSensor(uint8_t number);
    uint8_t getSensorsNum() const;
    TankStatus getStatus() const;

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
    TankStatus m_status;
};

template <typename T, uint8_t sensorsNum>
Tank<T, sensorsNum>::Tank(T* levelSensors)
    : m_levelSensors{levelSensors}
    , m_levelSensorsNum{sensorsNum}
    , m_status{}
{
    m_status = getStatus();
}

template <typename T, uint8_t sensorsNum>
T* Tank<T, sensorsNum>::getLevelSensor(uint8_t number)
{
    if (m_levelSensorsNum == 0 || number >= m_levelSensorsNum)
        return nullptr;

    return m_levelSensors + m_levelSensorsNum - 1;
}

template <typename T, uint8_t sensorsNum>
uint8_t Tank<T, sensorsNum>::getSensorsNum() const
{
    return m_levelSensorsNum;
}

template <typename T, uint8_t sensorsNum>
TankStatus Tank<T, sensorsNum>::getStatus() const
{
    if (m_levelSensorsNum == 0)
        return TankStatus::Error;

    if (m_levelSensorsNum == 1)
        return m_levelSensors->getData() ? TankStatus::Full : TankStatus::NotFull;

    /// Error if higher sensor is activated but lower isn't
    for (uint8_t i = 1; i < m_levelSensorsNum; ++i)
        if (!m_levelSensors[i - 1].getData() && m_levelSensors[i].getData())
            return TankStatus::Error;

    return m_levelSensors[m_levelSensorsNum - 1].getData() ?
            TankStatus::Full : TankStatus::NotFull;
}

template <typename T, uint8_t sensorsNum>
T* Tank<T, sensorsNum>::getLowerLevelSensor()
{
    if (m_levelSensorsNum == 0)
        return nullptr;

    return m_levelSensors;
}

template <typename T, uint8_t sensorsNum>
T* Tank<T, sensorsNum>::getUpperLevelSensor()
{
    if (m_levelSensorsNum == 0)
        return nullptr;

    return m_levelSensors + m_levelSensorsNum - 1;
}

template <typename T, uint8_t sensorsNum>
bool Tank<T, sensorsNum>::isFull() const
{
    return getStatus() == TankStatus::Full;
}

template <typename T, uint8_t sensorsNum>
void Tank<T, sensorsNum>::update()
{
    for (uint8_t i = 0; i < m_levelSensorsNum; ++i)
        m_levelSensors[i].update();
}
