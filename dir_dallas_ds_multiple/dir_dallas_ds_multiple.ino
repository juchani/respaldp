#include <OneWire.h>
OneWire ourWire(2);


void setup(void) {
  Serial.begin(9600);

}

void loop(void) {
byte addr[8];
Serial.println ("obteniendo direcciones:"); 
while(ourWire.search(addr)){
  Serial.print("dir= ");
  for(int i =0;i<8;i++){
    Serial.print(" 0x");
    Serial.print(addr[i],HEX);
}
Serial.println();
}
Serial.println();
ourWire.reset_search();
delay(2000);
}
