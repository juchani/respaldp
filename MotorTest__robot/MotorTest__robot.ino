
#include <IRremote.h>
#include <AFMotor.h>

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);

decode_results results;
int t=300;

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  irrecv.enableIRIn(); // Start the receiver
  // turn on motor
  motor3.setSpeed(250);
  motor4.setSpeed(250);

  //  motor.run(RELEASE);
}
void adelante() {
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(t+500);
  parar();
}
void retro() {
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(t+500);
  parar();

}
void derecha() {
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(t);
  parar();
}
void izquierda() {
  motor4.run(FORWARD);
  motor3.run(BACKWARD);
  delay(t);
  parar();
}
void parar() {

  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void loop() {
  if (irrecv.decode(&results))

  {
    switch (results.value)
    {
      case 0xFF18E7: Serial.println("Tecla: Arriba"); adelante();
        break;
      case 0xFF10EF: Serial.println("Tecla: Izquierda"); derecha();
        break;
      case 0xFF5AA5: Serial.println("Tecla: Derecha"); izquierda();
        break;
      case 0xFF4AB5: Serial.println("Tecla: Abajo"); retro();
        break;
    }
    irrecv.resume();
  }
  delay(300);
}
