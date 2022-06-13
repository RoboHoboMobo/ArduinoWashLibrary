#include "MockSensorsImpl.h"

template bool getFloatLevelSensorData<0>(EncButton<0>& arduinoButton);
template uint8_t updateFloatLevelSensorData<0>(EncButton<0>& arduinoButton);

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

template <uint8_t mode>
bool getFloatLevelSensorData(EncButton<mode>&)
{
    return data;
}

template <uint8_t mode>
uint8_t updateFloatLevelSensorData(EncButton<mode>&)
{
    isUpdatedFlag = true;

    return {};
}
