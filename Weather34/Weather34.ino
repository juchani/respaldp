/*
  ShiftDisplay example
  by MiguelPynto
  Simulate a weather station, showing info such as temperature and condition
  https://miguelpynto.github.io/ShiftDisplay/
*/

#include <ShiftDisplay.h>

const int LATCH_PIN = 7;
const int CLOCK_PIN = 6;
const int DATA_PIN = 5;
const int DISPLAY_TYPE = COMMON_ANODE; // COMMON_CATHODE or COMMON_ANODE
const int DISPLAY_SIZE = 8; // number of digits on display

ShiftDisplay display(LATCH_PIN, CLOCK_PIN, DATA_PIN, DISPLAY_TYPE, DISPLAY_SIZE);


void setup() {
}

void loop() {

  display.show(2, 8, 1, ALIGN_LEFT);
 // display.clear();
  display.show(3, 8, 1, ALIGN_RIGHT);
 // display.clear();
<<<<<<< HEAD
}
=======
}
>>>>>>> 941ca59634530a6110725808d796cfe22c1cd89d
