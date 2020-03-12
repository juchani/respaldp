int led1 = 3, led2 = 5, led3 = 7, led4 = 9, led5 = 11, led6 = 13, led7 = A0, led8 = A2;
int bt1 = 2, bt2 = 4, bt3 = 6, bt4 = 8, bt5 = 10, bt6 = 12, bt7 = A1;
bool c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A2, OUTPUT);

  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt3, INPUT_PULLUP);
  pinMode(bt4, INPUT_PULLUP);
  pinMode(bt5, INPUT_PULLUP);
  pinMode(bt6, INPUT_PULLUP);
  pinMode(bt7, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(bt1));
  bool e1 = !digitalRead(bt1);
  bool e2 = !digitalRead(bt2);
  bool e3 = !digitalRead(bt3);
  bool e4 = !digitalRead(bt4);
  bool e5 = !digitalRead(bt5);
  bool e6 = !digitalRead(bt6);
  bool e7 = !digitalRead(bt7);
  if ( e1) {
    digitalWrite(led1, HIGH);
    Serial.println("sec1");
  }

  if ( e2 ) {
    Serial.println("sec2");
    digitalWrite(led1, LOW);
    delay(2000);
    digitalWrite(led2, HIGH);
  }

  if ( e3 ) {
    Serial.println("sec3");
    digitalWrite(led2, LOW);
    delay(2000);
    digitalWrite(led3, HIGH);
  }
  if ( e4 ) {
    Serial.println("sec4");
    delay(2000);
    digitalWrite(led4, HIGH);
  }

  if ( e5 ) {
    Serial.println("sec5");
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    delay(2000);
    digitalWrite(led5, HIGH);
  }
  if ( e6 ) {
    Serial.println("sec6");
    digitalWrite(led5, LOW);
    delay(2000);
    digitalWrite(led6, HIGH);

    // digitalWrite(led7, HIGH);
  }
  if ( e7 ) {
    Serial.println("sec7");
    digitalWrite(led6, LOW);
    delay(2000);
    digitalWrite(A2, HIGH);
    delay(2000);
    digitalWrite(A2, 0);
  }



}
