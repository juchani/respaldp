int a=5;
void setup() {
Serial.begin(9600);
pinMode(2,INPUT);
pinMode(a,OUTPUT);
}

void loop() {
  Serial.println(digitalRead(2));
  digitalWrite(a,LOW);
}
