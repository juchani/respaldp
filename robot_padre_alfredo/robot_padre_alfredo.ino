int Pin_Motor_Der_A = 9;
int Pin_Motor_Der_B = 10;
int Pin_Motor_Izq_A = 11;
int Pin_Motor_Izq_B = 12;
int M1_A = 2, M1_B = 3, M2_A = 4, M2_B = 5, M3_A = 6, M3_B = 7, M4_A = 8, M4_B = A0;
int tiempo = 0;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
  pinMode(M1_A, OUTPUT);
  pinMode(M1_B, OUTPUT);
  pinMode(M2_A, OUTPUT);
  pinMode(M2_B, OUTPUT);
  pinMode(M3_A, OUTPUT);
  pinMode(M3_B, OUTPUT);
  pinMode(M4_A, OUTPUT);
  pinMode(M4_B, OUTPUT);
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
    else if (dato == 'f') {
      digitalWrite(M1_A, HIGH);
      delay(500);
      digitalWrite(M1_A, LOW);
      delay(200);
    }
    else if (dato == 'g') {
      digitalWrite(M1_B, HIGH);
      delay(500);
      digitalWrite(M1_B, LOW);
      delay(200);
    }
    else if (dato == 'h') {
      digitalWrite(M2_A, HIGH);
      delay(500);
      digitalWrite(M2_A, LOW);
      delay(200);
    }
    else if (dato == 'j') {
      digitalWrite(M2_B, HIGH);
      delay(500);
      digitalWrite(M2_B, LOW);
      delay(200);
    }
    else if (dato == 'k') {
      digitalWrite(M3_A, HIGH);
      delay(500);
      digitalWrite(M3_A, LOW);
      delay(200);
    }
    else if (dato == 'l') {
      digitalWrite(M3_B, HIGH);
      delay(500);
      digitalWrite(M3_B, LOW);
      delay(200);
    }

    else if (dato == 'm') {
      digitalWrite(M4_A, HIGH);
      delay(500);
      digitalWrite(M4_A, LOW);
      delay(200);
    }
    else if (dato == 'n') {
      digitalWrite(M4_B, HIGH);
      delay(500);
      digitalWrite(M4_B, LOW);
      delay(200);
    }

  }

  if (tiempo < 100) // 1000   cilcos de 1ms
  {
    tiempo = tiempo + 1;
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
  digitalWrite (Pin_Motor_Der_A, LOW );
  digitalWrite (Pin_Motor_Der_B, HIGH );
  digitalWrite (Pin_Motor_Izq_A, LOW );
  digitalWrite (Pin_Motor_Izq_B, HIGH );
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

