#include <SoftwareSerial.h>
SoftwareSerial SIM800L(9,10); //SIM800L Tx & Rx is connected to Arduino #3 & #2
String texto = "", numero = "71066743";
bool st=0;
void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);

  //Begin serial communication with Arduino and SIM800L
  SIM800L.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  SIM800L.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  SIM800L.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  SIM800L.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
}

void loop()
{
  updateSerial();
  if (st==1){
    sms();
    st=0;
  }
}

void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
   SIM800L.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (SIM800L.available())
  {
    texto += (char)SIM800L.read();
    if (texto.indexOf("Iniciar alarma") > -1) {
    
    texto = "";
    st=1;

  }

  }
  

  

}

void sms(){
  Serial.print("aceptado... ");
    Serial.println(texto);
    SIM800L.println("AT+CMGF=1"); // Configuring TEXT mode
    updateSerial();
    SIM800L.println("AT+CMGS=\"71066743\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
    updateSerial();
    SIM800L.println("MENSAJE RECIBIDO:"); //text content
    SIM800L.print(texto); //text content
    updateSerial();
    SIM800L.write(26);
}
