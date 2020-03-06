class ultrasonico{
 private:
 int t,e;
 float tiempo,distancia,velocidad=343.2;  
 public:
 float ultra();
 estatus(int trig, int echo);
};
 float ultrasonico::ultra(){
  digitalWrite(t,0);
  delayMicroseconds(2);
  digitalWrite(t,1);
  delayMicroseconds(10);
  digitalWrite(t,0);
  tiempo=pulseIn(e,HIGH);
 // distancia=velocidad*(tiempo/1000000)*100;
  
  return tiempo;}
  
 ultrasonico:: estatus( int trig ,int echo){
  t=trig;
  e=echo;
  pinMode(t,OUTPUT);
   pinMode(e,INPUT);
}
#include "SingleEMAFilterLib.h"

 SingleEMAFilter<float> singleEMAFilter(0.15);

ultrasonico s1;
void setup() {
s1.estatus(8,9);///trig,echo
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  tone(13,100);
float t=singleEMAFilter.AddValue(s1.ultra());
Serial.print(1023);
Serial.print('\t');
Serial.println(t);
}
