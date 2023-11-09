// This example shows how to use the alphanumeric segment names in an animation.
//
// Author: Jonny Bergdahl (github@bergdahl.org)
//
#include <Arduino.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();
// Defines the animation. For segment names, 
// see https://learn.adafruit.com/14-segment-alpha-numeric-led-featherwing/usage
uint16_t animation[] { 0, ALPHANUM_SEG_A, 
                       1, ALPHANUM_SEG_H, 
                       1, ALPHANUM_SEG_N, 
                       2, ALPHANUM_SEG_L, 
                       2, ALPHANUM_SEG_K, 
                       3, ALPHANUM_SEG_A, 
                       3, ALPHANUM_SEG_B, 
                       3, ALPHANUM_SEG_C, 
                       3, ALPHANUM_SEG_D, 
                       2, ALPHANUM_SEG_N,
                       2, ALPHANUM_SEG_H, 
                       1, ALPHANUM_SEG_K,
                       1, ALPHANUM_SEG_L, 
                       0, ALPHANUM_SEG_D,
                       0, ALPHANUM_SEG_E,
                       0, ALPHANUM_SEG_F };

void setup() {
  Serial.begin(9600);  
  alpha4.begin(0x70);  // pass in the address
}

void loop() {
  // For each step of the animation, write the value to the given digit
  for (int j = 0; j < sizeof(animation)/2; j = j + 2)
  {
    alpha4.clear();
    alpha4.writeDigitRaw(animation[j], animation[j+1]);
    alpha4.writeDisplay();
    delay(200);
  }
}