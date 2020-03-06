#include "SingleEMAFilterLib.h"

 SingleEMAFilter<int> singleEMAFilter(0.05);

void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(12,OUTPUT);
}


void loop() {
  // read the input on analog pin 0:
  int sensorValue =pulseIn(8,LOW);
  sensorValue=sensorValue;
  Serial.print(0);
Serial.print("  ");
  Serial.print(sensorValue);
digitalWrite(12,!digitalRead(8));
sensorValue =singleEMAFilter.AddValue(sensorValue );

  Serial.print("  ");
  Serial.println(sensorValue);

  delay(10);        // delay in between reads for stability
}
