int dato=0;// introducimos la variable dato
int limite=250;//introducimos la variable limite
int buzzer=5;//introducimos la variable buzzer
void setup() {
 Serial.begin(9600);//configuramos comunicacion serial a 9600 bits
pinMode(buzzer,OUTPUT);//establecemos el pin d5 como salida para el buzzer
}

void loop() {
dato=analogRead(A4);//cargamos los datos del pin A4 a la variable dato
Serial.println(dato);
if (dato>limite){ // si dato es mayor a limite entonces:
  digitalWrite(buzzer,HIGH);// activamos el buzzer
  delay(500);
  digitalWrite(buzzer,LOW);// activamos el buzzer
  delay(500);
}
else{  // de lo contrario:
  digitalWrite(buzzer,LOW);//apagamos el buzzer
}
delay(500); //esperamos medio segundo
}
