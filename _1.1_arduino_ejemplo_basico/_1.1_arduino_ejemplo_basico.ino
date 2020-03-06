int led1=8,led2=9;//declaramos pines 8 y 9
void setup() {
pinMode(led1,OUTPUT);//declaramos los pin como salida digital (OUTPUT)
pinMode(led2,OUTPUT);
}

void loop() {
digitalWrite(led1,HIGH);//encendemos el primer led(HIGH)
delay(500);//esperamos medio segundo
digitalWrite(led1,LOW);//apagamos el primer led (LOW)
delay(500);//esperamos medio segundo
digitalWrite(led2,HIGH);//encendemos el segundo led 
delay(500);//esperamos medio segundo
digitalWrite(led2,LOW);//encendemos el segundo led
delay(500);//esperamos medio segundo
}
