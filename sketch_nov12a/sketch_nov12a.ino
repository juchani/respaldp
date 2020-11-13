#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
SoftwareSerial SIM800L(9, 10); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  SIM800L.begin(9600);

  Serial.println("Initializing..."); 
}

void loop()
{
  updateSerial();
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    SIM800L.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(SIM800L.available()) 
  {
    Serial.write(SIM800L.read());//Forward what Software Serial received to Serial Port
  }
}
