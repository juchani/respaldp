void setup() {
pinMode(0,OUTPUT);
}

void loop() {
  moverServo(0,160);
  delay(100);
 
}
void moverServo (int pin, int angulo)
{
   float pausa;
   pausa = angulo*2000.0/180.0 + 500;
   digitalWrite(pin, HIGH);
   delayMicroseconds(pausa);
   digitalWrite(pin, LOW);
   delayMicroseconds(2500-pausa);
}
