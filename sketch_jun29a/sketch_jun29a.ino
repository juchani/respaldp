int valor;
void setup() {
Serial.begin(9600);
pinMode(3,OUTPUT);
}

void loop() {
valor =analogRead(A0);//700
valor=map(valor,0,1023,0,255);
Serial.println(valor);
analogWrite(3,valor);
delay(100);
}
