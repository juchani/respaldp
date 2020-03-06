//Pines de conexión del driver
//motor derecho
int Pin_Motor_Der_A = 3;//int es un numero entero 2-3-4
int Pin_Motor_Der_B = 2;
//motor izquierdo
int Pin_Motor_Izq_A = 5;
int Pin_Motor_Izq_B = 4;
// variables de sensor
int MQ135;
int limite=500;
//variable buzzer
int buzzer=13;
//variables de tiempo
int tiempo=0;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
 MQ135=analogRead(A0);
 if (MQ135> limite){
  digitalWrite(buzzer,HIGH);
 }
 else{
digitalWrite(buzzer,LOW);
  
 }
  if (Serial.available()) { //se habilita cuando se envia un caracter (letra)
     char dato= Serial.read();//almacemnamos lo leido en el caracter dato
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
     

  }

  if(tiempo<1000) // 100 cilcos de 1ms 
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
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void Mover_Retroceso()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Derecha()
{
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,HIGH);
  digitalWrite (Pin_Motor_Izq_B,LOW);
}
void Mover_Izquierda()
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
