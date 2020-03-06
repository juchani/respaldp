#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <Servo.h>
Servo servo;
LiquidCrystal_PCF8574 lcd(0x3F);
Password password = Password( "12345" );
const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
int buzzer=13;
byte rowPins[ROWS] = { 9, 8, 7, 6 }; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 5, 4, 3 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  servo.attach(12);
pinMode(buzzer,OUTPUT);

}

void loop() {
  keypad.getKey();
  lcd.setCursor(2, 0);
  lcd.print("INCERTE CLAVE");
  delay(100);
  lcd.clear();
  //
  //
}


void keypadEvent(KeypadEvent eKey) {
  switch (keypad.getState()) {
    case PRESSED:
      Serial.print("Pressed: ");
      Serial.println(eKey);

      lcd.setCursor(8, 1);
      lcd.print(eKey);
      
      switch (eKey) {
        case '*': checkPassword();bip(400); break;
        case '#': password.reset();bip(200); break;
        default:bip(100); password.append(eKey);
      }
  }
}

void checkPassword() {
  if (password.evaluate()) {
    servo.write(180);
    bip(200);
    lcd.setCursor(0, 1);
    lcd.print("abriendo puerta");
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("error");
    bip(100);
    bip(100);
    servo.write(10);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
    lcd.print(".");
    delay(100);
  }

}

void bip(int tiempo){
  digitalWrite(buzzer,HIGH);
  delay(tiempo);
  digitalWrite(buzzer,LOW);
  delay(tiempo);
}

