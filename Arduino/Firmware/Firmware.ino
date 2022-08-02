#include "Controller.h"

#include "Well.h"
#include "Cube.h"
#include "Primer.h"
#include "Bio.h"
#include "Concentrator.h"

/** Константы - номера пинов и т.д. **/

// Пины управления и состояния системы
const uint8_t errorAlarmLampPin = D13;    // Лампа ошибки
const uint8_t resetErrorButtonPin = D12;  // Кнопка сброса состояния ошибки 
const uint8_t modePin = D11;              // Тумблер выбора режима (0 - стандартный режим, 1 - ночной режим)
const uint8_t manualPumpSwitchPin = D10;  // Проверка состояния (вкл/выкл) тумблера ручного насоса приямок->куб

// Таймауты кнопок и тумблеров, мс (до 8 000)
const int resetErrorButtonTimeout = 2000;
const int modeSwitchTimeout = 200;

// Пины насосов
const uint8_t cubePrimerPumpPin = D31;      // Насос куб->первак
const uint8_t primerBioPumpPin = D33;       // Насос первак->био
const uint8_t bioConcentratorPumpPin = D39; // Насос био->концентратор (накачка/рециркуляция)

const uint8_t bioRelayPin = D34; // Реле насоса био

// Пины датчиков
const uint8_t cubeFloatLevelSensorPin0 = D2;   // Нижний датчик уровня в кубе
const uint8_t cubeFloatLevelSensorPin1 = D3;   // Верхний датчик уровня в кубе

const uint8_t primerFloatLevelSensorPin0 = D4; // Нижний датчик уровня в перваке
const uint8_t primerFloatLevelSensorPin1 = D5; // Верхний датчик уровня в перваке

const uint8_t bioFloatLevelSensorPin0 = D6;    // Датчик уровня в био 25% (нижний)
const uint8_t bioFloatLevelSensorPin1 = D7;    // Датчик уровня в био 50%
const uint8_t bioFloatLevelSensorPin2 = D8;    // Датчик уровня в био 75%
const uint8_t bioFloatLevelSensorPin3 = D9;    // Датчик уровня в био 100% (верхний)

const uint8_t concentratorFloatLevelSensorPin0 = D35;   // Датчик уровня в концентраторе 25% (нижний)
const uint8_t concentratorFloatLevelSensorPin1 = D36;   // Датчик уровня в концентраторе 50%
const uint8_t concentratorFloatLevelSensorPin2 = D37;   // Датчик уровня в концентраторе 75%
const uint8_t concentratorFloatLevelSensorPin3 = D38;   // Датчик уровня в концентраторе 100% (верхний)

// Значения таймеров (мс)
//const uint32_t wellManualPumpTimer = 600000;
//const uint32_t cubePrimerPumpTimer = 1200000;
//const uint32_t primerBioPumpTimer  = 3600000;
//const uint32_t bioConcentratorPumpTimer = 0;

const uint32_t wellManualPumpTimer = 120000;
const uint32_t cubePrimerPumpTimer = 240000;
const uint32_t primerBioPumpTimer  = 3600000;
const uint32_t bioConcentratorPumpTimer = 0;

/** Переменные - кнопки, насосы, резервуары и т.д. **/

// Кнопки и тумблеры
EncButton2<EB_BTN> resetErrorButton(INPUT_PULLUP, resetErrorButtonPin); // Кнопка сброса ошибки
EncButton2<EB_BTN> modeSwitch(INPUT_PULLUP, modePin);                   // Тумблер выбора режима (0 - стандартный режим, 1 - ночной режим)

// Резервуары и насосы
Well well; // Приямок
Cube cube({cubeFloatLevelSensorPin0, cubeFloatLevelSensorPin1}); // Куб
Primer primer({primerFloatLevelSensorPin0, primerFloatLevelSensorPin1}); // Первак

Bio bio({bioFloatLevelSensorPin0, bioFloatLevelSensorPin1,
         bioFloatLevelSensorPin2, bioFloatLevelSensorPin3}); // Био
         
