int tiempo, distancia;
void setup() {
  pinMode(7, INPUT);//echo
  pinMode(6, OUTPUT);//trig
pinMode(4,OUTPUT);
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
 if(distancia > 2 && distancia<150){   
   Serial.println(distancia);
   if (distancia>10){
   digitalWrite(4,0); 
   }
   if (distancia<10){
    digitalWrite(4,1); 
   }
}
}
