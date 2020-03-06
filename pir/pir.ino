int pir=8;
int led=13;
void setup() {
  pinMode(pir,INPUT);
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  Serial.println(digitalRead(pir));
  if (digitalRead(pir)==HIGH){
    digitalWrite(led,HIGH);
    delay(10000);
    digitalWrite(led,LOW);
  }

}
