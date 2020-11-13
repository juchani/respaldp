#include <TinyGPS.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); //SIM800L Tx & Rx is connected to Arduino #9 & #10
TinyGPS gps;
int led = 13;
String mens aje;
String texto = "", numero = "71066743";
bool st = 0;

void setup()
{

  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
}

void loop()
{
  //ubicacion();
  if (digitalRead(A0) == 0) {
    sms();
  }
  updateSerial();
  if (st == 1) {
    sms();
    st = 0;
  }
}

void updateSerial()
{
  delay(500);

  while (mySerial.available())
  {
    texto += (char)mySerial.read();
    if (texto.indexOf("Iniciar alarma") > -1) {

      texto = "";
      st = 1;

    }

  }

}

void sms() {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite( led, LOW);
  delay(500);
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"71066743\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print(mensaje); //text content
  updateSerial();
  mySerial.write(26);

}

void ubicacion() {
  
  bool datos = false;
  unsigned long chars;
  unsigned short sentences, failed;

  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (Serial.available())
    {
      char c = Serial.read();

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
    mensaje = "LA UBICACION DEL DIPOSITIVO ES :" + String(flat, 6) + "," + String(flon, 6);
    digitalWrite(led, HIGH);
  }

  gps.stats(&chars, &sentences, &failed);

  if (chars == 0) {
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
  }
  
}
