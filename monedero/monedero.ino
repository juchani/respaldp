#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x3F);
volatile int contador = 0;   // Variable entera que se almacena en la RAM del Micro
int bt1 = 9, timer, oldtimer;
int tiempo = 0;
void setup()   {
  delay(3000);
  Wire.begin();
  Wire.beginTransmission(0x27);


  lcd.begin(16, 2); // initialize the lcd
  attachInterrupt(0, interrupcion0, RISING); // Interrupcion 0 (pin2)
  pinMode(bt1, OUTPUT);
  Serial.begin(9600);

}


void loop() {
  lcd.setBacklight(255);

  timer = analogRead(A3);
  timer = map(timer, 0, 1024, 10, 91);
  if (timer != oldtimer) {
    oldtimer = timer;
    Serial.println(timer);
    delay(300);
  }

  if (tiempo < 1000)   {
    tiempo = tiempo + 1;
  }
  else {
    contador--;
    tiempo = 0;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(contador);
  }
  if (contador<2){
    contador=0;
    digitalWrite(bt1,1);
  }
  delay(1);
  tiempo++;
  //digitalWrite(bt1,contador);
}


void interrupcion0()    // Funcion que se ejecuta durante cada interrupion
{
  timer = analogRead(A3);
  timer = map(timer, 0, 1024, 10, 91);
  digitalWrite(bt1,0);
  contador = contador + timer;       // Se incrementa en uno el contador

}
