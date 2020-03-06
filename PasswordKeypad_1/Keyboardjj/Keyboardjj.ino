#include "DigiKeyboard.h"
int est1,est2,est3,est4,var=0;
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
if (est1==true){
    var=1;
}
if (est2==true){
    var=3;
}
if (est3==true){
    var=5;
}
if (est4==true){
    var=var*2;
}
if (var>0){
  DigiKeyboard.println(var);
   DigiKeyboard.delay(1000);
  DigiKeyboard.println("x");
  var=0;
  }
  
  
}

