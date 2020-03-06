int dem=2;
void setup() {
 pinMode(dem,OUTPUT);
 digitalWrite(dem,HIGH);
}

void loop() {
digitalWrite(dem,LOW);
delay(1000);
digitalWrite(dem,HIGH);
delay(1000);
}
