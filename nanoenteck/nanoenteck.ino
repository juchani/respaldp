#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 8); //SIM800L Tx & Rx is connected to Arduino #3 & #2
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
  if(c==1){
 // texto.remove('\n');
  Serial.print(texto);
  c=0;
  }
}

void updateSerial()
{

  while (mySerial.available())
  {
    texto += (char)mySerial.read();
    c = 1;
  }

}
