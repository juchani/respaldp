 int led=12;
int tiempo=1000;
void setup() {
pinMode(led,OUTPUT); 
}

void loop() {
 digitalWrite(led,HIGH);//enciende  led que se encuentra en el pin 13
 delay(tiempo);
 digitalWrite(led,LOW);
 delay(tiempo);
}

