#pragma once

#include "Tank.h"

#include "TestSensor.h"

class TestTank : public Tank
{
public:
    Sensor* getLevelSensor(uint8_t number) override;
    uint8_t getLevelSensorsNum() const override;
    Status getStatus() override;

    Sensor* getLowerLevelSensor() override;
    Sensor* getUpperLevelSensor() override;

    void setStatus(Tank::Status);
};
