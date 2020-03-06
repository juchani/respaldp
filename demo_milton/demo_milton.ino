/*laboratorio de electronica digital II*/
int limite = 0;
int contador =0;
int tiempo;
int distancia;
void setup() //estamento de configuraciones
{
pinMode(13, OUTPUT); //con la funcion pinMode definimos la salida digital 13 como salida
pinMode(10, OUTPUT);
limite--;
digitalWrite(13, 1);
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
}
void loop() // estamento de bucle
{
  digitalWrite(6, LOW);
  delayMicroseconds(2);
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  tiempo = pulseIn(7, HIGH);


  distancia = tiempo / 58;

//limite =analogRead (A0);
limite=distancia ;//map(limite,0,500,0,99);
if (contador>limite){
contador=0;
digitalWrite(13, 1);
//delay (1);
}
while (contador<limite ){
digitalWrite(13, 0);
digitalWrite(10, 1); // con la funcion digitalWrite enviamos un 1 logico (5v) a la salida 10 de la placa
// delay(5); // con la funcion delay hacemos que genere un retardo de 1 segundo en toda la placa
digitalWrite(10, 0); // con la misma funcion enviamos un 0 logico a la salida 10 de la placa
// delay(5);
contador++;}}




