#include <InductiveSensor.h>

InductiveSensor sensor(12, "NPN"); //initialization

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  if(sensor.approach() == true){
    digitalWrite(13, HIGH);
  }
  else{digitalWrite(13, LOW);}
}
