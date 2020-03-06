#include <EEPROM.h>
int m1[]={5,6};
int m2[]={10,11};
int programar=12;
int pla=13;
int pl;
int pr;
int x,y;
int buzzer=2;
int b,b1;
int c,c1;
int estatus;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
 pinMode(m1[0],OUTPUT);
 pinMode(m1[1],OUTPUT);
 pinMode(m2[0],OUTPUT);
 pinMode(m2[1],OUTPUT);
 pinMode(programar,INPUT);
  pinMode(pla,INPUT);
 
}

void loop() {
pr=digitalRead(programar);
pl=digitalRead(pla);
Serial.println(pl); 
if (pr==1){
for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
digitalWrite(buzzer,1);
  }
  digitalWrite(buzzer,0);
  bip();
  b=1;
  c=0;
while(b==1){
  //pr=digitalRead(programar);
  x=analogRead(A0);
  y=analogRead(A1);
  x=map(x,0,0124,0,2);
  y=map(y,0,0124,0,2);
//  Serial.print(x);
//  Serial.print("  ");
  Serial.println(c);
  if(y<9){
    EEPROM.write(c, 1);
    c++;
    delay(450);
    bip();
  }
  if(y>15){
    EEPROM.write(c, 2);
    c++;
    delay(450);
    bip();
  }
   if(x>15){
    EEPROM.write(c, 3);
    c++;
    delay(450);
    bip();
  }
   if(x<9){
    EEPROM.write(c, 4);
    c++;
    delay(450);
    bip();
  }
  if(digitalRead(programar)==1){
    bip();
    b=0;
   
    
  }}}
if (pl==1 ){
bip();
b1=1;
c1=0;
while(b1==1){
estatus=EEPROM.read(c1);
if (estatus==1){
  adelante();
  delay(100);
  c1++;
}
if (estatus==2){
  atras();
  delay(100);
  c1++;
}if (estatus==3){
  derecha();
  delay(100);
  c1++;
}if (estatus==4){
  izquierda();
  delay(100);
  c1++;
}if (estatus==0){
  parar();
  delay(100);
c1++;
}
 parar();
  delay(200);









if(digitalRead(pla)==1){
    bip();
    b1=0;   
  }}
}

  
delay(250);



}
void bip(){
  digitalWrite(buzzer,1);
  delay(100);
  digitalWrite(buzzer,0);
}
 void parar(){
digitalWrite(m1[0],0);
digitalWrite(m1[1],0);
digitalWrite(m2[0],0);
digitalWrite(m2[1],0);  
 }
 void adelante(){
digitalWrite(m1[0],1);
digitalWrite(m1[1],0);
digitalWrite(m2[0],1);
digitalWrite(m2[1],0);  
 }
void atras(){
  digitalWrite(m1[0],0);
digitalWrite(m1[1],1);
digitalWrite(m2[0],0);
digitalWrite(m2[1],1);
}
 void derecha(){
  digitalWrite(m1[0],0);
digitalWrite(m1[1],1);
digitalWrite(m2[0],1);
digitalWrite(m2[1],0);
 }

void izquierda(){
  digitalWrite(m1[0],1);
digitalWrite(m1[1],0);
digitalWrite(m2[0],0);
digitalWrite(m2[1],1);
}

