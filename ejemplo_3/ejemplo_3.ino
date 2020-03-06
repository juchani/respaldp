int estado;
int led=13;
void setup() {
Serial.begin(9600); 
pinMode(led,OUTPUT);
}

void loop() {
 estado=analogRead(A0);
 Serial.println(estado);
if(estado>600){
digitalWrite(led,HIGH); 
}
else{
  digitalWrite(led,LOW);
}
}
