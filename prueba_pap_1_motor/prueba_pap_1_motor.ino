#include <LiquidCrystal.h> // includes the LiquidCrystal Library
#include <Servo.h>
LiquidCrystal lcd(27, 26, 25, 24, 23, 22); 
Servo servo1, servo2;
const int stepPin = 21;
const int dirPin = 20;
const int step1 = 19;
const int dir1 = 18;
int bt1 = 8;
int bt2 = 9;
int st = 1;
int sensor = 14;
void setup() {
  lcd.begin(16, 2);
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(step1, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}
void loop() {
    lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Inserte una");
  lcd.setCursor(4, 1);
  lcd.print("Moneda!");
  if(digitalRead(sensor)){
    st=0;
  }
  Serial.println(digitalRead(sensor));
  while (st == 0) {
    delay(10);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Escoja un item");
  lcd.setCursor(0, 1);
  lcd.print(" 1, 2, 3 or 4?");

    if (digitalRead(bt1) == 0) {
      lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Entregando...");
      arriba ();
      horizontal1();
      servo1.attach(2);
      servo1.write(0);
      delay(2000);
      servo1.detach();
      horizontal0();
      abajo();
      st = 1;
    }
    if (digitalRead(bt2) == 0) {
      lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Entregando...");
      arriba1 ();
      //horizontal1();
      servo1.attach(3);
      servo1.write(0);
      delay(2000);
      servo1.detach();
      // horizontal0();
      abajo1();
      st = 1;
    }

    delay(500);
  }
  delay(200);
}
