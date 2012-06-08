#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();

uint8_t counter = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("HT16K33 test");
  
  matrix.begin(0x74);  // pass in the address
}

void loop() {
  // paint one LED per row. The HT16K33 internal memory looks like
  // a 8x16 bit matrix (8 rows, 16 columns)
  for (uint8_t i=0; i<8; i++) {
    // draw a diagonal row of pixels
    matrix.displaybuffer[i] = _BV((counter+i) % 16) | _BV((counter+i+8) % 16)  ;
  }
  // write the changes we just made to the display
  matrix.writeDisplay();
  delay(100);

  counter++;
  if (counter >= 16) counter = 0;  
}

