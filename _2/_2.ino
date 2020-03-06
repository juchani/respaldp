int led[]={23,8,9,10,32};
int contador =0;
int cnt;
int boton=7;
void setup() {
  pinMode(boton,INPUT);
  pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
      pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() {
int sensor=digitalRead(boton);
Serial.print ("el valor del contador es: ");
Serial.println(contador); 
if (sensor==HIGH){
  contador++;
}
delay(250);



}
