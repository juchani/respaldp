#include <SoftwareSerial.h>
#include <TinyGPS.h>
SoftwareSerial SIM800L(9,10); //SIM800L Tx & Rx is connected to Arduino #3 & #2
SoftwareSerial GPS(8, 7);
TinyGPS gps;

String texto = "", numero = "71066743";
String mensaje;
int led = 13,c;
bool st = 0;
void setup()
{

  //Serial.begin(9600);
  GPS.begin(9600);
  SIM800L.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  
  SIM800L.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  SIM800L.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  SIM800L.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
  //ubicacion();
}

void loop()
{
//
updateSerial();
c++;

 // Serial.println(c);
 if(c>20){
  ubicacion();
c=0;  
 }
  if (digitalRead(A0) == 0) {
    
    sms();
  }
 
  if (st == 1) {
   
    sms();
    st = 0;
  }
}

void ubicacion(){
  
  
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
}

void updateSerial()
{
  delay(500);
  //Serial.println(texto);

  SIM800L.listen();
   while (SIM800L.available())
  {
    texto += (char)SIM800L.read();
    //Serial.println(texto);
    if (texto.indexOf("Iniciar alarma") > -1) {
    
    texto = "";
    st=1;

  }

  }
  

  

}

void sms(){
  
//  Serial.print("aceptado... ");
 //   Serial.println();
    //SIM800L.listen();
    digitalWrite(led,HIGH);
    SIM800L.println("AT+CMGF=1"); // Configuring TEXT mode
    updateSerial();
    SIM800L.println("AT+CMGS=\"71066743\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
    updateSerial();
    SIM800L.println("MENSAJE RECIBIDO:"); //text content
    SIM800L.print(mensaje); //text content
    updateSerial();
    SIM800L.write(26);
    digitalWrite(led,LOW);
}
