#include "DistanciaUltrasonidos.h"
#include <LiquidCrystal.h>
#include <Cronos.h>
LiquidCrystal lcd(44, 42, 40, 38, 36, 34);
Cronos M1(100);
const int TriggerPin = 53;
const int EchoPin = 52;
DistanciaUltrasonidos sensorUltrasonidos(TriggerPin, EchoPin);
int distancia;
int motor1 = 37;
int motor2 = 41;
int tanque_1 = 9;
int tanque_2 = 10;
int tanque_3 = 11;
int valor1 ;
int valor2 ;
int valor3 ;
int valor4 ;
int grifo = 39;
int boton_1 = 2;
int boton_2 = 3;
int boton_3 = 21;
//int valvula[3] = { 47, 49, 51};
int total[] = {37, 39, 41, 43, 45, 47, 49, 51};
int rep;
int estado1 ;
int estado2 ;
int estado3 ;
int contador ;
int ml1=20000;
int ml2=45000;
int ml3=60000;
//variables para el sensor de flujo
void apagado_total() {
  digitalWrite(total[0], 1);
  digitalWrite(total[1], 1);
  digitalWrite(total[2], 1);
  digitalWrite(total[3], 1);
  digitalWrite(total[4], 1);
  digitalWrite(total[5], 1);
  digitalWrite(total[6], 1);
  digitalWrite(total[7], 1);

}
void antiruido() {
  lcd.begin(20, 4);
}


void apagado_valvulas() {
  digitalWrite(47, 1);
  digitalWrite(49, 1);
  digitalWrite(51, 1);
}
void setup() {
  pinMode (motor1, OUTPUT);
  pinMode (47, OUTPUT);
  pinMode (49, OUTPUT);
  pinMode (51, OUTPUT);
  pinMode (motor2, OUTPUT);
  pinMode(tanque_1, INPUT);
  pinMode(tanque_2, INPUT);
  pinMode(tanque_3, INPUT);
  pinMode(boton_1, INPUT);
  pinMode(boton_2, INPUT);
  pinMode(boton_3, INPUT);
  pinMode(grifo, OUTPUT);
  apagado_valvulas();
  apagado_total();
  lcd.begin(20, 4);
  lcd.setCursor(3, 0);
  lcd.print ("PROYECTO U.E.B. ");
  lcd.setCursor(6, 1);
  lcd.print ("SIPES 6 ");
  lcd.setCursor(4, 2);
  lcd.print ("DOSIFICADORA");
  lcd.setCursor(1, 3);
  lcd.print("DE AGUA PURIFICADA   ");
  delay (5000);
}



void loop() {
  lcd.clear();
  distancia = sensorUltrasonidos.obtenerDistancia();
  valor1 = ! digitalRead(tanque_1);
  valor2 = ! digitalRead(tanque_2);
  valor3 = ! digitalRead(tanque_3);
  estado1 = digitalRead(boton_1);
  estado2 = digitalRead(boton_2);
  estado3 = digitalRead(boton_3);
  int promedio = valor1 + valor2 + valor3;
  antiruido();
  lcd.setCursor (0, 0);
  lcd.print ("fulltank disponibles ");
  lcd.setCursor (5, 1);
  lcd.print (promedio);

 /* if (promedio != rep) {
    apagado_valvulas();
    delay(100);
  }*/
  //digitalWrite(valvula[promedio], 0);
  if (M1.Estado()) {
    if (distancia > 9) {
      digitalWrite(motor1, 0);

    }
    else {
      digitalWrite(motor1, 1);
    }
  }
  if(promedio==3){
    apagado_valvulas();
  digitalWrite(47,0);
  }
  if(promedio==2){
    apagado_valvulas();
    
  digitalWrite(47,0);
  }
  if(promedio==1){
    apagado_valvulas();
    
  digitalWrite(49,0);
  }
  if(promedio==0){
    apagado_valvulas();
    
  digitalWrite(51,0);
  }
  
  if (estado1 == HIGH) {
    antiruido();
    lcd.setCursor (5, 2);
    lcd.print ("500 ml ");
    lcd.setCursor (5, 3);
    lcd.print ("dispensando");
    digitalWrite(grifo, 0);
    delay(2500);
    digitalWrite(motor2, 0);
    delay(ml1);
  }
  if (estado2 == HIGH) {
    antiruido();
    lcd.setCursor (0, 0);
    lcd.print ("fulltank disponibles ");
    lcd.setCursor (5, 1);
    lcd.print (promedio);
    lcd.setCursor (5, 2);
    lcd.print ("1000 ml ");
    lcd.setCursor (5, 3);
    lcd.print ("dispensando");
    digitalWrite(grifo, 0);
    delay(2500);
    digitalWrite(motor2, 0);
    delay(ml2);
  }
  if (estado3 == HIGH) {
    antiruido();
    lcd.setCursor (0, 0);
    lcd.print ("fulltank disponibles ");
    lcd.setCursor (5, 1);
    lcd.print (promedio);
    lcd.setCursor (5, 2);
    lcd.print ("2000 ml ");
    lcd.setCursor (5, 3);
    lcd.print ("dispensando");
    digitalWrite(grifo, 0);
    delay(2500);
    digitalWrite(motor2, 0);
    delay(ml3);
  }
    
    digitalWrite(motor2, 1);
  delay(250);
}

