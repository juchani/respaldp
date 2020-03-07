#include <SPI.h>
#include <SevSegSPI.h>

// create a member of SevSegSPI class
SevSegSPI display;

void setup() {
	// init display SPI
  display.init();
}

void loop() {
	// display 1234
  display.set(1, 2, 3, 4);
  display.update();
}
