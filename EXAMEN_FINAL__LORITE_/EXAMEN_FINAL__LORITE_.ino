#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
int ba1;
int ba2;
int bb1;
int bb2;
int boton1=10;
int boton2=11;
int promedio; 
void setup() {
  lcd.begin(16, 2);
pinMode(boton1,INPUT);
pinMode(boton2,INPUT);
}

void loop() {
  
  lcd.begin(16, 2);
  ba1 = analogRead(A0);
  ba2 = analogRead(A1);
  bb1 = analogRead(A2);
  bb2 = analogRead(A3);
  ba1 = map(ba1, 0, 1023, 0, 50);
  ba2 = map(ba2, 0, 1023, 0, 50);
  bb1 = map(bb1, 0, 1023, 0, 50);
  bb2 = map(bb2, 0, 1023, 0, 50);

  lcd.setCursor (0, 0);
  lcd.print("T= ");
  lcd.print(GetTemp(), 1);
  lcd.setCursor (0, 1);
  lcd.print ("a1 ");
  lcd.print (ba1);
  lcd.print("kg");
  lcd.setCursor (9, 1);
  lcd.print("a2 ");
  lcd.print (ba2);
  lcd.print("kg");
 int estado1=digitalRead(boton1);
   int estado2=digitalRead(boton2);
   if (estado1==HIGH)  {
    promedio=promedio+ba1;
   }
   if (estado2==HIGH){
    promedio=promedio-ba2;
   }
    lcd.setCursor (10, 0);
    lcd.print (promedio);
  delay(100);
  lcd.clear();
}

double GetTemp(void)
{
  unsigned int wADC;
  double t;

  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);
  delay(20);
  ADCSRA |= _BV(ADSC);
  while (bit_is_set(ADCSRA, ADSC));
  wADC = ADCW;

  // Esto es la función a calibrar.
  t = (wADC - 324.31 ) / 1.22;
  return (t);
}
