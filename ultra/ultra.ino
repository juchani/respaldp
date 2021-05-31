#include <Servo.h>

Servo servo;
int trig=A0,echo=A1;
float setpoint=3;
int p[4]={4,5,2,3};
int dt=7;
void setup() {
Serial.begin(9600);

pinMode(p[0],INPUT_PULLUP);
pinMode(p[1],INPUT_PULLUP);
pinMode(p[2],INPUT_PULLUP);
pinMode(p[3],INPUT_PULLUP);
pinMode(dt,INPUT_PULLUP);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trig,LOW);
servo.attach(8);
}

void loop() {
//ultra();
estado();
elevador(ultra());

}
float ultra(){
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
int tiempo=pulseIn(echo,HIGH);
float d=tiempo/59;
if(d>2 && d<100){
//Serial.println(d);  
return d;
}
  
}


void elevador(float dis){
if (digitalRead(dt)==0){
  dis=60;
}
int res=dis-setpoint;

Serial.println(res);
if (res==0 ){
  servo.detach();
}
if (res<-2){
  servo.attach(8);
servo.write(170);  
delay(100);
}
if (res>2){
  servo.attach(8);
servo.write(0);  
delay(100);
}

}
void estado(){
  if(digitalRead(p[0])==0){
    setpoint=3;
  }
  if(digitalRead(p[1])==0){
    setpoint=20;
  }
  if(digitalRead(p[2])==0){
    setpoint=40;
  }
  if(digitalRead(p[3])==0){
    setpoint=60;
  }
  
}
