#pragma once

#include "Tank.h"

/**
 * @brief Возвращает значения датчиков уровня резервуара в виде битовой маски
 */
uint8_t getFloatLevelSensorsDataMask(Tank& tank);
