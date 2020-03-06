unsigned int tiempo, distancia;
int d,led1=3;

void setup() {
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);

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


  if (distancia >= 2 && distancia <= 300) {
     d= distancia;
     }
     if(d<10){
      digitalWrite(led1,HIGH);
      Serial.println("bomba activada");
     }
     if(d>50){
      digitalWrite(led1,LOW);
      Serial.println("bomba desactivada");

     }
  Serial.println(String(d)+" CM");
}
