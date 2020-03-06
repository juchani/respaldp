#include <Ultrasonic.h>

Ultrasonic ultrasonic(7,8);
int est;  
 //Pines de conexión del driver
int grados;
int Pin_Motor_Der_A = 9;
int Pin_Motor_Der_B = 10;
int Pin_Motor_Izq_A = 11;
int Pin_Motor_Izq_B = 12;
int tiempo=0;
int plasma=13;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
pinMode(plasma,OUTPUT);

}

void loop() {
if(ultrasonic.Ranging(CM)<20){
Mover_Retroceso();
 delay(100);
  Mover_Izquierda();
      delay(100);
      Mover_Stop();
digitalWrite(plasma,1);
}
  if (Serial.available()) {
     char dato= Serial.read();
     if(dato=='a')
     {
        Mover_Adelante();
        tiempo=-100;
        
     }
     else if(dato=='r')
     { 
        Mover_Retroceso();
        tiempo=0;
    tiempo=-100;
     }
     else if(dato=='d')
     { 
        Mover_Derecha();
        tiempo=0;
     }
     else if(dato=='i')
     { 
        Mover_Izquierda();
        tiempo=0;
     } 
     else if(dato=='y'){
      est=1;
     }
   else if(dato=='x'){
      est=0;
     }
       else if(dato=='m'){
        grados=180;
     }
   else if(dato=='n'){
        grados=0;
        //delay(1000);
     }

  }
if(est==1) // 1000   cilcos de 1ms 
  {    
    tiempo=1;
    Mover_Adelante();
  }
  if(tiempo<100) // 1000   cilcos de 1ms 
  {    
    tiempo=tiempo+1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    Mover_Stop();
    digitalWrite(plasma,0);
  }
  
  
  delay(1); //pasusa de 1ms por ciclo
  
}

void Mover_Adelante()
{
 
  
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Retroceso()
{
digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
  
}
void Mover_Izquierda()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,HIGH);
  digitalWrite (Pin_Motor_Izq_B,LOW);
}
void Mover_Derecha()
{
  digitalWrite (Pin_Motor_Der_A,HIGH);
  digitalWrite (Pin_Motor_Der_B,LOW);
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Stop()
{
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void servo_sec1(){
digitalWrite(plasma,0);



}
void servo_sec2(){
digitalWrite(plasma,1);

}

