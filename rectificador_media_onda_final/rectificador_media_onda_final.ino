//C:\\Users\\Usuario\\AppData\\Local\\Temp\\arduino_build_823601/rectificador_media_onda_final.ino.hex
int valor = 0;
volatile bool estado1 = 0;
int dt = 50;
int scr1 = 9, scr2 = 10, scr3 = 11, scr4 = 12;
int c = 4;
void setup() {
  attachInterrupt(0, negativo, RISING);
  pinMode(scr1, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(scr2, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(scr3, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(scr4, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(c, OUTPUT);
}

void loop() {
  valor = map(dt, 0, 100, 8333, 10);
  if (estado1)
  {
    delayMicroseconds(valor);
    digitalWrite(scr2, HIGH);
    digitalWrite(scr4, HIGH);
    delayMicroseconds(10);
    digitalWrite(scr2, LOW);
    digitalWrite(scr4, LOW);
    cambio();
    delayMicroseconds(8333);
    digitalWrite(scr1, HIGH);
    digitalWrite(scr3, HIGH);
    delayMicroseconds(10);
    digitalWrite(scr1, LOW);
    digitalWrite(scr3, LOW);
    cambio();


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
