#include <Ultrasonic.h>
Ultrasonic ultrasonic(7,6); // (Trig PIN,Echo PIN)
int verde=8;
int amarillo=9;
int rojo=10;
int distancia=0;
int motor=11;
void setup() {
  Serial.begin(9600);
pinMode(verde,OUTPUT);
pinMode(amarillo,OUTPUT);
pinMode(rojo,OUTPUT);
pinMode(motor,OUTPUT);
}
void loop()
{
  Serial.print(ultrasonic.Ranging(CM));
  Serial.println(" cm" );
distancia=ultrasonic.Ranging(CM);
if(distancia<27){
digitalWrite(verde,0);
digitalWrite(amarillo,0);
digitalWrite(rojo,1);
digitalWrite(motor,1);
}  
if(distancia<15){
digitalWrite(verde,0);
digitalWrite(amarillo,1);
digitalWrite(rojo,0);
digitalWrite(motor,1);
}
if(distancia<5){
 
  digitalWrite(verde,1);
  digitalWrite(amarillo,0);
  digitalWrite(rojo,0);
  digitalWrite(motor,0);

}
delay(5000);
}

