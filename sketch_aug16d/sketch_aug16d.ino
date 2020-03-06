#include <SoftwareSerial.h>
//Pulsador para enviar el Mensaje
#define SIM800_PULSADOR 9
int contador = 0;
//Se declara los pines en el arduino Uno
SoftwareSerial MOD_SIM800L(7, 8);
void setup() {
//Se establece la velocidad para el puerto serie
Serial.begin(9600);
while(!Serial);
//Velocidad de trabajo entre el Arduino Uno y el Modulo SIM800L
MOD_SIM800L.begin(9600);
delay(1000);
pinMode (SIM800_PULSADOR, INPUT_PULLUP);
Serial.println("Configuracion Completa!");
Serial.println("Enviando SMS...");
//Se establece el formato de SMS en ASCII
MOD_SIM800L.write("AT+CMGF=1\r\n");
delay(1000);
//Enviar comando para un nuevos SMS al numero establecido
MOD_SIM800L.write("AT+CMGS=\"+591 69122887\"\r\n");
delay(1000);
//Enviar contenido del SMS
MOD_SIM800L.write("Hola.");
delay(1000);
//Enviar Ctrl+Z
MOD_SIM800L.write((char)26);
delay(1000);
Serial.println("Mensaje enviado!");

}
void loop() {
if((digitalRead(SIM800_PULSADOR) == 0)&&(contador == 0)){

}
}

