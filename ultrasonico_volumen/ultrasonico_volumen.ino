#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>
#define buzzer 7
#define relay 12
LiquidCrystal_PCF8574 lcd(0x27);


int pinecho = 9;
int pintrigger = 10;
int  led = 2;
float tiempo, distancia;

void setup() {
int error;
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer,OUTPUT);
pinMode(relay,OUTPUT);
lcd.begin(16, 2); 
lcd.setBacklight(255);
}

void loop() {
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = (tiempo / 29) / 2;

  // ENVIAR EL RESULTADO AL MONITOR SERIAL

  if(distancia<10){
    digitalWrite(led,HIGH);
    digitalWrite(relay,HIGH);
    digitalWrite(buzzer,HIGH);
delay(1000);
digitalWrite(relay,LOW);
digitalWrite(buzzer,LOW);
delay(500);
    digitalWrite(led,LOW);
     lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("GRACIAS");
    delay(2000);
  }
  else{
    digitalWrite(led,LOW);
   

  }
  Serial.print(distancia);
  Serial.println(" cm ");
  lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("ACERQUE");
    lcd.setCursor(5, 1);
    lcd.print("SU MANO");
delay(400);


}
