#define BLYNK_PRINT DebugSerial
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>
BlynkTimer timer;
char auth[] = "05403f5874484616bb16cfb2f1aa70ca";
const int sensorPin= A0;
 
void setup()
{
  pinMode(8,OUTPUT);
  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
 timer.setInterval(1000L, temperatura);
}


 
void temperatura()
{
  int value = analogRead(sensorPin);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  //Serial.print(celsius);  
 
  Blynk.virtualWrite(V6,celsius);
  //Serial.println(" C");
 
  delay(1000);
}
  void loop()
{
  Blynk.run();
  timer.run();
}



