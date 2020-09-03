#include <TinyWireM.h>
int c;
void setup() {
  TinyWireM.begin();

}

void loop() {
  dac(c);
  for (c = 0; c < 4095; c++)
  {
    dac(c);
  }
  for (c = 4095; c > 0; c--)
  {
    dac(c);
  }
}

void dac(int voltaje) {
  TinyWireM.beginTransmission(0x 60);
  TinyWireM.write(0x60);
  TinyWireM.write(voltaje / 16);                 // Upper data bits          (D11.D10.D9.D8.D7.D6.D5.D4)
  TinyWireM.write((voltaje % 16) << 4);// Lower data bits          (D3.D2.D1.D0.x.x.x.x)
  TinyWireM.endTransmission();
}
