const int dirPin = 8;
const int stepPin = 9;
 
const int steps = 200;
int stepDelay;
 
void setup() {
   // Marcar los pines como salida
   pinMode(dirPin, OUTPUT);
   pinMode(stepPin, OUTPUT);
   Serial.begin(9600);
}
 
void loop() {
   //Activar una direccion y fijar la velocidad con stepDelay
   digitalWrite(dirPin, HIGH);
   stepDelay+=10;
   // Giramos 200 pulsos para hacer una vuelta completa
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepDelay);
   Serial.println(stepDelay);
   delay(500);
 
   //Cambiamos la direccion y aumentamos la velocidad
 
}
