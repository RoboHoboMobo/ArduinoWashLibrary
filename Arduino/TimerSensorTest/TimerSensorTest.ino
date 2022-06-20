#include "Timer.h"
#include "Sensors.h"

Timer t(60000);

FloatLevelSensor sensor0(3);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  t.update();
  sensor0.update();

  if (sensor0.getData()) {
    t.start();
    Serial.println("Button has been pressed!");
  }

  if (t.getState() == Timer::Running)
    Serial.println(t.getRemainingTime());

  if (t.isDone()) {
    Serial.println("Timer is Done!");

    t.reset(t.getDuration());
  }
}
