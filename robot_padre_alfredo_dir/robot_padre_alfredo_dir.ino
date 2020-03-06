//Pines de conexión del driver
#include <Servo.h>
int grados;
Servo myservo;
int Pin_Motor_Der_A = 9;
int Pin_Motor_Der_B = 10;
int Pin_Motor_Izq_A = 11;
int Pin_Motor_Izq_B = 12;
int tiempo=0;
int plasma=6;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  myservo.attach(7);
  // configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
pinMode(plasma,OUTPUT);
digitalWrite(plasma,HIGH);
}

void loop() {

  if (Serial.available()) {
     char dato= Serial.read();
     if(dato=='a')
     {
        Mover_Adelante();
        tiempo=0;
     }
     else if(dato=='r')
     { 
        Mover_Retroceso();
        tiempo=0;
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
        servo_sec1();
     }
   else if(dato=='x'){
       digitalWrite(plasma,0);
       delay(1000);
       digitalWrite(plasma,1);
     }
       else if(dato=='m'){
        grados=180;
        servo_sec3(grados);
     }
   else if(dato=='n'){
        grados=10;
        servo_sec4(grados);
        //delay(1000);
     }

  }

  if(tiempo<500) // 1000   cilcos de 1ms 
  {    
    tiempo=tiempo+1;
  }
  else   //ya transcurrió 100ms (100ciclos)
  {
    Mover_Stop();
  }
  
  
  delay(1); //pasusa de 1ms por ciclo
  
}

void Mover_Adelante()
{
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  
}
void Mover_Retroceso()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  
}
void Mover_Derecha()
{
  digitalWrite (Pin_Motor_Izq_A,HIGH);
  digitalWrite (Pin_Motor_Izq_B,LOW);
  Mover_Adelante();
}
void Mover_Izquierda()
{
  
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
  Mover_Adelante();
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
void servo_sec3(int contador){
  myservo.write(contador);
}
void servo_sec4(int contador){

  myservo.write(contador);
}

