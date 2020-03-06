#include <Servo.h>
Servo servo1, servo2, servo3, servo4, servo5;
#include "SingleEMAFilterLib.h"
SingleEMAFilter<int> singleEMAFilter(0.09);

int angulo1;
int angulo2;
int angulo3;
int angulo4;
int angulo5;
void setup() {
  Serial.begin(9600);
  servo1.attach(6);
  servo2.attach(7);
  servo3.attach(8);
  servo4.attach(9);
  servo5.attach(10);
}

void loop() {
  int sensorValue2 = analogRead(A4);
  int sensorValue1 = analogRead(A3);
  int sensorValue3 = analogRead(A5);
  int sensorValue4 = analogRead(A6);
  int sensorValue5 = analogRead(A7);
  singleEMAFilter.AddValue(sensorValue1);
  singleEMAFilter.AddValue(sensorValue2);
  singleEMAFilter.AddValue(sensorValue3);
  singleEMAFilter.AddValue(sensorValue4);
  singleEMAFilter.AddValue(sensorValue5);
  Serial.println(sensorValue2);
  delay(50);        // delay in between reads for stability
  if (Serial.available()) {
    char da = Serial.read();
    if (da == '1') {
      angulo1 = map(sensorValue2,860, 890, 180,0 );
      servo1.write(angulo1);
    }
    if (da == '2') {
      angulo2 = map(sensorValue2,860, 890, 180, 0);
      servo2.write(angulo2);
    }
    if (da == '3') {
      angulo3 = map(sensorValue2,860, 890, 180, 0);
      servo3.write(angulo3);
    }
    if (da == '4') {
      angulo4 = map(sensorValue2,860, 890, 0, 180);
      servo4.write(angulo4);
    }
    if (da == '5') {
      angulo5 = map(sensorValue2, 860, 890, 180, 0);
      servo5.write(angulo5);
    }
  }

}
