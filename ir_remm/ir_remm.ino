#include "IRremote.h"
int receiver = 11;

IRrecv ir(receiver);
decode_results results;
void setup() {
  Serial.begin(9600);
  ir.enableIRIn();
  pinMode(13, OUTPUT);
}

void loop() {
if (ir.decode(&results)){
  if(results.value==0x4EEB1123){
  digitalWrite(13,HIGH);  
  }
  if(results.value==0xA89B7436){
    digitalWrite(13,LOW);
  }
}
}
