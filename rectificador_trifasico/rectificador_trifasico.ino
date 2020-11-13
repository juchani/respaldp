//C:\\Users\\Usuario\\AppData\\Local\\Temp\\arduino_build_875970/rectificador_trifasico.ino.hex
int valor = 0;
volatile int estado1 = 0;
int scr1 = 5, scr2 = 6, scr3 = 7, scr4 = 8, scr5 = 9, scr6 = 10;
int c = 4;
void setup() {
  attachInterrupt(0, negativo, FALLING);
  pinMode(scr1, OUTPUT);
  pinMode(scr2, OUTPUT);
  pinMode(scr3, OUTPUT);
  pinMode(scr4, OUTPUT);
  pinMode(scr5, OUTPUT);
  pinMode(scr6, OUTPUT);
  pinMode(c, OUTPUT);

}

void loop() {

  if (estado1)
  {
    //T1
    digitalWrite(scr1, HIGH);
    digitalWrite(scr5, HIGH);
    delayMicroseconds(1300);
    delayMicroseconds(10);
    digitalWrite(scr1, LOW);
    digitalWrite(scr5, LOW);
    delayMicroseconds(1800);
    //T2
    digitalWrite(scr1, HIGH);
    digitalWrite(scr6, HIGH);
    delay(1);
    digitalWrite(scr1, LOW);
    digitalWrite(scr6, LOW);
    delayMicroseconds(2000);
    //T3
    cambio();
    digitalWrite(scr3, HIGH);
    digitalWrite(scr4, HIGH);
    delay(1);
    digitalWrite(scr3, LOW);
    digitalWrite(scr4, LOW);
    delayMicroseconds(2200);
    //T4
    digitalWrite(scr3, HIGH);
    digitalWrite(scr5, HIGH);
    delay(1);
    digitalWrite(scr3, LOW);
    digitalWrite(scr5, LOW);
    delayMicroseconds(2200);
    //T5
    digitalWrite(scr2, HIGH);
    digitalWrite(scr4, HIGH);
    delay(1);
    digitalWrite(scr2, LOW);
    digitalWrite(scr4, LOW);
    delayMicroseconds(1200);
    //T6
    digitalWrite(scr2, HIGH);
    digitalWrite(scr6, HIGH);
    delay(1);
    digitalWrite(scr2, LOW);
    digitalWrite(scr6, LOW);


    estado1 = 0;
  }


}
void negativo() {
  estado1 = 1;
}

void cambio() {
  digitalWrite(c, HIGH);
  delayMicroseconds(10);
  digitalWrite(c, LOW);

}
