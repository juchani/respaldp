int led =9;
int led1=8;
void setup() {
  pinMode(led,OUTPUT);
pinMode(led1,OUTPUT);
}

void loop() {
  digitalWrite(led,HIGH);
  //digitalWrite(led1,LOW);
  delay(1000);
 digitalWrite(led,LOW);
 // digitalWrite(led1,HIGH);

delay(1000);

}
