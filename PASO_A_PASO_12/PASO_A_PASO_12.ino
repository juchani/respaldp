#include <Cronos.h>

Cronos M1(500);
int pul=12;
int dir=11;
int en=10;
int paso=1;//[]={};
int temp=0;
void setup() {
  pinMode(pul,OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(en,OUTPUT);
  digitalWrite(en,  HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(dir,LOW);
//for (int i=0;i<3200;i++){
  digitalWrite(pul,HIGH);
delayMicroseconds(paso);
  digitalWrite(pul,LOW);
delayMicroseconds(paso);
 if(M1.Estado()){
Serial.println(paso);
paso =100  ;
 
 }

}
