void arriba1 () {
  digitalWrite(dirPin, LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 20666 ; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }
  delay(1000);

}
void abajo1() {
  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 20666 ; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }
  delay(1000);
}
