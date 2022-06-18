#include "Tank.h"

/**
  * @class Tank
  */

bool Tank::isDrainable()
{
    return getStatus() != Empty;
}

bool Tank::isFillable()
{
    return getStatus() != Full;
}

bool Tank::isFull()
{
    return getStatus() == Full;
}

void Tank::update()
{
    uint8_t n = getLevelSensorsNum();

    for (uint8_t i = 0; i < n; ++i)
        getLevelSensor(i)->update();
}
