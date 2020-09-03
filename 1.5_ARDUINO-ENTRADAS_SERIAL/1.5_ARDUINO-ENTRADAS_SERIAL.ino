int b=3;
void setup() {
Serial.begin(9600);
pinMode(b,INPUT_PULLUP);
}

void loop() {
Serial.println(digitalRead(b));
}
