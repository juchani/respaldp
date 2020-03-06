#include <EEPROM.h>
int valor;
int sensor;
int direccion=0;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  delay(5000);
  Serial.println(EEPROM.read(direccion));
}

void loop() {
  sensor = secuencia(500, 500);
  Serial.println(sensor);
}
