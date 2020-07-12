#include <TinyWireM.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

void setup() {
  //Serial.begin(9600);
  //Serial.println("16x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
  
  matrix.setBrightness(4);
}

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 },
  alien1_bmp[] = {
     B00011000, // This is the first frame for alien #1
B00111100, // If you squint you can kind of see the
B01111110, // image in the 0's and 1's.
B11011011,
B11111111,
B00100100,
B01011010,
B10100101, },
  alien2_bmp[] = {
    B00100100, // Second frame for alien #3
    B10100101,
    B11111111,
    B11011011,
    B11111111,
    B01111110,
    B00100100,
    B01000010 };

void loop() {
  matrix.setRotation(1);
    
  matrix.clear();
  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  
//  matrix.clear();
  matrix.drawBitmap(8, 0, frown_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(5000);
  

  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  matrix.setRotation(1);
  for (int8_t x=15; x>=-70; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Adafruit!");
    matrix.writeDisplay();
    delay(100);
  }

}
