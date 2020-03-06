#include <Encoder.h>

Encoder myEnc(2, 3);


long oldPosition  = -999;
boolean isButtonPressed = false;
long lastUpdateMillis = 0;

void handleKey() {
  isButtonPressed = true;  
}

void setup() {
  Serial.begin(115200);
  Serial.println("Basic Encoder Test:");
   pinMode(3, INPUT_PULLUP);
   attachInterrupt(3, handleKey, RISING);
}


void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }
  // software debounce
 /* if (isButtonPressed & amp;& amp; millis() - lastUpdateMillis &gt; 50) {
    isButtonPressed = false;
    lastUpdateMillis = millis();
    // Reset the counter
    myEnc.write(0);
  }*/
}
