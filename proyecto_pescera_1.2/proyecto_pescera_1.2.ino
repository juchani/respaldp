#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <Arduino.h>
#include "RTClib.h"
#include <EEPROM.h>
#include <OneWire.h>
#include <DHT11.h>
#include <Servo.h>
Servo sec;
Servo direccion;
int pin = 6;
DHT11 dht11(pin);
OneWire  ds(A0);
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
RTC_DS1307 rtc;
int show;
int x_axis;
int y_axis;
int boton;
int luz = 255;
int contador = 0;
int contador1 = 0;
///////////////DIRECCIONES EEPROM/////////////////////
int dir_m=9;
int dir_new = 100;
int dir_old = 101;
int dir_contador = 102;
int dir_hora = 0;
int dir_minuto = 1;
int dir_ultra = 2;
int dir_dht11 = 3;
int dir_dallas = 4;
int dir_ultima_hora = 5;
int dir_ultimo_min = 6;
int dir_f = 7;
int dir_g=8;
///////////VARIABLES PARA EL CONTADOR//////////////////
int new_1 = 0;
int old_1 = 0;
int contador3 = 0;
int limite = 120;
//////////VARIABLES PARA EL RELAY//////////
int rl1=9;
int rl2=10;
int rl3=11;
int rl4=12;
bool estatus=0;
void setup()
{
  direccion.attach(5);
  sec.attach(4);
  pinMode(rl1,OUTPUT);
  pinMode(rl2,OUTPUT);
  pinMode(rl3,OUTPUT);
  pinMode(rl4,OUTPUT);
  digitalWrite(rl1,!estatus);
  digitalWrite(rl2,!estatus);
  digitalWrite(rl3,!estatus);
  digitalWrite(rl4,!estatus);
  sec.write(0);
  int error;
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  Serial.begin(9600);
  Serial.println("LCD...");
  pinMode(2, INPUT_PULLUP);
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
  lcd.begin(16, 2); // initialize the lcd
  show = 0;
  rest();

} // setup()

void fecha() {
  DateTime now = rtc.now();
  //lcd.setBacklight(255);
  lcd.print(now.year() - 2000, DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print(" ");
  lcd.print(EEPROM.read(dir_minuto) * 0.5);
  lcd.print(" SEG");
  lcd.setCursor(0, 1);
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  lcd.print("   ");
  lcd.print(EEPROM.read(dir_hora));
  lcd.print(" HRS");
  //rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), 0));
}
void loop()
{
//digitalWrite(rl1,estatus);
  lcd.setBacklight(luz);
  fecha();
  contado();
  //sec.write(10);
  boton = digitalRead(2);
  x_axis = analogRead(A3);
  x_axis = map(x_axis, 0, 1024, 0, 3);
  y_axis = analogRead(A2);
  y_axis = map(y_axis, 0, 1024, 0, 3);
  if (boton == 0) {
    luz = 255;
  }
  while (x_axis == 2 || x_axis == 0 || y_axis == 2 || y_axis == 0) {
    delay(250);
    while (true) {
      delay(200);
      lcd.clear();
      contador, x_axis, boton = menu(6);
      if (contador == 0) {
        if (boton == 0 || x_axis == 0) {
          delay(250);
          sub_menu0();
        }
        if (x_axis >= 2) {
          break;
        }
        lcd.setCursor(0, 0);
        lcd.print("    TIEMPO ");
        lcd.setCursor(0, 1);
        lcd.print("  DE RETARDO");
      }
      //////////////////////////////////////////////////////
      if (contador == 1) {
        if (boton == 0 || x_axis == 0) {
          delay(250);
          sub_menu1();
        }
        lcd.setCursor(0, 0);
        lcd.print("  CAMBIAR HORA ");
        lcd.setCursor(3, 1);
        lcd.print("DEL PROCESO");
      }
      /////////////////////////////////////////////////////
      if (contador == 2) {
        if (boton == 0 || x_axis == 0) {
          delay(250);
          sub_menu2();

        }
        lcd.setCursor(0, 0);
        lcd.print("DATOS DEL SENSOR");
        lcd.setCursor(2, 1);
        lcd.print("ULTRASONICO");
      }
      //////////////////////////////////////////////////////////
      if (contador == 3) {
        if (boton == 0 || x_axis == 0) {
          delay(250);
          sub_menu3();

        }
        lcd.setCursor(3, 0);
        lcd.print("SENSOR DE");
        lcd.setCursor(2, 1);
        lcd.print("TEMPERATURA");
      }
      //////////////////////////////////////////////////////
      if (contador == 4) {
        if (boton == 0 || x_axis == 0) {
     secuencia();
        }
        lcd.setCursor(4, 0);
        lcd.print("INICIAR");
        lcd.setCursor(3, 1);
        lcd.print("SECUENCIA");
      }
      /////////////////////////////////////////////////////////////
      if (contador == 5) {
        if (boton == 0 || x_axis == 0) {
          luz = 0;
          contador = 0;
          rest();
          break;

        }
        lcd.setCursor(5, 0);
        lcd.print("SALIR");
        lcd.setCursor(2, 1);
        lcd.print("Y APAGAR LUZ");
      }
      /////////////////////////////////////////////////////////
      if (contador == 6) {
        if (boton == 0 || x_axis == 0) {
          delay(250);
          sub_menu4();

        }
        lcd.setCursor(4, 0);
        lcd.print("REGISTRO");
        lcd.setCursor(3, 1);
        lcd.print("Y SENSORES");
      }
      /////////////////////////////////////////////////////////


    }

    delay(100);
    lcd.clear();
    break;

  }
  delay(300);
  lcd.clear();
}



