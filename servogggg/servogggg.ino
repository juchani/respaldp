
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)
int t = 250;
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();

  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);

}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period");
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit");
  pulse *= 1000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void loop() {
  Serial.println(t);
  pwm.setPWM(1, 0, 370);//pies b
  pwm.setPWM(0, 0, 380);//pie a
  pwm.setPWM(2, 0, 460);//rodilla a
  pwm.setPWM(3, 0, 460);//rodilla b
  pwm.setPWM(4, 0, 480);//cadera a
  pwm.setPWM(5, 0, 420);//cadera b
  delay(1000);
  t += 10;
  if (t > 600) {
    t = 200;
  }
}

void parado() {
  pwm.setPWM(1, 0, 330);//pies b
  pwm.setPWM(0, 0, 380);//pie a
  pwm.setPWM(2, 0, 360);//rodilla a
  pwm.setPWM(3, 0, 360);//rodilla b
  pwm.setPWM(4, 0, 330);//cadera
  pwm.setPWM(5, 0, 360);//pie a
}
void saludo() {
  pwm.setPWM(1, 0, 350);//pies b
  pwm.setPWM(0, 0, 400);//pie a
  pwm.setPWM(2, 0, 360);//rodilla a
  pwm.setPWM(3, 0, 360);//rodilla b
  pwm.setPWM(4, 0, 380);//cadera a
  pwm.setPWM(5, 0, 320);//cadera b

}
void venia (){
    pwm.setPWM(1, 0, 370);//pies b
  pwm.setPWM(0, 0, 380);//pie a
  pwm.setPWM(2, 0, 460);//rodilla a
  pwm.setPWM(3, 0, 460);//rodilla b
  pwm.setPWM(4, 0, 480);//cadera a
  pwm.setPWM(5, 0, 420);//cadera b

}

