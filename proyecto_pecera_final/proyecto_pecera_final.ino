#include <SoftwareSerial.h>
#include <Wire.h>
#include "RTClib.h"
#include <EEPROM.h>
//#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <OneWire.h>
#include <Cronos.h>
Cronos M1(10000);
Cronos M2(30000);
int pull1 = 9;
int pull2 = 8;
int pull3 = 7;
int pull4 = 6;
int sensor1;
int sensor2;
int sensor3;
int sensor4;
int contr;
int var;
int define_cont = 0;
int l = 1;
int tiempo;
int a;
OneWire  ds(A1);  // on pin 10 (a 4.7K resistor is necessary)

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int show;
RTC_DS1307 rtc;
char diasdelasemana[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
char mes[12][0]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
SoftwareSerial BT1(2, 3); // RX, TX
int est=0;
int est1=0;

int dir_new=100;
int dir_old=101;
int dir_contador=102;
int new_1=0;
int old_1=0;
int contador=0;
int dir_limite=30;
int temp_relay=3;
int dir_relay=103;
int buzzer=5;
int motor =4;
int t;
int limite;
void setup () {
pinMode(buzzer,OUTPUT);
pinMode(motor,OUTPUT);
digitalWrite(motor,1);
pinMode(pull1, INPUT_PULLUP);
  pinMode(pull2, INPUT_PULLUP);
  pinMode(pull3, INPUT_PULLUP);
  pinMode(pull4, INPUT_PULLUP);
int error;
 BT1.begin(9600);
//EEPROM.write(dir_relay,temp_relay); 
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);

  if (error == 0) {
    Serial.println(": LCD found.");

  } else {
    Serial.println(": LCD not found.");
  } // if

  lcd.begin(20, 4); // initialize the lcd
  show = 0;
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    
  }
  DateTime now = rtc.now();
  if(EEPROM.read(dir_new)<now.second()){
  int resque=EEPROM.read(dir_contador);
  resque=resque+(EEPROM.read(dir_new)-now.second()+3);
  EEPROM.write(dir_contador,resque);}
 else{
  new_1=now.second();
  old_1=now.second();
  EEPROM.write(dir_new,new_1 );
  EEPROM.write(dir_old,old_1 );
  
}

}

void loop () {
  lcd.setBacklight(155);
      contado();
       bluetooth();
       menu_principal();
       dallas_temperature();
       if (digitalRead(pull3)==LOW){
  sub_menu();
  }
        if (M1.Estado()) {

lcd.clear();

}
<<<<<<< HEAD
}
=======
}
>>>>>>> 941ca59634530a6110725808d796cfe22c1cd89d
