//C:\\Users\\Usuario\\AppData\\Local\\Temp\\arduino_build_959417/rectificador_trifasico.ino.hex
int valor = 0;
volatile int estado1 = 0;
volatile bool estado2 = 0;
int scr1 = 5, scr2 = 6, scr3 = 7, scr4 = 8, scr5 = 9, scr6 = 10;
void setup() {
  attachInterrupt(0, negativo, FALLING);
  pinMode(scr1, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(scr2, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(scr3, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(scr4, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(scr5, OUTPUT);       //Define D3 as output for the DIAC pulse
  pinMode(scr6, OUTPUT);       //Define D3 as output for the DIAC pulse
  digitalWrite(scr1, HIGH);
  digitalWrite(scr5, HIGH);
}

void loop() {
  //Read the value of the pot and map it from 10 to 10.000 us. AC frequency is 50Hz, so period is 20ms. We want to control the power
  //of each half period, so the maximum is 10ms or 10.000us. In my case I've maped it up to 7.200us since 10.000 was too much

  valor = 1000; //8333-10
  //In my case I've used valor = map(analogRead(A0),0,1024,7200,10); for better results
  if (estado1)
  {
    delayMicroseconds(valor); //This delay controls the power
    //T1
    digitalWrite(scr1, HIGH);
    digitalWrite(scr5, HIGH);
    delayMicroseconds(10);
    digitalWrite(scr1, LOW);
    digitalWrite(scr5, LOW);
    delayMicroseconds(2700); //This delay controls the power
    //T2
    digitalWrite(scr1, HIGH);
    digitalWrite(scr6, HIGH);
    delayMicroseconds(10);
    digitalWrite(scr1, LOW);
    digitalWrite(scr6, LOW);
    delayMicroseconds(2700); //This delay controls the power
    //T3
    digitalWrite(scr2, HIGH);
    digitalWrite(scr6, HIGH);
    delayMicroseconds(10);
    digitalWrite(scr2, LOW);
    digitalWrite(scr6, LOW);
    delayMicroseconds(2700); //This delay controls the power
    //T4
    digitalWrite(scr2, HIGH);
    digitalWrite(scr4, HIGH);
    delayMicroseconds(10);
    digitalWrite(scr2, LOW);
    digitalWrite(scr4, LOW);
    delayMicroseconds(2700); //This delay controls the power
    //T5
    digitalWrite(scr3, HIGH);
    digitalWrite(scr4, HIGH);
    delayMicroseconds(10);
    digitalWrite(scr3, LOW);
    digitalWrite(scr4, LOW);
    delayMicroseconds(2700); //This delay controls the power
    //T6
    digitalWrite(scr3, HIGH);
    digitalWrite(scr5, HIGH);
    delayMicroseconds(10);
    digitalWrite(scr3, LOW);
    digitalWrite(scr4, LOW);
    estado1 = 0;
  }
}
void negativo() {
  estado1 = 1;
}
