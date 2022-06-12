#include "SensorsImpl.h"

namespace MockSensorsImpl {

void setFloatLevelSensorData(bool flag);
bool isUpdated();

} // namespace MockSensorsImpl

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

template <uint8_t mode, uint8_t key>
bool getFloatLevelSensorData(EncButton<mode, key>&)
{
    return data;
}

template <uint8_t mode, uint8_t key>
uint8_t updateFloatLevelSensorData(EncButton<mode, key>&)
{
    isUpdatedFlag = true;

    return {};
}
