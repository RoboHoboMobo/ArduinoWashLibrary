#pragma once

#include "Tank.h"

#include "TestSensor.h"

class TestTank : public Tank
{
public:
    Sensor* getLevelSensor(uint8_t number) override;
    Sensor** getLevelSensors() override;
    uint8_t getLevelSensorsNum() const override;
    Status getStatus() override;

    Sensor* getLowerLevelSensor() override;
    Sensor* getUpperLevelSensor() override;

    virtual bool isDrainable() override;

    virtual bool isFillable() override;

    void setStatus(Tank::Status);
    void setIsDrainable(bool flag);
    void setIsFillable(bool flag);

private:
    Tank::Status m_status{};
    bool m_isDrainable{};
    bool m_isFillable{};
};
