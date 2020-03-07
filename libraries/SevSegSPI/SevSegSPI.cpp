#include "SevSegSPI.h"

SevSegSPI::SevSegSPI(void) {}

void SevSegSPI::init() {
  SPI.begin();
  pinMode(CS_PIN, OUTPUT);
}

void SevSegSPI::init(uint8_t _CS_PIN) {
  SPI.begin();

  CS_PIN = _CS_PIN;
  pinMode(CS_PIN, OUTPUT);
}

void SevSegSPI::set(uint8_t POSITION, uint8_t VALUE) {
  display[POSITION] = VALUE;
}

void SevSegSPI::set(uint8_t SEG_FIRST, uint8_t SEG_SECOND, uint8_t SEG_THIRD, uint8_t SEG_FOURTH) {
  display[0] = SEG_FIRST;
  display[1] = SEG_SECOND;
  display[2] = SEG_THIRD;
  display[3] = SEG_FOURTH;
}

uint8_t SevSegSPI::get(uint8_t POSITION) {
  return display[POSITION];
}

void SevSegSPI::off() {
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(0xFF);
  SPI.transfer(0x00);
  digitalWrite(CS_PIN, HIGH);
}

void SevSegSPI::update() {
  if(micros() - UPDATE_TIMER < SEVSEG_FRAMEPERIOD) return;
  UPDATE_TIMER = micros();

  digitalWrite(CS_PIN, LOW);
  SPI.transfer(digits[display[display_position]]);
  SPI.transfer(positions[display_position]);
  digitalWrite(CS_PIN, HIGH);

  display_position++;
  if(display_position == 4) {
    display_position = 0;
  }
}

