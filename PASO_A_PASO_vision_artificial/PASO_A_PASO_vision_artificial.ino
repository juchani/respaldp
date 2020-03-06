#include <Cronos.h>
Cronos M1(500);
 int sentido;
  int dato;
  int on;
int pul=2;
int dir=3;
int en=4;
int paso=1;//[]={};
int temp=0;
int direccion;
bool est;
void setup() {
  pinMode(pul,OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(en,OUTPUT);
    Serial.begin(9600);
}

void loop() {
if(Serial.available()>0){
 dato=Serial.parseInt();
sentido=Serial.parseInt();
on=Serial.parseInt();
Serial.print(dato);
Serial.print('\t');
Serial.println(sentido);
if(dato>0){
paso =dato ;  
direccion=sentido;
est=on;
}

}
digitalWrite(en, est);
  digitalWrite(dir,direccion);
  digitalWrite(pul,HIGH);
delayMicroseconds(paso);
  digitalWrite(pul,LOW);
delayMicroseconds(paso);
 

}
