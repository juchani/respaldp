#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver();
class ss {
  private:
    int in, fin, inter, pos;
  public:
    inicio(int i, int f, int t, int p);
    int ad();
    int ret();
    int estatus();
    int forzar(int sd);
};
ss::inicio(int i, int f, int t, int p) {
  in = i;
  fin = f;
  inter = t;
  pos = p;
}
int ss:: ad() {
  if (pos < fin) {
    pos += inter ;
  }
  if (pos >= fin) {
    pos = fin;
  }
  return pos;
}
int ss:: ret() {
  if (pos > in) {
    pos -= inter ;
  }

  if (pos <= in) {
    pos = in;
  }
  return pos;
}
int ss::estatus() {
  return pos;
}
int ss:: forzar(int sd) {
  pos = sd;
  return pos;
}
unsigned pos0 = 172;
unsigned pos180 = 565;


int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
ss a11, a12, a13, a14, b11, b12, b13, b14 ;
void setup() {
  Serial.begin(9600);
  int p = 0;
  servos.begin();
  servos.setPWMFreq(60);
  a11.inicio(60, 160, 10, 60);
  a12.inicio(60, 160, 10, 60);
  a13.inicio(0, 100, 10, 0);
  a14.inicio(0, 100, 10, 0);

  b11.inicio(0, 180, 10, 180);
  b12.inicio(0, 180, 10, 180);
  b13.inicio(0, 180, 20, 0);
  b14.inicio(0, 180, 10, 0);
  subir(90);
}
void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty = map(angulo, 0, 180, pos0, pos180);
  servos.setPWM(n_servo, 0, duty);
}

void loop() {
  if (Serial.available()) { //se habilita cuando se envia un caracter (letra)
    char dato = Serial.read(); //almacemnamos lo leido en el caracter dato

    if (dato == 'm')
    {

      subir(90);
    }
    if (dato == 'a')
    {
      adelante();
      adelante();
      adelante();
    }
    else if (dato == 'r')
    {
      bajar();
    }
    else if (dato == 'd')
    {
      derecha();
      derecha();
      derecha();
      bajar();

    }
    else if (dato == 'i')
    {
      izquierda();
      izquierda();
      izquierda();
      bajar();

    }


  }


}
void subir(int ang) {

  setServo(0, a11.forzar(160));
  setServo(1, a12.forzar(160));
  setServo(2, a13.forzar(100));
  setServo(3, a14.forzar(100));
  setServo(4, b11.forzar(ang - 10));
  setServo(5, b12.forzar(ang));
  setServo(6, b13.forzar(ang));
  setServo(7, b14.forzar(ang - 10));
}
void bajar() {

  setServo(0, a11.forzar(60));
  setServo(1, a12.forzar(60));
  setServo(2, a13.forzar(0));
  setServo(3, a14.forzar(0));
  setServo(4, b11.forzar(80));
  setServo(5, b12.forzar(90));
  setServo(6, b13.forzar(90));
  setServo(7, b14.forzar(80));
}
void adelante() {
  setServo(0, a11.forzar(60));
  delay(100);
  setServo(4, b11.forzar(90));
  delay(10);
  setServo(0 , a11.forzar(160));
  delay(100);

  setServo(2, a13.forzar(0));
  delay(100);
  setServo(6, b13.forzar(45));
  delay(10);
  setServo(2 , a13.forzar(100));
  delay(100);


  setServo(1, a12.forzar(60));
  delay(100);
  setServo(5, b12.forzar(135)); //135
  delay(100);
  setServo(1 , a12.forzar(130));
  delay(100);



  setServo(3, a14.forzar(0));
  delay(100);
  setServo(7, b14.forzar(0)); //
  delay(100);
  setServo(3 , a14.forzar(60));
  delay(100);

  setServo(7, b14.forzar(90)); //45
  setServo(6, b13.forzar(135)); //45
  setServo(4, b11.forzar(0)); //45
  setServo(5, b12.forzar(45)); //90

  delay(100);

}

void izquierda() {
  setServo(0, a11.forzar(160));
  setServo(2, a12.forzar(70));
  setServo(6, b13.forzar(45));
  delay(500);
  setServo(4, b11.forzar(100));
  delay(500);
  setServo(0, a11.forzar(60));

  setServo(4, b11.forzar(0));
  delay(500);
  setServo(0, a11.forzar(160));



  delay(1000);

}
void derecha() {
  setServo(2, a13.forzar(120));
  setServo(0, a11.forzar(150));
  setServo(4, b11.forzar(95));
  delay(500);
  setServo(6, b13.forzar(135));
  delay(500);
  setServo(6, b13.forzar(20));
  delay(500);
  setServo(2, a13.forzar(0));

  delay(50);
  setServo(6, b13.forzar(135));

  delay(50);
  //setServo(6,b13.forzar(20));
  //delay(500);
  //setServo(2,a13.forzar(60));



  delay(100);

}
