#include <Wire.h>
int bot[] = {2, 3, 4, 5, 6, 7};
int sensor = 9;
int dato=0;
int dato1=0;
int dato2=0;
void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode( bot[0] , INPUT_PULLUP );
  pinMode( bot[1] , INPUT_PULLUP );
  pinMode( bot[2] , INPUT_PULLUP );
  pinMode( bot[3] , INPUT_PULLUP );
  pinMode( bot[4] , INPUT_PULLUP );
  pinMode( bot[5] , INPUT_PULLUP );
  pinMode(sensor, INPUT_PULLUP);
}
void loop() {
  Wire.beginTransmission(4);
  int b1  = digitalRead ( bot[0] );
  int b2  = digitalRead ( bot[1] );
  int b3  = digitalRead ( bot[2] );
  int b4  = digitalRead ( bot[3] );
  int b5  = digitalRead ( bot[4] );
  int b6 = digitalRead ( bot[5] );
  int sen=digitalRead(sensor);
  Serial.println(b1);
  if (b1  == LOW  ) {
    dato=1;

  }
  if ( b2 == LOW  ) {
    Wire.write(2);
dato=2;
  }
  if (b3  == LOW  ) {
    Wire.write(3);
dato=3;
  }
  if ( b4 == LOW  ) {
    Wire.write(4);
dato1=4;
  }
  if (b5 == LOW  ) {
    Wire.write(5);
dato1=5;
  }
  if ( b6 == LOW  ) {
    
dato1=6;
  }
    if ( sen == LOW  ) {
    
dato2=0;
  }
  Wire.write(dato);
  delay(2000);
  Wire.write(0);
  delay(100);
  Wire.write(dato1);
  delay(1000);
  Wire.write(0);
  Wire.endTransmission();
  delay(500);
}//loop
