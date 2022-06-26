#include "Controller.h"

#include "PinImpl.h"

Controller::Controller(PumpController* pc, uint8_t errorLampPin,
                       uint8_t bioRecirculationPin)
    : m_state{On}
    , m_pc{pc}
    , m_errorLamp{errorLampPin}
    , m_bioRecirculation{bioRecirculationPin}
{
}

void Controller::setState(State state)
{
    if (state != m_state)
        m_state = state;
}

Controller::State Controller::getState() const
{
    return m_state;
}

void Controller::setMode(PumpController::Mode mode)
{
    m_pc->setMode(mode);
}

PumpController::Mode Controller::getMode() const
{
    return m_pc->getCurrentMode();
}

void Controller::operate()
{
    switch (m_state) {
        case On : {
            switchPinOff(m_errorLamp);
            switchPinOn(m_bioRecirculation);

            const bool isManualPumpOn = m_pc->front()->pump->isOn();

            m_state = m_pc->operate(isManualPumpOn) ? On : Error;
        }
        break;

        case Error : {
            m_pc->switchPumpsOff();

            switchPinOff(m_bioRecirculation);
            switchPinOn(m_errorLamp);
        }
        break;

        default : {}
    }
}

void Controller::update()
{
    m_pc->update();
}
