int f;
void setup() {
Serial.begin(9600);
}

void loop() {
 f=(f+1)%12;
 Serial.println(f);
 delay(500);
}
