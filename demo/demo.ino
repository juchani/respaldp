#include <LiquidCrystal_PCF8574.h>
#include <OneWire.h>
#include <Wire.h>

OneWire  ds(9);  // on pin 10 (a 4.7K resistor is necessary)

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
float temp, t_ini = 70;
int b1 = 6, b2 = 5, b3 = 7, buzzer = 12, relay = 4, sp = t_ini, tiempo, tiempo1, sp1 = t_ini;
int pwm = 3, salida, r1 = 0, co, minutos = 2;
int frec = 50;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  pinMode(pwm, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  Wire.begin();
  Wire.beginTransmission(0x27);

  lcd.begin(16, 2);
  analogWrite(pwm, 0);
}

void loop() {
  if (!digitalRead(b1)) {
    sp++;
    tiempo1 = 0;
    delay(100);
    // bip();
  }
  if (!digitalRead(b2)) {
    sp--;
    tiempo1 = 0;
    delay(100);
    // bip();
  }
  if (!digitalRead(b3)) {
    sp1 = sp;
    tiempo1 = 0;
    bip();
    delay(10);
    r1 = 1;

  }
  if (tiempo < 1) // 1000   cilcos de 1ms
  {
    tiempo = tiempo + 1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    pantalla();
    tiempo = 0;
  }
  if (tiempo1 < 40) // 1000   cilcos de 1ms
  {
    tiempo1 = tiempo1 + 1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    sp = sp1;
    tiempo1 = 0;
  }
  if (temp < sp1 - 6) {
    if (r1 == 1) {
      digitalWrite(relay, LOW);
      Serial.println("llegando al setpoint");
    }

  }
  else {

    Serial.println("setpoint");
    while (r1 == 1) {
      pantalla();
      Serial.println(co);
      if (co > minutos * 50) {
        co = 0;
        r1 = 0;
      }
      if (temp < sp1 - 3) {
        digitalWrite(relay, LOW);
      }
      else {
        digitalWrite(relay, HIGH);
      }
      if (!digitalRead(b3)) {

        tiempo1 = 0;
        bip();
        delay(10);
        r1 = 0;

      }
      co++;
      bip();
      analogWrite(pwm, frec);
      delay(100);
    }
    analogWrite(pwm, 0);

    digitalWrite(relay, HIGH);
  }
  //
  delay(10);
}
