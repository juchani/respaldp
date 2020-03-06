int led[]={4,5,6,7};
int encendido;
int apagado;
void setup() {
 pinMode(led[0],OUTPUT);
 pinMode(led[1],OUTPUT);
 pinMode(led[2],OUTPUT);
 pinMode(led[3],OUTPUT);  
}

void loop() {
  encendido=random(0,5);
digitalWrite(led[encendido],1);
delay(100);  
  apagado=random(0,5);
  digitalWrite(led[apagado],0);
delay(100);
}
