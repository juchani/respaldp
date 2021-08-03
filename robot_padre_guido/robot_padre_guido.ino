
int est;
//Pines de conexión del driver
int Pin_Motor_Der_A = 9;
int Pin_Motor_Der_B = 8;
int Pin_Motor_Izq_A = 7;
int Pin_Motor_Izq_B = 6;
int c = 0;

int en1=10;
int en2=11;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  analogWrite(en1,250);
  analogWrite(en2,255);
}

void loop() {
  if (Serial.available()) {
    char dato = Serial.read();
    if (dato == 'a')
    {
      Mover_Adelante();
      c = 0;

    }
    else if (dato == 'r')
    {
      Mover_Retroceso();
      c = 0;
      
    }
    else if (dato == 'd')
    {
      
      Mover_Derecha();
      delay(100);
      Mover_Stop();
      c = 0;
    }
    else if (dato == 'i')
    {
      Mover_Izquierda();
delay(100);      
      Mover_Stop();
      c = 0;
    }
    else if (dato == 's')
    {
    Mover_Stop();
      c = 0;
    }    
  }
   if (c > 500) // 1000   cilcos de 1ms
  {
    c =0;
    Mover_Stop();    
  }
  




  delay(1); //pasusa de 1ms por ciclo
c++;

}

void Mover_Adelante()
{
  digitalWrite (Pin_Motor_Der_A, LOW );
  digitalWrite (Pin_Motor_Der_B, HIGH );
  digitalWrite (Pin_Motor_Izq_A, LOW );
  digitalWrite (Pin_Motor_Izq_B, HIGH );
}
void Mover_Retroceso()
{
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);

}
void Mover_Derecha()
{
  digitalWrite (Pin_Motor_Der_A, LOW );
  digitalWrite (Pin_Motor_Der_B, HIGH );
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void Mover_Izquierda()
{
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW );
  digitalWrite (Pin_Motor_Izq_B, HIGH );
}
void Mover_Stop()
{
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
