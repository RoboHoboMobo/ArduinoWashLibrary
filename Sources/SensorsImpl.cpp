#include "SensorsImpl.h"
#include "SensorsImplDef.h"

template bool getFloatLevelSensorData<0>(EncButton<0>& arduinoButton);
template uint8_t updateFloatLevelSensorData<0>(EncButton<0>& arduinoButton);