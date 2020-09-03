int Pin_Motor_Der_A = 9;
int Pin_Motor_Der_B = 10;
int Pin_Motor_Izq_A = 11;
int Pin_Motor_Izq_B = 12;
int t=1000;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
pinMode(13,OUTPUT);
}

void loop() {

  if (Serial.available()) {
    char dato = Serial.read();
    if (dato == 'a')
    {
      digitalWrite(13,HIGH);
      delay(300);
      digitalWrite(13,LOW);
      delay(300);
      Mover_Adelante();
      delay(t);
      Stop();

    }
    else if (dato == 'r')
    {
      Mover_Retroceso();
      delay(t);
      Stop();
    }
    else if (dato == 'd')
    {
      Mover_Derecha();
      delay(t);
      Stop();
    }
    else if (dato == 'i')
    {
      Mover_Izquierda();
      delay(t);
      Stop();
    }

  }






}

void Mover_Adelante()
{
  Stop();
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void Mover_Retroceso()
{
  Stop();
  digitalWrite (Pin_Motor_Der_A, LOW );
  digitalWrite (Pin_Motor_Der_B, HIGH );
  digitalWrite (Pin_Motor_Izq_A, LOW );
  digitalWrite (Pin_Motor_Izq_B, HIGH );
}
void Mover_Derecha()
{
  Stop();
  digitalWrite (Pin_Motor_Der_A, LOW );
  digitalWrite (Pin_Motor_Der_B, HIGH );
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void Mover_Izquierda()
{
  Stop();
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW );
  digitalWrite (Pin_Motor_Izq_B, HIGH );
}
void Stop()
{

  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
delay(1000);
}
