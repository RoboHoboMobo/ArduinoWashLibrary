#include "MockArduinoButtonImpl.h"

namespace {

bool isHold{};
uint8_t updateButtonResult{};

} // namespace

void MockArduinoButtonImpl::setIsButtonHold(bool flag)
{
    isHold = flag;
}

void MockArduinoButtonImpl::setUpdateButtonResult(uint8_t value)
{
    updateButtonResult = value;
}

bool isButtonHold()
{
    return isHold;
}

uint8_t updateButton()
{
    return updateButtonResult;
}

