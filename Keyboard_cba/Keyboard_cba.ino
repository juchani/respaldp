#include "DigiKeyboard.h"LO dIGISPARK!

int est1,est2,est3,est4,est;

void setup() {
 pinMode(0,INPUT);
  pinMode(1,INPUT);
   pinMode(2,INPUT);
    pinMode(5,INPUT);
}


void loop() {
est1=digitalRead(0);
est2=digitalRead(1);
est3=digitalRead(2);
est4=digitalRead(5);
if(est1==LOW){
//  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("A");
  
}
if(est2==LOW){
//  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("B");
}
if(est3==LOW){
//  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("C");
}
else if(est4==LOW){
//  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("d");
}
   
 
}



