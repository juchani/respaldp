const int bt = 2;
const int led = 5;

void setup() {
  DDRD = B100000; //pinMode(led,OUTPUT);
  PORTD=100; //pinMode(bt, INPUT_PULLUP);
 }

void loop() {
  int btn = !digitalRead(bt);
  digitalWrite(led, btn);

}
