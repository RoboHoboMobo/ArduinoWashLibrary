#include "PumpController.h"

#include "TestTank.h"

// Таймеры
Timer timer0(30000, true);
Timer timer1(30000, true);
Timer timer2(30000, true);
Timer timer3(30000, true);

// Резервуары и насосы
TestTank tank0(2, 3); // Tank(нижний датчик уровня, верхний датчик уровня)
Pump p01(4);

TestTank tank1(5, 6);
Pump p12(7);

TestTank tank2(8, 9);
Pump p23(10);

TestTank tank3(11, 12);
Pump p34(13);

TestTank tank4(14, 15);

// Узлы
Node node0(&p01, &tank0, &tank1, &timer0);
Node node1(&p12, &tank1, &tank2, &timer1);
Node node2(&p23, &tank2, &tank3, &timer2);
Node node3(&p34, &tank3, &tank4, &timer3);

// Контроллер узлов
PumpController pc;

void setup()
{
  Serial.begin(9600);

  // Настраиваем пины насосов
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);

  // Добавляем узлы к контроллеру
  pc.pushBack(&node0);
  pc.pushBack(&node1);
  pc.pushBack(&node2);
  pc.pushBack(&node3);
}

void loop()
{
  timer0.update();
  timer1.update();
  timer2.update();
  timer3.update();

  pc.update();
  pc.operate(true); // PumpController::operate(bool flag), где flag - флаг, что нужно обрабатывать с последнего узла


  if (timer0.getState() == Timer::Running) {
    Serial.print("timer0: ");
    Serial.println(timer0.getRemainingTime());
  }

  if (timer1.getState() == Timer::Running) {
    Serial.print("timer1: ");
    Serial.println(timer1.getRemainingTime());
  }

  if (timer2.getState() == Timer::Running) {
    Serial.print("timer2: ");
    Serial.println(timer2.getRemainingTime());
  }

  if (timer3.getState() == Timer::Running) {
    Serial.print("timer3: ");
    Serial.println(timer3.getRemainingTime());
  }

  Node::State st0 = node0.getState();
  Node::State st1 = node1.getState();
  Node::State st2 = node2.getState();
  Node::State st3 = node2.getState();

  Serial.print("Node0: ");
  Serial.println(st0);

  Serial.print("Node1: ");
  Serial.println(st1);

  Serial.print("Node2: ");
  Serial.println(st2);

  Serial.print("Node3: ");
  Serial.println(st3);
}
