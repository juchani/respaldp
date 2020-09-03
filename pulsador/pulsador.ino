bool est,led;
int contador;
void setup() {
Serial.begin(9600);
pinMode(12,INPUT_PULLUP);
pinMode(13,OUTPUT);
}

void loop() {
  
est=!digitalRead(12);
digitalWrite(13,led);

if(est==1){
  contador++;
  Serial.println(contador); 
  delay(500);
}

if (contador==5){
  led=!led;
  contador=0; 
}
  
}
