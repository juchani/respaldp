#include <Wire.h> // 
byte x = 0; 
void setup()   {    
  Wire.begin(); } // 
  void loop() {  
    Wire.beginTransmission(4); // transmit to device #4   
    Wire.write("x is "); // sends five bytes  
    Wire.write(x); // sends one byte    
    
 Wire.endTransmission(); // stop transmitting
 x++;   
 delay(500); } 

