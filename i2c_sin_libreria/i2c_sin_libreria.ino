#include <Wire.h>
void setup() {
 Wire.begin();
 Serial.begin(9600);
}

void loop() {
  float temp;
  
  temp = read16(0x07);
  temp *= .02;
  temp  -= 273.15;
  Serial.println(temp);

}
uint16_t read16(uint8_t a) {
//  uint16_t ret;
int ret;
  Wire.beginTransmission(0x5A); // start transmission to device 
  Wire.write(a); // sends register address to read from
  Wire.endTransmission(false); // end transmission
  
  Wire.requestFrom(0x5A, (uint8_t)3);// send data n-bytes read
  ret = Wire.read(); // receive DATA
  ret |= Wire.read() << 8; // receive DATA

 uint8_t pec = Wire.read();

  return ret;
}

