#include <Servo.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

// La dirección del MPU6050 puede ser 0x68 o 0x69, dependiendo
// del estado de AD0. Si no se especifica, 0x68 estará implicito
MPU6050 sensor;

// Valores RAW (sin procesar) del acelerometro y giroscopio en los ejes x,y,z
int ax, ay, az;
int gx, gy, gz;
int Y_A, Y_B,X_A;
Servo AA;
Servo AB;
Servo BA;
Servo BB;
Servo CA;
Servo CB;
void setup() {
  AA.attach(2);
  AB.attach(3);
  BA.attach(4);
  BB.attach(5);
  CA.attach(6);
  CB.attach(7);
  Serial.begin(9600);    //Iniciando puerto serial
  Wire.begin();           //Iniciando I2C
  sensor.initialize();    //Iniciando el sensor

  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");

  servoA(150);
  servoB(170);
  servoC(180);
}

void loop() {
  giroscopio();
 // rev1();
  
}

void giroscopio() {
  // Leer las aceleraciones y velocidades angulares
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);

  //Mostrar las lecturas separadas por un [tab]
  Serial.print("y:\t");
  ax = map(ax, -16000, 16000, 180, 0);
  ay = map(ay, -16000, 16000, 180, 0);
  Serial.print(ax); Serial.println("\t");
  //Serial.print(ay); Serial.println("\t");
  //Serial.print(az); Serial.println("\t");

 // delay(100);
}

void rev1() {
  int y,x;
  y = ay - 90;
  x=ax-90;
  Serial.println(x);
  if (y > -4 && y < 4) {
    if (x > -4 && x < 4) {
      
    }
     if (x < -1) {
      X_A=X_A-1;
      servoC(X_A);
      delay(15);
     }
      if (x >1) {
      X_A=X_A+1;
      servoC(X_A);
      delay(15);
     }
    Serial.println("CENTRADO");
  }
  if (y > 1) {
    Y_A=Y_A-1;
    Y_B=Y_B+1;
    servoA(Y_A);
    servoB(Y_B);
    delay(15);
  }
  if (y < -1) {
    Y_A=Y_A+1;
    Y_B=Y_B-1;
    servoA(Y_A);
    servoB(Y_B);
    delay(15);
  }
}

void servoA(int angulo) {
  int angulob;
  if (angulo>180){
    angulo=180;
  }
  if (angulo<0){
    angulo=0;
  }
  angulob = map(angulo, 0, 180, 180, 0);
  AA.write(angulo);
  AB.write(angulob);
  Y_A = angulo;
  
}

void servoB(int angulo) {
  int angulob;
  if (angulo>180){
    angulo=180;
  }
  if (angulo<0){
    angulo=0;
  }
  angulob = map(angulo, 0, 180, 180, 0);
  BB.write(angulo);
  BA.write(angulob);
 
  Y_B = angulo;
}

void servoC(int angulo) {
  int angulob;
  if (angulo>180){
    angulo=180;
  }
  if (angulo<0){
    angulo=0;
  }
  angulob = map(angulo, 0, 180, 180, 0);
  CB.write(angulo);
  CA.write(angulob);
 X_A=angulo;
 
}
