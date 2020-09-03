int var;
int led =3;
void setup() {
  pinMode(led,OUTPUT);
}

void loop() {
  analogWrite(led,255);

}
