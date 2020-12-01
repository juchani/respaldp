#include <SoftwareSerial.h>
#include <TinyGPS.h>
SoftwareSerial SIM800L(10, 9); //SIM800L Tx & Rx is connected to Arduino #3 & #2
SoftwareSerial GPS(7, 8);
TinyGPS gps;

String texto = "";
String mensaje;
int led = 13, relay = A1, c;
bool st = 0, sta = 0;
void setup()
{

  Serial.begin(9600);
  GPS.begin(9600);
  SIM800L.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  digitalWrite(relay, sta);
  SIM800L.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  SIM800L.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  SIM800L.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
  ubicacion();
}

void loop()
{
  //
  updateSerial();
  c++;
  digitalWrite(relay, sta);

  if (c > 20) {
    ubicacion();
    c = 0;
  }
  if (digitalRead(A0) == 0) {

    sms();
  }

  if (st == 1) {

    sms();
    st = 0;
  }
}

void ubicacion() {


  bool datos = false;
  unsigned long chars;
  unsigned short sentences, failed;

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
    flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6;
    flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6;
    mensaje = "LA UBICACION DEL DIPOSITIVO ES :" + String(flat, 6) + "," + String(flon, 6);
  }
  // Serial.println(mensaje);
  gps.stats(&chars, &sentences, &failed);
    Serial.println();
}

void updateSerial()
{
  SIM800L.listen();
  delay(500);
  //Serial.println(texto);


  while (SIM800L.available() > 0)
  {
    texto += (char)SIM800L.read();
    //Serial.println(texto);
    if (texto.indexOf("Ubicacion") > -1) {
      texto = "";
      st = 1;

    }
    if (texto.indexOf("Iniciar alarma") > -1) {

      texto = "";
      //st=1;
      sta = !sta;

    }
  Serial.println();
  }




}

void sms() {
  digitalWrite(led, HIGH);
  SIM800L.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  SIM800L.println("AT+CMGS=\"63438720\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  SIM800L.println("MENSAJE RECIBIDO:"); //text content
  SIM800L.print(mensaje); //text content
  updateSerial();
  SIM800L.write(26);
  digitalWrite(led, LOW);
}
