#include <Servo.h>

Servo pinzas;
Servo el;
Servo brazo;
Servo eje;
class ss {
  private:
    int in, fin, inter, pos;
  public:
    inicio(int i, int f, int t, int p);
    int ad();
    int ret();
    int estatus();
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

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
ss a, b, c, d;
void setup() {
  eje.attach(2);
  el.attach(3);
  brazo.attach(4);
  pinzas.attach(5);

  Serial.begin(9600);
  a.inicio(0, 90, 10, 45);
  b.inicio(0, 90, 10, 45);
  c.inicio(0, 90, 20, 45);
  d.inicio(0, 180, 20, 90);
  eje.write(d.estatus());
  el.write(c.estatus());
  brazo.write(b.estatus());
  pinzas.write(a.estatus());
}

void loop() {
  if (Serial.available()) {
    char da = Serial.read();
    if (da == 'd') {
      eje.write(d.ad());
    }
    if (da == 'e') {
      eje.write(d.ret());
    }
    if (da == 'f') {
      el.write(c.ad());
    }
    if (da == 'g') {
      el.write(c.ret());
    }
    if (da == 'h') {
      brazo.write(b.ad());
    }
    if (da == 'i') {
      brazo.write(b.ret());
    }
    if (da == 'j') {
      pinzas.write(a.ad());
    }
    if (da == 'k') {
      pinzas.write(a.ret());
    }
  }
  Serial.print(a.estatus());
  Serial.print("  ");
  Serial.print(b.estatus());
  Serial.print("  ");
  Serial.print(c.estatus());
  Serial.print("  ");
  Serial.println(d.estatus());

  delay(50);

}

