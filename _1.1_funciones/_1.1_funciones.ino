int led1=8,led2=9;// declaramos variables 
void setup() {
pinMode(led1,OUTPUT);//declaramos led1 como salida 
pinMode(led2,OUTPUT);// declaramos led2 como salida
}
void loop() {
intermitencia(led1,500); //llamamos a la funcion y asignamos a la variable pin= led1 y tiempo =500 ms
intermitencia(led2,1000);//llamamos a la funcion y asignamos a la variable pin= led2 y tiempo =1000 ms
}                     


     
//la cual tendra 2 variables internas pin y tiempo
void intermitencia(int pin,int tiempo){
digitalWrite(pin,HIGH);//encendemos pin
  delay(tiempo);//esperamos el tiempo asignado
digitalWrite(pin,LOW);//apagamos pin
delay(tiempo);//esperamos el tiempo asignado
}

