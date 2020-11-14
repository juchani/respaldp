#include <SoftwareSerial.h>
SoftwareSerial gsm(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2
#include <TinyGPS.h>
SoftwareSerial GPS(11, 10);
TinyGPS gps;
String texto = "", coordenadas = "";
String sms[] = {"alarma activada", "alarma desactivada"};
bool estado = 1;
byte  c = 0;
void setup()
{

  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT");
ubicacion();  
}

void loop()
{
  if (c > 30) {
    ubicacion();
    c = 0;
  }
  verificar();
  c++;
}

void verificar()
{

  delay(500);
  //Serial.println(texto);

  gsm.listen();
  while (gsm.available())
  {
    texto += (char)gsm.read();
    Serial.println(texto);
    if (texto.indexOf("RING") > -1) {
      Serial.println("aceptado");
      estado = !estado;
      delay(1000);
      gsm.println("ATA");
      delay(3000);
      gsm.println("ATH");
      delay(4000);
      gsm.println("AT+CMGF=1"); // Configuring TEXT mode
      delay(500);
      gsm.println("AT+CMGS=\"71066743\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
      delay(500);
      gsm.println(sms[estado]); //text content
      gsm.print(coordenadas); //text content
      delay(500);
      gsm.write(26);

      texto = "";
    }

  }
}



void ubicacion() {
  bool datos = false;
  unsigned long chars;
  unsigned short sentences, failed;
  GPS.begin(9600);
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    GPS.listen();
    while (GPS.available())
    {
      char c = GPS.read();

      if (gps.encode(c))
        datos = true;
    }
  }

  if (datos)
  {
    float flat, flon;
    gps.f_get_position(&flat, &flon);
    flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 10;
    flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 10;
    coordenadas = String(flat, 10) + "," + String(flon, 10);
  }
  Serial.println(coordenadas);
  gps.stats(&chars, &sentences, &failed);

  if (chars == 0) {

  }
  GPS.end();
}
