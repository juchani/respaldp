#include <Wire.h>

void setup() {
  Wire.begin();

}

void loop() {
 int c; 
 dac(4000);
c=c+1;

}

void dac(int voltaje) {
  Wire.beginTransmission(0x60);
  Wire.write(0x60);
  Wire.write(voltaje / 16);                 // Upper data bits          (D11.D10.D9.D8.D7.D6.D5.D4)
  Wire.write((voltaje % 16) << 4);// Lower data bits          (D3.D2.D1.D0.x.x.x.x)
  Wire.endTransmission();
}
