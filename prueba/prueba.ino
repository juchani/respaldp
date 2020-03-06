#include <Wire.h>
#include "RTClib.h"
 
// RTC_DS1307 rtc;
RTC_DS3231 rtc;
 
String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };

int limite=5;
int horas_del_dia=59;
int l=0;
int contador=0;
int resultado;
int segundo;
int dia;
int car;
int char_dia;
int char_segundo;
void setup() {
Serial.begin(9600);
   delay(1000); 
 pinMode(13,OUTPUT);
// tiempo_g=EEPROM.read(dir);
   if (!rtc.begin()) {
      Serial.println(F("Couldn't find RTC"));
      while (1);
   }
    DateTime date = rtc.now();
    char_segundo=date.second();
    char_dia=date.minute();
resultado=horas_del_dia;
}

void loop() {
  DateTime date = rtc.now();
    segundo=date.second();
    dia=date.minute();
 while(l<1){
    resultado=resultado-limite;
    contador++;
    //Serial.println(resultado);
  if (resultado<limite){
       car=limite-resultado;
       l=1;
  Serial.println(contador);
   Serial.println(resultado);
    Serial.println(car);
  }}
  ///////////////////////////
  Serial.println(segundo);
  if (segundo==char_segundo){
    char_dia=char_dia+limite;
    digitalWrite(13,HIGH);
    delay(500);
  }
  else{
     digitalWrite(13,LOW);
  }
  if(dia=!char_dia){
    while(segundo<car){
       segundo=date.second();
Serial.print(segundo);
Serial.println ("  al parecer funciono");
    }
    char_segundo=date.second();
    resultado=horas_del_dia-car;
    contador=0;
    l=0;
    char_dia=dia;
    car=0;
  }
  delay(500);
 }

