bool est;
int contador;
void setup() {
 Serial.begin(9600);
 pinMode(12,INPUT_PULLUP);
}

void loop() {
  est=!digitalRead(12);
  Serial.println(contador);
 if(est==1){
  contador++;
  delay(500);
 }


  
}
