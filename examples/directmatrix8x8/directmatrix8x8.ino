/*************************************************** 
    This is a library to address LED matrices that requires
    constant column/row rescans.

    It uses code from the Adafruit I2C LED backpack library designed for
    ----> http://www.adafruit.com/products/881
    ----> http://www.adafruit.com/products/880
    ----> http://www.adafruit.com/products/879
    ----> http://www.adafruit.com/products/878

    Adafruit invests time and resources providing this open source code, 
    please support Adafruit and open-source hardware by purchasing 
    products from Adafruit!

    Original code written by Limor Fried/Ladyada for Adafruit Industries.  
    BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "TimerOne.h"

// These go to ground:
uint8_t _gnd_lines[] = { 5, 6, 7, 8, 12, 11, 10, 9 };
// Those go to V+
// A6 and A7 do NOT work as digital pins on Arduino Nano
uint8_t _redcolumns[] = { A0, A1, A2, A3, A4, A5, 4, 0 };

PWMDirectMatrix *matrix;

void setup() {
#ifndef __AVR_ATtiny85__
    // Initializing serial breaks one row (shared pin)
    //Serial.begin(57600);
    //Serial.println("DirectMatrix Test");
#endif
    matrix = new PWMDirectMatrix(8, 8);
    matrix->begin(_gnd_lines, _redcolumns);

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
        B00111100 };


void loop() {

    matrix->clear();
    matrix->drawBitmap(0, 0, smile_bmp, 8, 8, LED_HIGH);
    matrix->writeDisplay();
    delay(1000);

    matrix->clear();
    matrix->drawBitmap(0, 0, neutral_bmp, 8, 8, LED_MEDIUM);
    matrix->writeDisplay();
    delay(1000);

    matrix->clear();
    matrix->drawBitmap(0, 0, frown_bmp, 8, 8, LED_VERYLOW);
    matrix->writeDisplay();
    delay(1000);

    matrix->clear();
    matrix->drawLine(0,0, 7,7, LED_MEDIUM);
    matrix->writeDisplay();  // write the changes we just made to the display
    delay(500);

    matrix->clear();
    matrix->drawRect(0,0, 8,8, LED_VERYLOW);
    matrix->fillRect(2,2, 4,4, LED_HIGH);
    matrix->writeDisplay();  // write the changes we just made to the display
    delay(2000);

    matrix->clear();
    matrix->drawCircle(3,3, 3, LED_MEDIUM);
    matrix->writeDisplay();  // write the changes we just made to the display
    delay(500);

    matrix->setTextWrap(false);  // we don't want text to wrap so it scrolls nicely
    matrix->setTextSize(1);
    matrix->setTextColor(LED_MEDIUM);
    matrix->setRotation(1);
    for (int8_t x=7; x>=-36; x--) {
        matrix->clear();
        matrix->setCursor(x,0);
        matrix->print("Hello");
        matrix->writeDisplay();
	delay(50);
    }
    delay(100);
    matrix->setRotation(2);
    matrix->setTextColor(LED_HIGH);
    for (int8_t x=7; x>=-36; x--) {
        matrix->clear();
        matrix->setCursor(x,0);
        matrix->print("World");
        matrix->writeDisplay();
	delay(50);
    }
    matrix->setRotation(0);
}
