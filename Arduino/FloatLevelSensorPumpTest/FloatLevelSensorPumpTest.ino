#include "Pump.h"
#include "Sensors.h"

Pump p(3);

FloatLevelSensor sensor0(5);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  sensor0.update();

  if (sensor0.getData()) {
    p.on();
    Serial.println("Button has been pressed!");
  }
  else
    p.off();
}
