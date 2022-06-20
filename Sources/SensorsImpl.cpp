#include "SensorsImpl.h"
#include "SensorsImplDef.h"

template bool getFloatLevelSensorData<1>(EncButton2<1>& arduinoButton);
template uint8_t updateFloatLevelSensorData<1>(EncButton2<1>& arduinoButton);
