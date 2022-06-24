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

bool Tank::isEmpty()
{
    return getStatus() == Empty;
}


bool Tank::isFull()
{
    return getStatus() == Full;
}

void Tank::update()
{
    const uint8_t n = getLevelSensorsNum();

    if (!n)
        return;

    Sensor** sensors = getLevelSensors();

    for (uint8_t i = 0; i < n; ++i)
        sensors[i]->update();
}
