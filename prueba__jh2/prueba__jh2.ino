
#include <Wire.h>

int rl[]={ 2,3,4,8,6,7};
int cont =0;
int lim=6;
void setup() {
Wire.begin(4);
Serial.begin(9600);
salida();
Wire.onReceive(receiveEvent);


}
void loop(){}
void receiveEvent() {
int recibo = Wire.read();
Serial.print("Recibo : ");
Serial.println(recibo);

if( recibo == 0 ){
apagado();

}
if ( recibo == 1 ){

digitalWrite(rl[0],LOW);
}
if( recibo == 2 ){
digitalWrite(rl[1],LOW);
}
if ( recibo == 3 ){
digitalWrite(rl[2],LOW);
}
if( recibo == 4 ){

digitalWrite(rl[3],LOW);
}
if ( recibo == 5 ){

digitalWrite(rl[4],LOW);
}
if( recibo == 6 ){
digitalWrite(rl[5],LOW);
}

}
void apagado(){
  cont=0;
while(cont<lim){
  digitalWrite(rl[cont],HIGH);
  Serial.println(rl[cont]);
  cont++;
  delay(100); 
}
   
  
  }
void salida(){
  cont=0;
while(cont<lim){
  pinMode(rl[cont],OUTPUT);
 // Serial.println(rl[cont]);
  cont++;
  delay(100); 
}
   
  
  }
