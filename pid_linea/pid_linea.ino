#include <QTRSensors.h>
#define NUM_SENSORS 5 // number of sensors used
#define NUM_SAMPLES_PER_SENSOR 4 // average 4 analog samples per sensor reading
#define EMITTER_PIN QTR_NO_EMITTER_PIN
#define m_i 5
#define m_d 10
#define pin_pwm_i 6
#define pin_pwm_d 11
QTRSensorsAnalog qtra((unsigned char[]) { 4,3,2,1,0},NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];
unsigned int position = 0;
int boton = 12;
int derivativo = 0, proporcional = 1, integral = 0;
int salida_pwm = 0, proporcional_pasado = 0;
int velocidad = 40;
float Kp = 1, Kd = 1, Ki = 0;
int linea = 0;
void setup() {
  // put your setup code here, to run once:
  delay(800);
  pinMode(m_i, OUTPUT);
  pinMode(m_d, OUTPUT);
  pinMode(pin_pwm_i , OUTPUT);
  pinMode(pin_pwm_d, OUTPUT);
  for (int i = 0; i < 40; i++) {
    delay(20);
    qtra.calibrate();
    delay(20);
  }
  //digitalWrite(led1,LOW);
  delay(400);
  //digitalWrite(led1,HIGH);
  while (true) {
    int x = digitalRead(boton);
    delay(100);
    if (x == 1) {
    //  digitalWrite(led1, HIGH);
      delay(100);
      break;
    }
  }
  Serial.begin(9600);
}

void loop() {
  pid(linea, velocidad, Kp, Ki, Kd);

  frenos_contorno(linea, 700);
}
void pid(int linea, int velocidad, float Kp, float Ki, float Kd) {
  position = qtra.readLine(sensorValues, QTR_EMITTERS_ON, linea);
  Serial.println(position);
  proporcional = (position) - 3500;
  integral = integral + proporcional_pasado;
  derivativo = (proporcional - proporcional_pasado);
  if (integral > 1000) integral = 1000;
  if (integral < -1000) integral = -1000;
  salida_pwm = (proporcional * Kp) + (derivativo * Kd) + (integral * Ki);
  if (salida_pwm > velocidad)salida_pwm = velocidad;
  if (salida_pwm < -velocidad)salida_pwm = -velocidad;

  if (salida_pwm < 0) {
    motores(velocidad + salida_pwm, velocidad);
  }
  if (salida_pwm > 0) {
    motores(velocidad, velocidad - salida_pwm);
  }
  proporcional_pasado = proporcional;
}
void motores(int motor_izq, int motor_der) {
  if (motor_izq >= 0) {
    digitalWrite(m_i, LOW);
    analogWrite(pin_pwm_i, 255 - motor_izq);
  }
  else {
    digitalWrite(m_i, LOW);
    motor_izq = motor_izq * (-1);
    analogWrite(pin_pwm_i, motor_izq);
  }
  if (motor_der >= 0) {
    digitalWrite(m_d, LOW);
    analogWrite(pin_pwm_d, 255 - motor_der);
  }
  else {
    digitalWrite(m_d, LOW);
    motor_der = motor_der * (-1);
    analogWrite(pin_pwm_d, motor_der);
  }
}

void frenos_contorno (int tipo, int flanco_comparacion) {
  if (tipo == 0) {
    if (position <= 500) {
      motores(0, 150);
      while (true) {
        qtra.read(sensorValues);
        if (sensorValues[0] > flanco_comparacion || sensorValues[1] > flanco_comparacion) {
          break;
        }
      }
    }
    if (position >= 6550) {
      motores(150 , 0);
      while (true) {
        qtra.read(sensorValues);
        if (sensorValues[7] > flanco_comparacion || sensorValues[6] > flanco_comparacion) {
          break;
        }
      }
    }
  }





  if (tipo == 1) {
    if (position <= 500) {
      motores(0, 180);
      while (true) {
        qtra.read(sensorValues);
        if (sensorValues[0] < flanco_comparacion || sensorValues[1] < flanco_comparacion) {
          break;
        }
      }
    }
    if (position >= 3500) {
      motores(180, 0);
      while (true) {
        qtra.read(sensorValues);
        if (sensorValues[7] > flanco_comparacion || sensorValues[6] > flanco_comparacion) {
          break;
        }
      }
    }
  }
}
