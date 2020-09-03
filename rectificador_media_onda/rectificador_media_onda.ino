int valor = 0;
volatile bool estado1 = 0;
volatile bool estado2 = 0;
int dt=50;
void setup() {
  attachInterrupt(0, negativo, RISING);
  attachInterrupt(1, positivo, FALLING);
  pinMode(10, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(11, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(12, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(9, OUTPUT);       //Define D3 as output for the DIAC pulse
  Serial.begin(9600);
}

void loop() {
  //Read the value of the pot and map it from 10 to 10.000 us. AC frequency is 50Hz, so period is 20ms. We want to control the power
  //of each half period, so the maximum is 10ms or 10.000us. In my case I've maped it up to 7.200us since 10.000 was too much

  valor =map(dt,0,100,8333,10);
  //In my case I've used valor = map(analogRead(A0),0,1024,7200,10); for better results
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
    delayMicroseconds(valor); //This delay controls the power
    digitalWrite(12, HIGH);
    digitalWrite(9, HIGH);
    delay(1);
    digitalWrite(12, LOW);
    digitalWrite(9, LOW);
    estado2 = 0;
  }

}
void negativo() {
  estado1 = 1;
}

void positivo() {
  estado2 = 1;
}
