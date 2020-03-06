int led[]={2,3,4,5};
int pull=8,contador=5;
boolean estado=0;
void setup() {
pinMode(led[0],OUTPUT);
pinMode(led[1],OUTPUT);
pinMode(led[2],OUTPUT);
pinMode(led[3],OUTPUT);

 pinMode(pull,INPUT);
 
 }

void loop() {
estado=digitalRead(pull);
if(estado==HIGH){
  if (estado<4){
digitalWrite(led[contador],HIGH);
  }
contador++;
  
  delay(500);
}


if (contador>4){
  
digitalWrite(led[0],LOW);
digitalWrite(led[1],LOW);
digitalWrite(led[2],LOW);
digitalWrite(led[3],LOW);
contador=0;  
}

}
