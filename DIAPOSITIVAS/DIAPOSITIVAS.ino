

#include <Ultrasonic.h>

Ultrasonic ultrasonic(4,5); // (Trig PIN,Echo PIN)
Ultrasonic ultrasonic1(11,12); // (Trig PIN,Echo PIN)
int ds;
int ds1;
int contador=1;
void setup() {
  Serial.begin(9600); 
  Serial.print(contador);
    Serial.print(",");
    Serial.println("3");
}

void loop()
{
  control();
  
}
