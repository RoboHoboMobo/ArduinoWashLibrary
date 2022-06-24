#include "TankHelpers.h"

uint8_t getFloatLevelSensorsDataMask(Tank& tank)
{
    uint8_t result{};

    const uint8_t levelSensorsNum = tank.getLevelSensorsNum();
    Sensor** sensors = tank.getLevelSensors();

    if (!levelSensorsNum || !sensors)
        return result;

    for (uint8_t i = 0; i < levelSensorsNum; ++i)
        result |= static_cast<BinarySensor*>(sensors[i])->getData() << i;

    return result;
}
