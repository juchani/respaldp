int m1 = 2;
int m2 = 3;
int m3 = 4;
int m4 = 5;
void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}

void loop() {
  adelante();
  delay(1000);
  apagado();
  atras();
  delay(1000);
  apagado();
  izquierda();
  delay(1000);
  derecha();
  delay(1000);
}
void adelante () {
  
  digitalWrite(m2, 1);
  digitalWrite(m3, 1);
}
void atras () {
  
  digitalWrite(m1, 1);
  digitalWrite(m4, 1);
}
void apagado() {
  digitalWrite(m1, 0);
  digitalWrite(m2, 0);
  digitalWrite(m3, 0);
  digitalWrite(m4, 0);
}
void derecha(){
  apagado();
  digitalWrite(m4, 1); 
}
void izquierda(){
  apagado();
  digitalWrite(m1, 1);
}

