#include <SoftwareSerial.h>
// software serial #1: RX = digital pin 10, TX = digital pin 11
SoftwareSerial bt(2, 3);

int x,y;
void setup() {
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
x=analogRead(A6);
y=analogRead(A7);
x=map(x,0,1024,0,3);
y=map(y,0,1024,0,3);
Serial.print(analogRead(A6));
Serial.print("  ");
Serial.print(y);
Serial.print("  ");
 Serial.print(analogRead(A7));
Serial.print("  ");
Serial.println(x);
if(y==0){
bt.print("d");
  }
  if(y==2){
bt.print("i");
  }
  if(x==0){
bt.print("a");
  }
  if(x==2){
bt.print("r");
  }
}

