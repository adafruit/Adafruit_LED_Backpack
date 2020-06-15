


#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"


class Adafruit_16x16matrix : public Adafruit_GFX {
 public:
  Adafruit_16x16matrix(void);

  void begin(uint8_t addr1, uint8_t addr2);
  void drawPixel(int16_t x, int16_t y, uint16_t color);
  
  void setBrightness(uint8_t b);
  void blinkRate(uint8_t b);
  void writeDisplay(void);
  void clear(void);

private:
  Adafruit_LEDBackpack a,b;
};
