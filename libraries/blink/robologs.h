//Tutorial de librerias personalizadas con Arduino
//
//Escrita por Transductor
//www.robologs.net
 
//Primero los include guards
#ifndef ROBOLOGS_H
#define ROBOLOGS_H
 
//Cambia Arduino.h por Wprogram.h si usas una version antigua de la IDE.
#include <Arduino.h> //Permite utilizar los comandos de Arduino
 
class robologs //Definicion de la clase
{
 
    public:
 
    //Constructor de la clase
    robologs();
 
    //Funcion blinking: enciende el led 'pin', espera 'time' segundos y lo apaga
    void blinking(int pin, int time);
 
    private:
 
    //Nada que declarar
};
 
#endif