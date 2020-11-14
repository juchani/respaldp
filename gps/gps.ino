#include <SoftwareSerial.h>
#include <TinyGPS.h>
SoftwareSerial GPS(11, 10);
TinyGPS gps;
String mensaje;
void setup()
{
  Serial.begin(9600);
  GPS.begin(9600);
}

void loop()
{
  bool datos = false;
  unsigned long chars;
  unsigned short sentences, failed;

  for (unsigned long start = millis(); millis() - start < 1000;)
  {
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
    flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6;
    flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6;
    mensaje = "LA UBICACION DEL DIPOSITIVO ES :" + String(flat,6) + "," + String(flon,6);
  }
Serial.println(mensaje);
  gps.stats(&chars, &sentences, &failed);

  if (chars == 0) {
 
  }

}
