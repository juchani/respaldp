void setup() {
  pinMode(13,OUTPUT);   //inicia el pin 13 como salida  
}

  

 



void loop() {
digitalWrite(13,HIGH); //Manda un pulso de 5v al pin 13
delay(2000);  // pausa 2 segundos 
digitalWrite(13,LOW);  //Manda un pulso de 0v al pin 13
delay(2000); // pausa 2 segundos 
}
