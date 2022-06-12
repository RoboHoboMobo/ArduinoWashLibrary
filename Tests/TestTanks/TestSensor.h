#include "Common.h"

class TestSensor
{
public:
    TestSensor(uint8_t pin);

    bool getData();
    void update();

    uint8_t getPin() const;
    void setData(bool data);
    bool isUpdated() const;

private:
    uint8_t m_pin;
    bool m_data;
    bool m_isUpdated;
};
