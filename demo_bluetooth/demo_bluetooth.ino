#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

SoftwareSerial BT1(4, 2); // RX, TX
int cont = 0;
//int reg;
int minut = 0;
int hora = 0;
//int dato;
void setup()
{
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  //Serial.println("Enter AT commands:");
  BT1.begin(9600);
  Serial.println("LCD...");
int error;
  while (! Serial);

  Serial.println("Dose: check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner
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

  lcd.begin(16, 2);
}

void loop()
{
    lcd.setBacklight(255);
  if (BT1.available() > 0) {
    int reg = BT1.parseInt();
    int dato = BT1.parseInt();

    if (reg > 0 && reg < 10 && dato > 0 && dato < 1000) {
     digitalWrite(12,HIGH);
     delay(500);
     digitalWrite(12,LOW);
     if(reg==1){
      lcd.setCursor(0,0);
      lcd.print("registrando... ");
     lcd.setCursor(0,1);
      lcd.print(dato);
      lcd.print(" hora");
     }
     if(reg==2){
      lcd.setCursor(0,0);
      lcd.print("registrando");
     lcd.setCursor(0,1);
      lcd.print(dato);
      lcd.print(" segundos");
      
     }
     if(reg==3){
      lcd.setCursor(0,0);
      lcd.print("registrando");
     lcd.setCursor(0,1);
      lcd.print(dato);
      lcd.print(" minutos");
     }
     if(reg==4){
      lcd.setCursor(0,0);
      lcd.print("iniciando ");
      lcd.setCursor(0,1);
      
     }
      Serial.print(reg);
      Serial.print('\t');
      Serial.println(dato);
    delay(1000);
    lcd.clear();
    }
    else {
      Serial.println("ERROR");
      reg = 0;
      dato = 0;
    }

  }


}


