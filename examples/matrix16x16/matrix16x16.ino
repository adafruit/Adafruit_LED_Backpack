/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit 16x8 LED Matrix backpacks 
  ----> http://www.adafruit.com/products/2035
  ----> http://www.adafruit.com/products/2036
  ----> http://www.adafruit.com/products/2037
  ----> http://www.adafruit.com/products/2038
  ----> http://www.adafruit.com/products/2039
  ----> http://www.adafruit.com/products/2040
  ----> http://www.adafruit.com/products/2041
  ----> http://www.adafruit.com/products/2042
  ----> http://www.adafruit.com/products/2043
  ----> http://www.adafruit.com/products/2044
  ----> http://www.adafruit.com/products/2052

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>

#include "Adafruit_16x16matrix.h"
Adafruit_16x16matrix matrix = Adafruit_16x16matrix();

void setup() {
  Serial.begin(9600);
  Serial.println("16x16 LED Matrix Test");
  
  matrix.begin(0x70, 0x71);  // pass in the address
  matrix.setBrightness(15);
}


void loop() {

   matrix.clear();
  matrix.fillRect(0,0, 16,16, LED_ON);
  
  matrix.writeDisplay();  // write the changes we just made to the display
  
  delay(500);

matrix.clear();
  matrix.drawLine(0,0, 15,15, LED_ON);
  
  matrix.writeDisplay();  // write the changes we just made to the display
  

  delay(500);
  

  matrix.setTextSize(2);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=0; x>=-64; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Hello");
    matrix.writeDisplay();
    delay(100);
  }
}
