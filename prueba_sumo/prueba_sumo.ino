int a1 = 4;
int a2 = 5;
int b1 = 7;
int b2 = 6;
int sensor=2;
int est=0;
int var;
void setup() {
  Serial.begin(9600);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(sensor,INPUT);
 parar();
 delay(500);
 
}
void parar() {
digitalWrite(a1,HIGH);
digitalWrite(a2,HIGH);
digitalWrite(b1,HIGH);
digitalWrite(b2,HIGH);
}

void loop() {
Serial.println(digitalRead(sensor));
ir();
if(digitalRead(sensor)==0){
  retro(500);
  parar();
  derecha();
  delay(700);
  parar();
}
}

void ir() {
digitalWrite(a2,LOW);
digitalWrite(b2,LOW);

}
void retro(int y) {
digitalWrite(a1,LOW);
digitalWrite(b1,LOW);
delay(y);
parar();
}
void izquierda(){
digitalWrite(a1,LOW);
  digitalWrite(b2,LOW);
}
void derecha(){
digitalWrite(a2,LOW);
  digitalWrite(b1,LOW);
}

