#include <Wire.h>



int Analog_in = A0;


int Read = 0;
float distance = 0.0;
float elapsedTime, time, timePrev;        //Variables for time control
float distance_previous_error, distance_error;
int period = 50;  //Refresh rate period of the loop is 50ms
///////////////////////////////////////////////////////


///////////////////PID constants///////////////////////
float kp = 8; //Mine was 8
float ki = 0.2; //Mine was 0.2
float kd = 3100; //Mine was 3100
float distance_setpoint = 500;           //Should be the distance from sensor to the middle of the bar in mm
float PID_p, PID_i, PID_d, PID_total;
///////////////////////////////////////////////////////



void setup() {
  //analogReference(EXTERNAL);
  Serial.begin(9600);
  Wire.begin();
  pinMode(Analog_in, INPUT);
  time = millis();
}

void loop() {
  if (millis() > time + period)
  {
    time = millis();
    distance = get_dist();
    distance_error = distance_setpoint - distance;
    PID_p = kp * distance_error;
    float dist_diference = distance_error - distance_previous_error;
    PID_d = kd * ((distance_error - distance_previous_error) / period);

    if (-3 < distance_error && distance_error < 3)
    {
      PID_i = PID_i + (ki * distance_error);
    }
    else
    {
      PID_i = 0;
    }

    PID_total = PID_p + PID_i + PID_d;
    PID_total = map(PID_total, -150, 150, 0, 4095);

    if (PID_total < 20) {
      PID_total = 20;
    }
    if (PID_total > 160) {
      PID_total = 160;
    }

    dac(PID_total + 30);
    distance_previous_error = distance_error;
  }
}




float get_dist()
{
  int sum = analogRead(Analog_in);
  return (sum);
}

void dac(int voltaje) {
  Wire.beginTransmission(0x60);
  Wire.write(0x60);
  Wire.write(voltaje / 16);                 // Upper data bits          (D11.D10.D9.D8.D7.D6.D5.D4)
  Wire.write((voltaje % 16) << 4);// Lower data bits          (D3.D2.D1.D0.x.x.x.x)
  Wire.endTransmission();
}
