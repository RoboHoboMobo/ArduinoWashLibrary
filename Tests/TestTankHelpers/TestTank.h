#pragma once

#include "Tank.h"

#include "TestSensor.h"

#include <vector>

class TestTank : public Tank
{
public:
    TestTank();

    Sensor* getLevelSensor(uint8_t number) override;
    Sensor** getLevelSensors() override;
    uint8_t getLevelSensorsNum() const override;
    Status getStatus() override;

    Sensor* getLowerLevelSensor() override;
    Sensor* getUpperLevelSensor() override;

    bool isNeedEmergencyPumping() override;

    void setSensorsData(const std::vector<bool>&);

private:
    static constexpr uint8_t m_levelSensorsNum{4};

    TestSensor m_s0;
    TestSensor m_s1;
    TestSensor m_s2;
    TestSensor m_s3;
    Sensor* m_sensors[m_levelSensorsNum];
};
