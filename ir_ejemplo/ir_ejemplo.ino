//ejemplo arduino -processing 
//desarrollado para MAKE IT YOURSELF
//EL DOMINIO DE  ESTE CODIGO ES PUBLICO
//para  mas informacion:www.youtubw.com/c/Juchani
#include "IRremote.h"
int receptor = 11;

IRrecv irrecv(receptor);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}


void loop()
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value == 0xFF02FD) {
      Serial.println("ok");

    }
    if (results.value == 0x1BC0157B) {
      Serial.println("abajo");
    }
    if (results.value == 0xFF22DD) {
      Serial.println("izquierda");
    }
    if (results.value == 0xFFC23D) {
      Serial.println("derecha");
    }
    if (results.value == 0x3D9AE3F7) {
      Serial.println("arriba");
    }
    if (results.value == 0xFF4AB5) {
      Serial.println(0);
    }

    irrecv.resume();
  }

  delay(300);
}
