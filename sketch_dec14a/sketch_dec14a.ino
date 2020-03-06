const int led = 2;
const int button = 1;
int button_state = 1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(led, 1);
}

void loop() {
  button_state = digitalRead(button);
  if(button_state==HIGH){
  digitalWrite(led, 0);
delay(1000);
digitalWrite(led, 1);
delay(100);
button_state = 1;
  }
}
