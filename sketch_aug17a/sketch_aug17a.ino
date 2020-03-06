void setup() {
pinMode(5,INPUT);
pinMode(6,INPUT);
Serial.begin(9600);
}

void loop() {
Serial.print(digitalRead(5));
Serial.print('\t');
Serial.println(digitalRead(6));
}
