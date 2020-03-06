#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
RTC_DS3231 rtc;
String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
int segundo;
int limite = 3 ;
int contador;
int dia ;
int fin_del_dia;
int horas_del_dia = 59;
int rec;
int j;
int reloj;
int mes ;
int sensor1 = 0;
int sensor2;
int boton1;
int boton2;
int s1 = 8;
int s2=9;
int estado1;
int estado2;
void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);
////////DECLARACION DE PINES 
  pinMode(13, OUTPUT);
  pinMode(s1, INPUT);
 
  delay(1000);
  
  // tiempo_g=EEPROM.read(dir);
  if (!rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  if (rtc.lostPower()) {
  }
  DateTime date = rtc.now();
  contador = date.second();
  fin_del_dia = date.minute();
  rec = contador - 1;
  contador = contador + limite;
  contador = contador - 2;
lcd.home();
}


void loop() {

  DateTime date = rtc.now();
  segundo = date.second();
  dia = date.minute();
  j = date.hour();
  mes = date.month() - 1;
  //Serial.print(j);
  //Serial.print("/");
  Serial.println(segundo);
  rec = horas_del_dia - contador;
  Serial.print("rec ");
  Serial.println(rec);
  if (rec == 59) {
    contador = limite - 1;
  }
  lcd.setCursor(0,1);
  lcd.print(date.second());
  if (segundo == contador) {
    
    contador = contador + limite;
    digitalWrite(13, HIGH);
    //Serial.println (" encendido ");
    reloj = 0;
    
    // delay(1000);
  }
  else {
    digitalWrite(13, LOW);
  }
  if (fin_del_dia < dia) {
    while (rec < 0) {
      rec = rec + limite;
    }
    if (rec > 0) {
      rec = limite - rec;
    }
    /*  if(rec==1){
        rec=1;
      }*/

    contador = rec;
    //rec=0;
    fin_del_dia = dia;
  }
  //tmp36();
  //menu();
  delay(250);
  lcd.clear();
}




