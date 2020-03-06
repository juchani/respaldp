#include <Password.h> //http://www.arduino.cc/playground/uploads/Code/Password.zip
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip
#include <LiquidCrystal.h>
#include <Cronos.h>
Cronos M1(60000);
int tiemp=0;
Password password = Password( "1234" );
const int rs = 37, en = 36, d4 = 35, d5 = 34, d6 = 33, d7 = 32;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int c=0;
int a=0;
int estado = 1;
int rl[]={14,15,16,17};
const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 39,41,43,45 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 47,49,51,53 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
lcd.begin(16, 2);
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  Serial.begin(9600);
 pinMode (5, INPUT);
  pinMode (13, OUTPUT);
 pinMode (rl[0], OUTPUT);
 pinMode (rl[1] , OUTPUT);
 pinMode (rl[2] , OUTPUT);
 pinMode (rl[3] , OUTPUT); 
     digitalWrite (rl[0],HIGH);
    digitalWrite (rl[1], HIGH);
    digitalWrite (rl[2],HIGH);
    digitalWrite (rl[3],HIGH);
 delay(2000);
}

void loop(){
  keypad.getKey();
    
if(c==1){
  
  estado = digitalRead (5);
  keypad.getKey();
 
 while(estado==LOW ){   
  lcd.clear();
  lcd.setCursor(1,1);
    lcd.println("alarma activada");
  keypad.getKey();
  
  if(M1.Estado()){mensaje();
    lcd.clear();
    lcd.println("enviando mensaje");
    break;
  }
  if(a==2){
    lcd.clear();
    lcd.println("alarma desactivada");
    a=0;
    break;
  }
  //mensaje();
 }
  
 }
  else  {
    digitalWrite (rl[0],HIGH);
    digitalWrite (rl[1], HIGH);
    digitalWrite (rl[2],HIGH);
    digitalWrite (rl[3],HIGH);
 digitalWrite(13, LOW);
  }

 
}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
//	Serial.print("Pressed: ");
	lcd.print(eKey);
	switch (eKey){
	  case '*': checkPassword();lcd.clear(); break;
	  case '#': password.reset(); lcd.clear();break;
	  default: password.append(eKey);
     }
  }
}

void checkPassword(){
  if (password.evaluate()){
    lcd.clear();
    lcd.println("CORRECTO");
   password.reset();
   
    delay(1000);
    c++;
    a++;
    if(c==3){
      c=0;
    }
   }
  else{
     lcd.clear();

    lcd.println("INCORRECTO");
    delay(1000);
    //add code to run if it did not work
  }
}
