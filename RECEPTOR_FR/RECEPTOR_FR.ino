#include <VirtualWire.h>  // libreria para utilizar los modulos RF

byte message[VW_MAX_MESSAGE_LEN]; //Creamos un mensaje
byte messageLength = VW_MAX_MESSAGE_LEN; //La constante VW_MAX_MESSAGE_LEN viene definida en la libreria

void setup()
   {  pinMode(13, OUTPUT);          //Configuramos el pin 13
      pinMode(7, OUTPUT);           //pines para el motor
      pinMode(8, OUTPUT);

      vw_setup(2000);         // iniciamos la comunicacion por radio
      vw_rx_start();
   }

void loop()
   { analogWrite(7,0);        // apagamos motor
     analogWrite(8,0);

     if (vw_get_message(message, &messageLength)) // leemos el mensaje          { if(comparar("activar") == 0)
            { // comparamos el mensaje
              digitalWrite(13, HIGH);     // encendemos LED
              analogWrite(7,180); // encendemos motor en un sentido
              analogWrite(8,0); // el valor 180 controla la velocidad de giro
              delay(4000);            // esperamos 4 segundos
              analogWrite(7,0);       // apagamos motor
              analogWrite(8,0);
              delay(3000);            // esperamos 3 segundos
              analogWrite(7,0);   // encendemos motor en sentido opuesto
              analogWrite(8,180);
              delay(4000);             // esperamos 4 segundos
              analogWrite(7,0);        // apagamos motor
              analogWrite(8,0);
              digitalWrite(13, LOW);      // apagamos LED
            }
        }
  

char comparar(char* cadena) 
   {   // Esta funcion compara el string cadena con el mensaje recibido.
       // Si son iguales, devuelve 1. Si no, devuelve 0.

       for(int i = 0; i<messageLength; i++)  
          {    if(message[i] != cadena[i])  
                  return 1;
          }
       return 0;
   }
