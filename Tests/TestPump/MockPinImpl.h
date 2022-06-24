#pragma once

#include "PinImpl.h"

#include "Common.h"

namespace MockPinImpl {

uint8_t getPin();
bool getPinCurrentState();

void reset();

} // namespace MockPinImpl
