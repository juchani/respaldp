#include <AccelStepper.h>
 
AccelStepper stepper(5 , 6, 7);//(define el tipo de control del motor,pin de paso,pin direccion)
 
int pos = 100;
 
void setup()
{
  stepper.setMaxSpeed(800); //velocidad maxima permitida
  stepper.setAcceleration(500);// relacion entre aceleracion/desaceleracion
}
 
void loop()
{
  if (stepper.distanceToGo() == 0)//distancia de la posicion actual y la destino
 
  {
    delay(500);
    pos = -pos;
    stepper.moveTo(pos);//establece la posicion de destino
  }
  stepper.run();
}
