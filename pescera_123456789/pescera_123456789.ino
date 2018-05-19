#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#include "RTClib.h"
#include <OneWire.h>
#include <Cronos.h>
#include <EEPROM.h>
#include <Servo.h>
#define motor 10
Servo myservo;
int hor=0;
int dur=1;
int est=0;
int est1=0;
int d=0;
Cronos M1(1000);
OneWire  ds(A1); 
RTC_DS1307 rtc;
char diasdelasemana[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
char mes[12][0]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
SoftwareSerial BT1(2, 3); // RX, TX
int cont = 0;
int minut = 0;
int hora = 0;
int buzzer=5;
int espera;
void setup()
{
  pinMode(motor,OUTPUT);
  myservo.attach(4);
    while (!Serial); // for Leonardo/Micro/Zero

  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
     rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  pinMode(buzzer,OUTPUT);
    //Serial.println("Enter AT commands:");
  BT1.begin(9600);
  Serial.println("LCD...");
int error;
  while (! Serial);

  Serial.println("Dose: check for LCD");

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

  lcd.begin(20, 4);
}

void loop()
{
    lcd.setBacklight(155);
  menu_principal();
  bluetooth();
  //delay(500);
  if (M1.Estado()) {
lcd.clear();

}}


