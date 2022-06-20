#include "MockSensorsImpl.h"

template bool getFloatLevelSensorData<1>(EncButton2<1>& arduinoButton);
template uint8_t updateFloatLevelSensorData<1>(EncButton2<1>& arduinoButton);

namespace {

bool data{};
bool isUpdatedFlag{};

} // namespace

void MockSensorsImpl::setFloatLevelSensorData(bool flag)
{
    data = flag;
}

bool MockSensorsImpl::isUpdated()
{
    return isUpdatedFlag;
}

template <uint8_t type, uint8_t mode>
bool getFloatLevelSensorData(EncButton2<type, mode>&)
{
    return data;
}

template <uint8_t type, uint8_t mode>
uint8_t updateFloatLevelSensorData(EncButton2<type, mode>&)
{
    isUpdatedFlag = true;

    return {};
}