Concentrator concentrator({concentratorFloatLevelSensorPin0, concentratorFloatLevelSensorPin1,
                           concentratorFloatLevelSensorPin2, concentratorFloatLevelSensorPin3}); // Концентратор

Pump p01;                    // Ручной насос приямок->куб
Pump p12(cubePrimerPumpPin); // Насос куб->первак
Pump p23(primerBioPumpPin);  // Насос первак->био         
Pump p34(bioConcentratorPumpPin); // Насос био->концентратор

// Таймеры
Timer timer0(wellManualPumpTimer, true);
Timer timer1(cubePrimerPumpTimer, true);
Timer timer2(primerBioPumpTimer, true);
Timer timer3(bioConcentratorPumpTimer, true);

// Узлы
Node node0(&p01, &well, &cube, &timer0);
Node node1(&p12, &cube, &primer, &timer1);
Node node2(&p23, &primer, &bio, &timer2);
Node node3(&p34, &bio, &concentrator, &timer3);

// Контроллер узлов
PumpController pc;

// Контроллер системы
Controller c(&pc, errorAlarmLampPin, bioRelayPin);

void serialTestPrint()
{
  Serial.println("Таймеры");
  Serial.print("Timer0 - Приямок->Куб: ");
  Serial.println(timer0.getRemainingTime());

  Serial.print("Timer1 - Куб->Первак: ");
  Serial.println(timer1.getRemainingTime());

  Serial.print("Timer2 - Первак->Био: ");
  Serial.println(timer2.getRemainingTime());

  Serial.print("Timer3 - Био->Концентрат: ");
  Serial.println(timer3.getRemainingTime());

  Serial.println("//////////////////////////////////");

  Serial.print("Статус приямка: ");
  Serial.println(well.getStatus());
  
  Serial.print("Статус куба: ");
  Serial.println(cube.getStatus());
  
  Serial.print("Статус первака: ");
  Serial.println(primer.getStatus());
  
  Serial.print("Статус био: ");
  Serial.println(bio.getStatus());

  Serial.print("Статус концентрата: ");
  Serial.println(concentrator.getStatus());

  Serial.println("//////////////////////////////////");

  Serial.print("Узел приямок->куб может качать: ");
  Serial.println(node0.canPumping());

  Serial.print("Узел куб->первак может качать: ");
  Serial.println(node1.canPumping());
  
  Serial.print("Узел первак->био может качать: ");
  Serial.println(node2.canPumping());

  Serial.print("Узел био->концентрат может качать: ");
  Serial.println(node3.canPumping());

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
}

void setup()
{
   Serial.begin(9600);
  // Настраиваем пины управления, состояния
  pinMode(manualPumpSwitchPin, INPUT); // Будем проверять тумблер ручного насоса
  pinMode(errorAlarmLampPin, OUTPUT);

  pinMode(bioRelayPin, OUTPUT); // Настраиваем пин для управления мотором (био -> концентратор)

  // Настраиваем кнопки и тумблеры
  resetErrorButton.setHoldTimeout(resetErrorButtonTimeout);
  modeSwitch.setHoldTimeout(modeSwitchTimeout);
  
  // Добавляем узлы к контроллеру
  pc.pushBack(&node0);
  pc.pushBack(&node1);
  pc.pushBack(&node2);
  pc.pushBack(&node3);
}

void loop()
{
  c.update(); // Обновить узлы (показания датчиков, таймеры)

  if (digitalRead(manualPumpSwitchPin)) // Читаем значения тумблера ручного насоса
    node0.on();
  else
    node0.finish();

  /** Управление состоянием системы **/
  if (c.getState() == Controller::Error && resetErrorButton.hold()) // Нажата кнопка сброса ошибки
    c.setState(Controller::On);

  /** Управление режимом работы **/
  if (modeSwitch.hold())                  // Тумблер ВКЛ (замыкает землю)
    c.setMode(PumpController::NightMode);
  else                                    // Тумблер ВЫКЛ (не замыкает землю)
    c.setMode(PumpController::DefaultMode);

  c.operate(); // Управление системой

  serialTestPrint(); // Вывести данные таймеров в serial
}
