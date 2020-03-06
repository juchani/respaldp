int listas[]={6,5,9,13,2};
int contador=0;
void setup() {
  pinMode(listas[0],OUTPUT);
 pinMode(listas[1],OUTPUT);
  pinMode(listas[2],OUTPUT);
}

void loop() {
  digitalWrite(listas[contador],1);
  delay(500);
  digitalWrite(listas[contador],0);
  delay(500);
  contador++;
  if(contador>4){
    contador=0;
  }
  
}
