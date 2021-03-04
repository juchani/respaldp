#include <Wire.h>
#include <Servo.h>



///////////////////////ENTRADA-SALIDA///////////////////////
int sharp1 = A0;
int sharp2 = A1;
Servo myservo;
///////////////////////////////////////////////////////


////////////////////////Variables///////////////////////
int Read = 0;
float distancia = 0.0;
float elapsedTime, time, timePrev;        //Variables para el control de tiempo
float distance_previous_error, distance_error;
int period = 70;  //tiempo de muestreo
///////////////////////////////////////////////////////


///////////////////PID///////////////////////
float kp = 20; //proporcional
float ki = 0.5; //integral
float kd = 800; //derivativo
float distance_setpoint = 7;           //Should be the distance from sensor to the middle of the bar in mm
float PID_p, PID_i, PID_d, PID_total;
///////////////////////////////////////////////////////



void setup() {

  Serial.begin(9600);
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
  myservo.write(125); //Put the servco at angle 125, so the balance is in the middle
  pinMode(sharp1, INPUT);
  pinMode(sharp2, INPUT);
  time = millis();
}

void loop() {
  
   b
  if (millis() > time + period)
  {
    distance_setpoint = sensor2(200);
    time = millis();
    distancia = sensor1(200);
    Serial.print(distance_setpoint);
    Serial.print("  ");
    Serial.println(distancia);
    distance_error = distance_setpoint - distancia;
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
    PID_total = map(PID_total, -150, 150, 0, 150);

    if (PID_total < 20) {
      PID_total = 20;
    }
    if (PID_total > 160) {
      PID_total = 160;
    }

    myservo.write(PID_total + 30);
    distance_previous_error = distance_error;
  }
}











int sensor1(int n)
{
  long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum = sum + analogRead(sharp1);
  }
  float adc = sum / n;
  int distance_cm = 17569.7 * pow(adc, -1.2062);
  return (distance_cm);
}

int sensor2(int j)
{
  long sum = 0;
  for (int i = 0; i < j; i++)
  {
    sum = sum + analogRead(sharp2);
  }
  float adc = sum / j;
  float distance_cm = 17569.7 * pow(adc, -1.2062);
  return (distance_cm);
}
