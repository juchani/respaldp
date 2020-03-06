unsigned int tiempo, distancia;
int cont = 0 ;
int t, piso, altura = 14;
int m1 = 8, m2 = 9,vel=10,f=227;
int bt1=2,bt2=3,bt3=4;
void setup() {
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(vel, OUTPUT);
  Serial.begin(9600);
  pinMode(bt1,INPUT_PULLUP);
  pinMode(bt2,INPUT_PULLUP);
  pinMode(bt3,INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop() {
  digitalWrite(6, LOW);
  delayMicroseconds(2);
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  tiempo = pulseIn(7, HIGH);


  distancia = tiempo / 58;


  delay(200);


  if (distancia >= 2 && distancia <= 32) {
    piso = distancia;
    Serial.println(piso);
  }
  if (piso >= altura && piso <= altura + 1) {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(13, LOW );
    delay(100);
  }
  else {
    if (piso < altura) {
      
analogWrite(vel,203);
      digitalWrite(13, HIGH);
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
    }
    if (piso > altura) {

analogWrite(vel,f);
digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(13, HIGH);

    }




  }
if(digitalRead(bt1)==0){
  altura=27;
}
if(digitalRead(bt2)==0){
  altura=15;
}
if(digitalRead(bt3)==0){
  altura=5;
}
}
