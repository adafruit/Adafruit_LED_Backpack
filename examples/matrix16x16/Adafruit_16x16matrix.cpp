
#include "Adafruit_16x16matrix.h"



#ifndef _BV
  #define _BV(bit) (1<<(bit))
#endif

#ifndef _swap_int16_t
#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }
#endif

Adafruit_16x16matrix::Adafruit_16x16matrix(void) : Adafruit_GFX(16, 16) {
}

void Adafruit_16x16matrix::drawPixel(int16_t x, int16_t y, uint16_t color) {


   
 // check rotation, move pixel around if necessary
  switch (getRotation()) {
  case 2:
    _swap_int16_t(x, y);
    x = 16 - x - 1;
    break;
  case 3:
    x = 16 - x - 1;
    y = 16 - y - 1;
    break;
  case 0:
    _swap_int16_t(x, y);
    y = 16 - y - 1;
    break;
  }

  Adafruit_LEDBackpack &ctrl = y>7 ? b:a;
  if(y>=8) { 
    y-=8;
  }
  /*
  Serial.print("("); Serial.print(x);
  Serial.print(","); Serial.print(y);
  Serial.println(")");
  */

  if ((y < 0) || (y >= 8)) return;
  if ((x < 0) || (x >= 16)) return;

  if (color) {
    ctrl.displaybuffer[y] |= 1 << x;
  } else {
    ctrl.displaybuffer[y] &= ~(1 << x);
  }
}


  void  Adafruit_16x16matrix::begin(uint8_t addr1, uint8_t addr2) {
    a.begin(addr1);
    b.begin(addr2);
  }
  void  Adafruit_16x16matrix::setBrightness(uint8_t br) {
    a.setBrightness(br);
    b.setBrightness(br);
  }
  void  Adafruit_16x16matrix::blinkRate(uint8_t br) {
    a.blinkRate(br);
    b.blinkRate(br);
  }
  void  Adafruit_16x16matrix::writeDisplay(void) {
    a.writeDisplay();
    b.writeDisplay();
  }
  void  Adafruit_16x16matrix::clear(void) {
    a.clear();
    b.clear();
  }
