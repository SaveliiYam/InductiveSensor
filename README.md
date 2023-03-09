# InductiveSensor
Библиотека предназначена для работы с индуктивными датчиками с NPN и PNP структурой.
Так как рабочее напряжение для индуктивных датчиков минимум 6В, то необходимо использовать развязку в виде реле или оптопары.

## Установка
- Скачать библиотеку архивом для ручной установки:
- Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
- Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
- Распаковать и положить в *Документы/Arduino/libraries/*
- (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
## Инициализация
```cpp
InductiveSensor sensor(pin); // Инициализация пина датчика, вероятнее всего вы будете использовать реле или оптрон перед датчиком, 
// т.к. датчик вряд-ли можно подключить к микроконтроллеру
```
## Использование
```cpp
void targetMetall(); // Если на к датчикуприближается металлический объект, то выведет true
```
## Примеры 
```cpp
#include <InductiveSensor.h>

InductiveSensor sensor(12); //initialization

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  if(sensor.targetMetall() == true){
    digitalWrite(13, HIGH);
  }
  else{digitalWrite(13, LOW);}
}
```
