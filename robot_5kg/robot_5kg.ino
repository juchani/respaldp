#include <Servo.h>
Servo s1;
Servo s2;
int s1_min=180, s1_max=0;
int s2_min=0, s2_max=95;
int tiempo = 0;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  
}

void loop() {
  if (Serial.available()) {
    char dato = Serial.read();
    if (dato == 'a')
    {
      Mover_Adelante();
      tiempo = -100;

    }
    else if (dato == 'r')
    {
      Mover_Retroceso();
      tiempo = 0;
      tiempo = -100;
    }
    else if (dato == 'd')
    {
      Mover_Derecha();
      tiempo = 0;
    }
    else if (dato == 'i')
    {
      Mover_Izquierda();
      tiempo = 0;
    }



  }

  if (tiempo < 100) // 1000   cilcos de 1ms
  {
    tiempo = tiempo + 1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    Stop();
  }


//  delay(1); //pasusa de 1ms por ciclo

delay(10);
}

void Mover_Adelante()
{
  active();
  s1.write(s1_max); 
  s2.write(s2_max);
}
void Mover_Retroceso()
{
  active();
  s1.write(s1_min); 
  s2.write(s2_min);
}
void Mover_Derecha()
{
}
void Mover_Izquierda()
{
}
void Stop()
{
  s1.detach();
  s2.detach();
}
void active(){
  s1.attach(9);
  s2.attach(8);
}
