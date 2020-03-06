  
#include <Servo.h>

Servo myservo;  
int bt1=3,bt2=10;
void setup() {
  pinMode(bt1,INPUT_PULLUP);
  pinMode(bt2,INPUT);
  myservo.attach(9);
myservo.write(10);             
    delay(15);                    
}

void loop() {
  if(digitalRead(bt1)==0){
    myservo.write(10);             
    delay(15);                   
  }
  if(digitalRead(bt2)==1){
    myservo.write(80);             
    delay(15);                   
  }  
  }


