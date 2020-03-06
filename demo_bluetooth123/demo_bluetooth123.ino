#include <SoftwareSerial.h>

SoftwareSerial BT1(1,2); // RX, TX
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  BT1.begin(9600);
 
}

void loop() {

  if (BT1.available()) {
     char dato= BT1.read();
  Serial.println(dato);
  }}
