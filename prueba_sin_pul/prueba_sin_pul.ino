#include <Cronos.h>
Cronos M1(30000);
int pull1 = 9;
int pull2 = 8;
int pull3 = 7;
int pull4 = 6;
int sensor1;
int sensor2;
int sensor3;
int sensor4;
int contr;
int var;
int define_cont = 0;
int l = 1;
int tiempo;
int a;
void setup() {
  Serial.begin(9600);
  pinMode(pull1, INPUT_PULLUP);
  pinMode(pull2, INPUT_PULLUP);
  pinMode(pull3, INPUT_PULLUP);
  pinMode(pull4, INPUT_PULLUP);

}

void loop() {
  if (digitalRead(pull3)==LOW){
  sub_menu();
  }
  Serial.println("q");
}
