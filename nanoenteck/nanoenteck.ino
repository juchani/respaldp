#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 15); //SIM800L Tx & Rx is connected to Arduino #3 & #2
String texto = "";
bool c;
void setup()
{
  Serial.begin(9600);

  mySerial.begin(9600);

}

void loop()
{
  updateSerial();
  
}

void updateSerial()
{

  while (mySerial.available())
  {
    texto += (char)mySerial.read();
  }
Serial.println(texto);
}
