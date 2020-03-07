#include <Cronos.h>

Cronos M1(1000);
Cronos M2(5000);

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(M1.Estado()){Serial.println("Crono 1");}
  if(M2.Estado()){Serial.println("Crono 2");}
}

