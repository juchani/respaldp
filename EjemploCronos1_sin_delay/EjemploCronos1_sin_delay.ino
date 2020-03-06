#include <Cronos.h>

Cronos M1(1000);
int led1 = 10;
int led2 = 11;
int boton1 = 9;
int boton2 = 8;
int cont1 = 9;
int cont2 = 7;
int estado;
int estado1;
int tiempo = 7;
int tiempo1 = 5;
bool l;
bool l2;
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
}

void loop() {
  if (M1.Estado()) {
    if (l == true) {
      cont1 = cont1 + 1;
    }
    if (l2 == true) {
      cont2 = cont2 + 1;
    }
  }
  estado = digitalRead(boton1);
  estado1 = digitalRead(boton2);
  if (estado == HIGH) {
    l = 1;
    cont1 = 0;
  }
  if (estado1 == HIGH) {
    l2 = 1;
    cont2 = 0;
  }

  if (cont1 < tiempo) {
    digitalWrite(led1, HIGH);
  }
  if (cont2 < tiempo1) {
    digitalWrite(led2, HIGH);
  }
  if (cont1 > tiempo) {
    digitalWrite(led1, LOW);
  }
  if (cont2 > tiempo1) {
    digitalWrite(led2, LOW);
  }
}

