#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Password password = Password( "1237" );

const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 9,8,7,6 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 5,4,3,2, };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.

int led=13;
int puerta=10;
int pir=11;
int estado;
// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
int error;

  Serial.begin(115200);
  Serial.println("LCD...");

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



  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
    Serial.print("Pressed ");
    pinMode(led,OUTPUT);
    pinMode(puerta,INPUT_PULLUP);
    pinMode(pir,INPUT_PULLUP);
}

void loop(){
  keypad.getKey();
  
  lcd.setCursor(0,0);
  lcd.setBacklight(255);
  
lcd.print("ALARMA ANTI-ROBO");
if (estado==1){
  if(digitalRead(puerta)==1||digitalRead(pir)==1){
    digitalWrite(led,1);
  }
}
else if(estado==0){
   digitalWrite(led,0);
}
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
 
  switch (keypad.getState()){
    case PRESSED:
	Serial.print("Pressed: ");
	Serial.println(eKey);
	switch (eKey){
	  case '*': checkPassword(); break;
	  case '#': password.reset(); break;
	  default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    Serial.println("Success");
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("CODIGO");
    lcd.setCursor(3,1);
lcd.print("CORRECTO");    
      delay(1000);
  lcd.clear();
   estado++;
   if(estado==2){
    estado=0;
     lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("ALARMA");
    lcd.setCursor(3,1);
lcd.print("DESACTIVADA");    
    delay(1000);
    lcd.clear();
   }
  }else{
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("CODIGO");
    lcd.setCursor(4,1);
lcd.print("INCORRECTO");    
    delay(1000);
    lcd.clear();
    Serial.println("Wrong");
   
  }
}
