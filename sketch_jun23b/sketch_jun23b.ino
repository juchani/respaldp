#include <Cronos.h>

Cronos M1(1000);
int boton1=5;
int boton2=6;
int boton3=7;
int led1=10;
int led2=11;
int led3=12;
int tiempo1=2;
int tiempo2=3;
int tiempo3=4;
int estado1;
int estado2;
int estado3;
bool est1=0;
bool est2=0;
bool est3=0;
int vart1=0;
int vart2=0;
int vart3=0;

void setup(){
  Serial.begin(9600);
  pinMode (boton1,INPUT);
   pinMode (boton2,INPUT);
    pinMode (boton3,INPUT);
    pinMode (led1,OUTPUT);
    pinMode (led2,OUTPUT);
    pinMode (led3,OUTPUT);
}

void loop(){
estado1=digitalRead(boton1);
estado2=digitalRead(boton2);
estado3=digitalRead(boton3);
if (estado1==HIGH){
  est1=1;
}
if (estado2==HIGH){
  est2=1;
}
if (estado3==HIGH){
  est3=1;
}  
  
  if(M1.Estado()){
    if (est1==HIGH){
      vart1++;
    }
    if (est2==HIGH){
      vart1++;
    }
    if (est3==HIGH){
      vart1++;
    }
    
    
    
    
    
    
    }
  
if (vart1>0 && vart1<tiempo1){
  digitalWrite(led1,HIGH);
}
else {
  digitalWrite(led1,LOW);
  vart1=0;
  est1=0;
}
if (vart2>0 && vart2<tiempo2){
  digitalWrite(led2,HIGH);

}
else {
  vart2=0;
  est2=0;
  digitalWrite(led2,LOW);
}
if (vart3>0 && vart1<tiempo3){
  digitalWrite(led3,HIGH);
}
else {
  vart3=0;
  est3=0;
  digitalWrite(led3,LOW);
}








}

