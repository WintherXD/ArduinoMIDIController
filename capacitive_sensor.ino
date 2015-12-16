#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(2,3);
CapacitiveSensor capSensor2 = CapacitiveSensor(2,4);
CapacitiveSensor capSensor3 = CapacitiveSensor(2,5);

const int potPin = 0;
int pot_valor_old = 0;
boolean pin_touched_old = false;
boolean pin2_touched_old = false;
boolean pin3_touched_old = false;


void setup() {
  Serial.begin(9600);
}

void loop() {
  loopOut();
  loopIn();
  play();
  loopSize();
  delay(100);
}

void loopOut() {
  long sensorValue = capSensor.capacitiveSensor(30);
  
  if(sensorValue > 100) {
    if(pin_touched_old == false) {
      Serial.write(1+0xB0);
      Serial.write(1);
      Serial.write(127);
      pin_touched_old = true;
    }
  } else {
    pin_touched_old = false;
  }
}

void loopIn() {
  long sensorValue2 = capSensor2.capacitiveSensor(30);
  
  if(sensorValue2 > 100) {
    if(pin2_touched_old == false) {
      Serial.write(1+0xB0);
      Serial.write(2);
      Serial.write(127);
      pin2_touched_old = true;
    }
  } else {
    pin2_touched_old = false;
  }
}

void play() {
  long sensorValue3 = capSensor3.capacitiveSensor(30);
  
  if(sensorValue3 > 100) {
    if(pin3_touched_old == false) {
      Serial.write(1+0xB0);
      Serial.write(3);
      Serial.write(127);
      pin3_touched_old = true;
    }
  } else {
    pin3_touched_old = false;
  }
}

void loopSize() {
  if(analogRead(0) != pot_valor_old) {
    Serial.write(1+0xB0);
    Serial.write(4);
    Serial.write(analogRead(0)/8);
    pot_valor_old = analogRead(0);
  }
}

