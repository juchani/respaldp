#include <VirtualWire.h>  //  libreria para los modulos RF
int pinBoton = 7;         // para la lectura del boton
int boton = 0;            // estado del boton

void setup()
   { 
      vw_setup(2000);     //  iniciamos la comunicacion por radio
      pinMode(pinBoton, INPUT_PULLUP);  // definimos como entrada
   }

void loop()
   {  boton = digitalRead(pinBoton);    // leemos la entrada
      if(boton == LOW)                  // si se ha pulsado
         {  send("activar");            // enviamos activar
            delay(100);
         }
   }

//Funcion para enviar el mensaje
void send (char *message)
   {  vw_send((uint8_t *)message, strlen(message)); //Envia el mensaje
      vw_wait_tx();         // Espera hasta acabar de transmitir todo
   } 
