// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
 
//  motor.run(RELEASE);
}

void loop() {
izquierda();
delay(1000);
parar();
delay(1000);
}
void adelante(){
  motor.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(10);
}
void retro(){
  motor.run(RELEASE);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);
  delay(10);

}
void derecha(){
  motor.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void izquierda(){
  motor.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void parar(){
  motor.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void tester(){
  uint8_t i;
  
  Serial.print("tick");
  
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  
  Serial.print("tock");

  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  

  Serial.print("tech");
  motor.run(RELEASE);
  delay(1000);  
}
