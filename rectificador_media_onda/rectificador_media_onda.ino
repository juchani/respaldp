//C:\\Users\\Usuario\\AppData\\Local\\Temp\\arduino_build_431789/rectificador_media_onda.ino.hex
int valor = 0;
volatile bool estado1 = 0;
volatile bool estado2 = 0;
int dt=30;
void setup() {
  attachInterrupt(0, negativo, RISING);
  attachInterrupt(1, positivo, FALLING);
  pinMode(10, OUTPUT);       //Define D10 como salida 
  pinMode(11, OUTPUT);       //Define D11 como salida
  pinMode(12, OUTPUT);       //Define D12 como salida
  pinMode(13, OUTPUT);       //Define D13 como salida
  Serial.begin(9600);
}

void loop() {
  valor =map(dt,0,100,8333,10);
  if (estado1)
  {
    Serial.println("CRUZE");
    delayMicroseconds(valor); //This delay controls the power
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    delay(1);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    
    
    
    estado1 = 0;
  }
  if (estado2)
  {
    Serial.println("CRUZE");
    delayMicroseconds(valor);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    delay(1);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    estado2 = 0;
  }

}
void negativo() {
  estado1 = 1;
}

void positivo() {
  estado2 = 1;
}
