int led=12;
int boton=10;
int estado;
int contador=0;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(boton,INPUT);
}

void loop() {
  while(contador<10){
    estado=digitalRead(boton);
if(estado==HIGH){
  contador++;
  delay(250);
}}
    digitalWrite(led,HIGH);
    
    
    }




    
