#include <Wire.h>
#include <PID_v1.h>
#define PIN_INPUT 0

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
float Kp = 1.7, Ki =40, Kd = 0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
  Wire.begin();
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);
  Setpoint = 512;
  Serial.begin(9600);
  //turn the PID on
  myPID.SetOutputLimits(10,4095);
  myPID.SetMode(AUTOMATIC);
}

void loop() {
  Input = analogRead(PIN_INPUT);
  Setpoint =analogRead(A1);
  myPID.Compute();
  dac(int(Output));
  Serial.println(int(Output));
}

void dac(int voltaje) {
  Wire.beginTransmission(0x60);
  Wire.write(0x40);//60
  Wire.write(voltaje / 16);                 // Upper data bits          (D11.D10.D9.D8.D7.D6.D5.D4)
  Wire.write((voltaje % 16) << 4);// Lower data bits          (D3.D2.D1.D0.x.x.x.x)
  Wire.endTransmission();
}
