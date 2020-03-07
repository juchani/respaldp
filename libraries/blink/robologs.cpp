#include "robologs.h"
 
robologs::robologs(){} //Constructor: no tiene que hacer nada en especial
 
void robologs::blinking(int pin, int time)
{
    //Recibe un pin y un tiempo como parametros
    //Enciende y apaga el pin según el tiempo
 
    //Establecer pin como salida
    pinMode(pin, OUTPUT);
 
    //Encenderlo y apagarlo
    digitalWrite(pin,HIGH);
    delay(time);
    digitalWrite(pin, LOW);
    delay(time);
}