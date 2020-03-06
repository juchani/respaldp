#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int velocidad;
int estado;
int registro;
bool est;
int vel;
int veli;
int co;
bool e;
bool d=1;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(0x27);
  lcd.begin(16, 2);
   lcd.setBacklight(0);
   delay(500);
    lcd.setBacklight(255);
  lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("REACTOR BATCH");
     lcd.setCursor(0,1);
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
  delay(500);
  lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
   
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
  
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
  lcd.clear();
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  lcd.setBacklight(255);
}

void loop() {
  velocidad = analogRead(A0);
  velocidad = map(velocidad, 0, 1023, 255, 0);
  estado = digitalRead(11);
  registro = digitalRead(12);
  Serial.println(velocidad);
  lcd.setCursor(0,0);
  lcd.print("vel.actual: ");
  lcd.print(vel);
    lcd.setCursor(0,1);
  lcd.print("velocidad: ");
  lcd.print(velocidad);
  veli = map(velocidad, 0, 255, 0, 180);
  if (estado == LOW) {
    est = !est;
    delay(500);
  }
  if (registro == LOW) {
    vel = velocidad;
    lcd.clear();
    lcd.setCursor(1,1);
    Serial.println("registrado");
    lcd.print("REGISTRANDO");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
  delay(500);
  lcd.clear();
 e=0;
  }
  if (est == 1&& e==0) {
    lcd.clear();
    lcd.setCursor(1,1);
    Serial.println("registrado");
    lcd.print("INICIANDO");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    delay(500);
    lcd.print(".");
    analogWrite(10, veli);
e=1;
d=0;
  }
  if (est == 0 && d==0) {
  
    analogWrite(10, 0);

e=0;
d=1;
    lcd.clear();
    lcd.setCursor(1,1);
    Serial.println("registrado");
    lcd.print("MOTOR APAGADO");
    delay(500);

  
  }
  if (co>30){
  lcd.clear();
  co=0;  
  }
  co++;
  delay(1);
  
}
