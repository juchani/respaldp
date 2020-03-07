#ifndef SEVSEGSPI_H
#define SEVSEGSPI_H

#include "Arduino.h"
#include <SPI.h>

#define SEVSEG_CS 8
#define SEVSEG_FRAMEPERIOD 2000

class SevSegSPI {
  public:
    SevSegSPI(void);
    void init();
    void init(uint8_t _CS_PIN);
    void set(uint8_t POSITION, uint8_t VALUE);
    void set(uint8_t SEG_FIRST, uint8_t SEG_SECOND, uint8_t SEG_THIRD, uint8_t SEG_FOURTH);
    uint8_t get(uint8_t POSITION);
    void update();
    void off();
  private:
    uint8_t digits[12] = {
    	0x02, // 0
    	0xBB, // 1
    	0x85, // 2
    	0x91, // 3
    	0xB8, // 4
    	0xD0, // 5
    	0xC0, // 6
    	0x9B, // 7
    	0x80, // 8
    	0x90, // 9
    	0xF7, // _ // KEY 10
    	0xFF  // EMPTY // KEY 11
    };

    uint8_t positions[4]= {0xC7, 0xCB, 0xD3, 0xE3};
    uint8_t display[4] = {11, 11, 11, 11};
    uint8_t display_position = 0;

    uint8_t CS_PIN = SEVSEG_CS;

    unsigned long UPDATE_TIMER;
};

#endif

