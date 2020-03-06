#include <SoftwareSerial.h>
#include <TinyGPS.h>
TinyGPS gps;
SoftwareSerial ss(10, 11);
SoftwareSerial sim800l(7, 8);
String ubicacion;
int botton = 9;
void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
  //sim800l.begin(9600);
  pinMode(9, INPUT_PULLUP);

}

void loop()
{
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (ss.available())
    {
      char c = ss.read();
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }

  if (newData)
  {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    ubicacion = String(flat, 6) + "," + String(flon, 6);

  }
if(digitalRead(botton)==0){
  
  Serial.println(ubicacion);
  delay(1000);
  Serial.println("AT"); //Once the handshake test is successful, it will back to OK
  delay(500);
  Serial.println("AT+CMGF=1"); 
  delay(500);
  Serial.println("AT+CMGS=\"+59169122887\"");
  delay(500);
  Serial.print("creo que estoy en peligro " + ubicacion); 
  delay(500);
  Serial.write(26);
}
  

    gps.stats(&chars, &sentences, &failed);
  
  if (chars == 0)
    Serial.println("** No characters received from GPS: check wiring **");
}



