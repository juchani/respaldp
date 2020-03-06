int t =2000;
int m1=2;
int m2=3;
int m3=4;
int m4=5;
void setup() {
 pinMode(m1,OUTPUT);
 pinMode(m2,OUTPUT);
 pinMode(m3,OUTPUT);
 pinMode(m4,OUTPUT);
adelante();
delay(1000);
parar();
atras();
delay(1000);
parar();
derecha();
delay(1000); 
parar();
izquierda();
delay(1000);
}

void loop() {



parar();
}

void adelante(){
  digitalWrite(m1,HIGH);
  digitalWrite(m4,HIGH);
}

void atras(){
    digitalWrite(m2,HIGH);
  digitalWrite(m3,HIGH);
}
void parar(){
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
void izquierda(){
  digitalWrite(m1,HIGH);
}
void derecha(){
  digitalWrite(m3,HIGH);
}

