
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensor1 = analogRead(A0);
  int sensor2 = analogRead(A1);
  int sensor3 = analogRead(A2);
  int sensor4 = analogRead(A3);
Serial.print("  ");
Serial.print(sensor1);
Serial.print(" ");
Serial.print(sensor2);
Serial.print(" ");
Serial.print(sensor3);
Serial.print(" ");
Serial.println(sensor4);
  delay(100);        // delay in between reads for stability
}
