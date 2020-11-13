
void arriba () {
  digitalWrite(dirPin, LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 32766 ; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }
  delay(1000);

}
void abajo() {
  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 32766 ; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(100);
  }
  delay(1000);
}

void horizontal1() {
  digitalWrite(dir1, HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 9500 ; x++) {
    digitalWrite(step1, HIGH);
    delayMicroseconds(500);
    digitalWrite(step1, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}

void horizontal0() {
  digitalWrite(dir1, LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 9000 ; x++) {
    digitalWrite(step1, HIGH);
    delayMicroseconds(500);
    digitalWrite(step1, LOW);
    delayMicroseconds(500);
  }

}
