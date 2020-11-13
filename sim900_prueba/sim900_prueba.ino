#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); //Seleccionamos los pines 7 como Rx y 8 como Tx
int st = 9, led = 13,sensor=12;

void setup()
{
  pinMode(sensor,INPUT_PULLUP);
  pinMode(st, OUTPUT);
  pinMode(led, OUTPUT);
  SIM900.begin(9600);
  Serial.begin(9600);
  digitalWrite(st, 1);
  delay(1000);
  digitalWrite(st,0);
  delay(35000);
 // Serial.println((char)26); 
  digitalWrite(led,1);
}

void loop()
{
  if(digitalRead(sensor)==0){
    SIM900.print("ATD ");
    SIM900.print("71066743");
    SIM900.println(";");
    Serial.println("llamando....");
    delay(25000);
    SIM900.println("ATH");
  }
 // tester();
 // delay(10);
 //estado();
 //delay(1000);
}


void tester()
{
  if (Serial.available() > 0)
    SIM900.write(Serial.read());
  // Serial.println("AT");
  if (SIM900.available() > 0)
    Serial.write(SIM900.read());
}

void estado(){
   SIM900.write("AT\r");
  if (SIM900.available() > 0){
    Serial.write(SIM900.read());
  }
  delay(200);
}
