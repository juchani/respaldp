#include <Cronos.h>

Cronos M1(1000);
const int channelPinA = 2;
const int channelPinB = 3;
int cont=0; 
const int timeThreshold = 5;
long timeCounter = 0;
 
const int maxSteps = 8550;
volatile int ISRCounter = 0;
int counter = 0;
 
bool IsCW = true;
int virus =5;
int bacterias=6;
int paracitos=7; 
int esp=8;
int est_v;
int est_b;
int est_p;
int est_e;
int n=1;
int rst=0;
void setup()
{
   pinMode(channelPinA, INPUT_PULLUP);
   Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt(channelPinA), EncodeA, CHANGE);
   attachInterrupt(digitalPinToInterrupt(channelPinB), EncodeB, CHANGE);
pinMode(virus,INPUT_PULLUP);
pinMode(bacterias,INPUT_PULLUP);
pinMode(paracitos,INPUT_PULLUP);
pinMode(esp,INPUT_PULLUP);
}
 
void loop()
{
est_v=digitalRead(virus);
est_b=digitalRead(bacterias);
est_p=digitalRead(paracitos);  
est_e=digitalRead(esp);
if (est_v==false){
  cont=1;
  rst=0;
}
if (est_b==false){
  cont=2;
  rst=0;
}
if (est_p==false){
  cont=3;
  rst=0;
}
if (est_e==false){
  n=4;
 // rst=0;
}
else{
  n=1;
 // rst=0;
}
    if(M1.Estado()){
      counter = ISRCounter;
      Serial.print(counter*-1);
      Serial.print(",");
      Serial.println(cont*n);
     // cont++;
     rst++;
      }
   if (counter != ISRCounter)
   {
      counter = ISRCounter;
      Serial.print(counter*-1);
      Serial.print(",");
      Serial.println(cont*n);
      
   }
   if(rst>30){
    cont=0;
    rst=0;
   }
   
}
 

