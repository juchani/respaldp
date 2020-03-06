// --------------------------------------
// i2c_scanner
//
//

#include <SoftWire.h>

SoftWire SWire(PB6, PB7, SOFT_FAST);


void setup() {
  Serial.begin(115200);
  SWire.begin();
  Serial.println("\nSoftware I2C.. Scanner");
}


void loop() {
  float temp;
  
  temp = read16(0x07);
  temp = temp*.02;
  temp  = temp-273.15;
  Serial.println(temp);
  delay(100);
}

uint16_t read16(uint8_t a) {
  uint16_t ret;

  SWire.beginTransmission(0x5A); // start transmission to device 
  SWire.write(a); // sends register address to read from
  SWire.endTransmission(false); // end transmission
  
  SWire.requestFrom(0x5A, (uint8_t)3);// send data n-bytes read
  ret = SWire.read(); // receive DATA
  ret |= SWire.read() << 8; // receive DATA

 uint8_t pec = SWire.read();

  return ret;
}

