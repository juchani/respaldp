
#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo
int lec1, lec2;


void setup() {
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  servo1.write(40);                  // sets the servo position according to the scaled value
  delay(15);
  servo2.write(130);                  // sets the servo position according to the scaled value
  delay(15);
  lec1 = servo1.read();
  lec2 = servo2.read();
  Serial.print(lec1);
  Serial.print('\t');
  Serial.println(lec2);
}

