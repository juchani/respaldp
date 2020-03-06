int tiempo=100;
int pin[]={8,9,10,11,12,13};
int contador=0;
void setup() {
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT); //define el pin 13 como salida
Serial.begin(9600);
}

void loop() {
Serial.println(contador);
digitalWrite(pin[contador],HIGH);
delay(tiempo);
digitalWrite(pin[contador],LOW);
delay(tiempo);
contador=contador+1;
if(contador==6){
  contador=0;
}

}
