int l = 13;
int b = 3;
void setup() {
  pinMode(l, OUTPUT);
  pinMode(b, INPUT_PULLUP);
  
}

void loop() {
  digitalWrite(l, !digitalRead(b));
 // delay(100);
}
