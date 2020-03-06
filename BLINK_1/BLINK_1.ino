int c,d, dato1, dato2;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  dato1, dato2 = led(1000);
  Serial.print(dato1);
  Serial.print(" ");
  Serial.println(dato2);

}

int led(int tiempo ) {

  digitalWrite(13, HIGH);
  delay(tiempo);
  digitalWrite(13, LOW);
  delay(tiempo);
  c++;
  d=tiempo;
  return c , d;
}

