int trago[]={89,2,3,4};
int soda[]={89,A4,6,7};
int bot[]={8,9,10,11,12,A0};
int cont=1;
int cont1=1;
int re=0;
int b1;
int b2;
int b3;
int b4;
int b5;
int b6;
int tiempo1[]={0,1500,1800,1800};
int tiempo2=9500;
int tiempo3=5000;
void setup() {
  Serial.begin(9600);
pinMode(bot[0],INPUT_PULLUP);
pinMode(bot[1],INPUT_PULLUP);
pinMode(bot[2],INPUT_PULLUP);
pinMode(bot[3],INPUT_PULLUP);
pinMode(bot[4],INPUT_PULLUP);
pinMode(A0,INPUT_PULLUP);
pinMode(trago[1],OUTPUT);
pinMode(trago[2],OUTPUT);
pinMode(trago[3],OUTPUT);
pinMode(soda[1],OUTPUT);
pinMode(soda[2],OUTPUT);
pinMode(soda[3],OUTPUT);
digitalWrite(soda[1],HIGH);
digitalWrite(trago[1],HIGH);
digitalWrite(soda[2],HIGH);
digitalWrite(trago[2],HIGH);
digitalWrite(soda[3],HIGH);
digitalWrite(trago[3],HIGH);

}

void loop() {
b1=digitalRead(bot[0]);
b2=digitalRead(bot[1]);
b3=digitalRead(bot[2]);
b4=digitalRead(bot[3]);
b5=digitalRead(bot[4]);
b6=digitalRead(A0);
if(b1==0){
  cont1=1;
}
if(b2==0){
  cont1=2;
}
if(b3==0){
  cont1=3;
}

if(b4==0){
  cont=1;
}
if(b5==0){
  cont=2;
}
if(b6==0){
  cont=3;
}
Serial.print(A6);
Serial.print('\t');
Serial.println(analogRead(A6));
if(analogRead(A6)<500 && re==0){
Serial.print("soda");
digitalWrite(soda[cont],LOW);
Serial.print(tiempo1[cont]);
delay(tiempo1[cont]);
digitalWrite(soda[cont],HIGH);
digitalWrite(trago[cont1],LOW);
Serial.print("trago");
delay(tiempo2);
Serial.print("soda");
digitalWrite(trago[cont1],HIGH);
//digitalWrite(soda[cont],LOW);
//delay(tiempo2/2);
//digitalWrite(soda[cont],HIGH);
re=1;
//delay(500);
}
if (analogRead(A6)>500){
re=0;
 //delay(1000); 
}
}
