int a=11;
void setup() {
 pinMode(a,OUTPUT);
 pinMode(5,OUTPUT);
}

void loop() {
 digitalWrite(a,HIGH);
 digitalWrite(5,HIGH);
 delay(2000);
 digitalWrite(a,LOW);
 digitalWrite(5,LOW);
 delay(2000);
}
