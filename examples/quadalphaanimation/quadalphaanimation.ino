// This example shows how to use the alphanumeric segment names in an animation.
//
// Author: Jonny Bergdahl (github@bergdahl.org)
//
#include <Arduino.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

/*
Segment names for 14-segment alphanumeric displays.
See https://learn.adafruit.com/14-segment-alpha-numeric-led-featherwing/usage

    -------A-------
    |\     |     /|
    | \    J    / |
    |   H  |  K   |
    F    \ | /    B
    |     \|/     |
    |--G1--|--G2--|
    |     /|\     |
    E    / | \    C
    |   L  |   N  |
    | /    M    \ |
    |/     |     \|
    -------D-------  DP
*/

uint16_t animation[] { 0, ALPHANUM_SEG_A | ALPHANUM_SEG_D, 
                       1, ALPHANUM_SEG_H | ALPHANUM_SEG_L, 
                       1, ALPHANUM_SEG_N | ALPHANUM_SEG_K, 
                       2, ALPHANUM_SEG_L | ALPHANUM_SEG_H, 
                       2, ALPHANUM_SEG_K | ALPHANUM_SEG_N, 
                       3, ALPHANUM_SEG_A | ALPHANUM_SEG_D, 
                       3, ALPHANUM_SEG_B | ALPHANUM_SEG_C, 
                       3, ALPHANUM_SEG_C | ALPHANUM_SEG_B, 
                       3, ALPHANUM_SEG_D | ALPHANUM_SEG_A, 
                       2, ALPHANUM_SEG_N | ALPHANUM_SEG_K,
                       2, ALPHANUM_SEG_H | ALPHANUM_SEG_L, 
                       1, ALPHANUM_SEG_K | ALPHANUM_SEG_N,
                       1, ALPHANUM_SEG_L | ALPHANUM_SEG_H, 
                       0, ALPHANUM_SEG_D | ALPHANUM_SEG_A,
                       0, ALPHANUM_SEG_E | ALPHANUM_SEG_F,
                       0, ALPHANUM_SEG_F | ALPHANUM_SEG_E };

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