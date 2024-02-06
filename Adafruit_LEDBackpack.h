/*!
 * @file Adafruit_LEDBackpack.h
 *
 * Part of Adafruit's Arduino library for our I2C LED Backpacks:
 * ----> http://www.adafruit.com/products/
 * ----> http://www.adafruit.com/products/
 *
 * These displays use I2C to communicate, 2 pins are required to
 * interface. There are multiple selectable I2C addresses. For backpacks
 * with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
 * with 3 Address Select pins: 0x70 thru 0x77
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Limor Fried/Ladyada for Adafruit Industries.
 *
 * MIT license, all text above must be included in any redistribution
 */

#ifndef Adafruit_LEDBackpack_h
#define Adafruit_LEDBackpack_h

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_I2CDevice.h>

#include "Adafruit_GFX.h"

#define LED_ON 1  ///< GFX color of lit LED segments (single-color displays)
#define LED_OFF 0 ///< GFX color of unlit LED segments (single-color displays)

#define LED_RED 1    ///< GFX color for red LED segments (bi-color displays)
#define LED_YELLOW 2 ///< GFX color for yellow LED segments (bi-color displays)
#define LED_GREEN 3  ///< GFX color for green LED segments (bi-color displays)

#define HT16K33_BLINK_CMD 0x80       ///< I2C register for BLINK setting
#define HT16K33_BLINK_DISPLAYON 0x01 ///< I2C value for steady on
#define HT16K33_BLINK_OFF 0          ///< I2C value for steady off
#define HT16K33_BLINK_2HZ 1          ///< I2C value for 2 Hz blink
#define HT16K33_BLINK_1HZ 2          ///< I2C value for 1 Hz blink
#define HT16K33_BLINK_HALFHZ 3       ///< I2C value for 0.5 Hz blink

#define HT16K33_CMD_BRIGHTNESS 0xE0 ///< I2C register for BRIGHTNESS setting

#define SEVENSEG_DIGITS 5 ///< # Digits in 7-seg displays, plus NUL end

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

#define ALPHANUM_SEG_A 0b0000000000000001  ///< Alphanumeric segment A
#define ALPHANUM_SEG_B 0b0000000000000010  ///< Alphanumeric segment B
#define ALPHANUM_SEG_C 0b0000000000000100  ///< Alphanumeric segment C
#define ALPHANUM_SEG_D 0b0000000000001000  ///< Alphanumeric segment D
#define ALPHANUM_SEG_E 0b0000000000010000  ///< Alphanumeric segment E
#define ALPHANUM_SEG_F 0b0000000000100000  ///< Alphanumeric segment F
#define ALPHANUM_SEG_G1 0b0000000001000000 ///< Alphanumeric segment G1
#define ALPHANUM_SEG_G2 0b0000000010000000 ///< Alphanumeric segment G2
#define ALPHANUM_SEG_H 0b0000000100000000  ///< Alphanumeric segment H
#define ALPHANUM_SEG_J 0b0000001000000000  ///< Alphanumeric segment J
#define ALPHANUM_SEG_K 0b0000010000000000  ///< Alphanumeric segment K
#define ALPHANUM_SEG_L 0b0000100000000000  ///< Alphanumeric segment L
#define ALPHANUM_SEG_M 0b0001000000000000  ///< Alphanumeric segment M
#define ALPHANUM_SEG_N 0b0010000000000000  ///< Alphanumeric segment N
#define ALPHANUM_SEG_DP 0b0100000000000000 ///< Alphanumeric segment DP

/*!
    @brief  Class encapsulating the raw HT16K33 controller device.
*/
class Adafruit_LEDBackpack {
public:
  /*!
    @brief  Constructor for HT16K33 devices.
  */
  Adafruit_LEDBackpack(void);

  /*!
    @brief  Start I2C and initialize display state (blink off, full
            brightness).
    @param  _addr  I2C address.
    @param  theWire  TwoWire bus reference to use.
    @return  true if successful, otherwise false

  */
  bool begin(uint8_t _addr = 0x70, TwoWire *theWire = &Wire);

  /*!
    @brief  Turn display on or off
    @param  state  State: true = on, false = off
  */
  void setDisplayState(bool state);

  /*!
    @brief  Set display brightness.
    @param  b  Brightness: 0 (min) to 15 (max).
  */
  void setBrightness(uint8_t b);

  /*!
    @brief  Set display blink rate.
    @param  b  One of:
               HT16K33_BLINK_OFF       = no blinking
               HT16K33_BLINK_2HZ       = 2 Hz blink
               HT16K33_BLINK_1HZ       = 1 Hz blink
               HT16K33_BLINK_HALFHZ    = 0.5 Hz blink
  */
  void blinkRate(uint8_t b);

  /*!
    @brief  Issue buffered data in RAM to display.
  */
  void writeDisplay(void);

  /*!
    @brief  Clear display.
  */
  void clear(void);

  uint16_t displaybuffer[8]; ///< Raw display data

protected:
  Adafruit_I2CDevice *i2c_dev = NULL; ///< Pointer to I2C bus interface
};

/*!
    @brief  Class for 24-element bargraph displays.
*/
class Adafruit_24bargraph : public Adafruit_LEDBackpack {
public:
  /*!
    @brief  Constructor for 24-element bargraph displays.
  */
  Adafruit_24bargraph(void);

  /*!
    @brief  Set color a single bar (dot).
    @param  bar    Bar index (0 to 23).
    @param  color  Bar color: LED_OFF, LED_GREEN, LED_YELLOW or LED_RED.
  */
  void setBar(uint8_t bar, uint8_t color);
};

/*!
    @brief  Class for 8x16 pixel single-color matrices.
*/
class Adafruit_8x16matrix : public Adafruit_LEDBackpack, public Adafruit_GFX {
public:
  /*!
    @brief  Constructor for 8x16 pixel single-color matrices.
  */
  Adafruit_8x16matrix(void);

  /*!
    @brief  Lowest-level pixel drawing function required by Adafruit_GFX.
            Does not have an immediate effect -- must call writeDisplay()
            after any drawing operations to refresh display contents.
    @param  x      Pixel column (horizontal).
    @param  y      Pixel row (vertical).
    @param  color  Pixel color (1 = pixel on, 0 = pixel off).
  */
  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

/*!
    @brief  Class for 8x16 pixel single-color mini matrices.
*/
class Adafruit_8x16minimatrix : public Adafruit_LEDBackpack,
                                public Adafruit_GFX {
public:
  /*!
    @brief  Constructor for 8x16 pixel single-color mini matrices.
  */
  Adafruit_8x16minimatrix(void);

  /*!
    @brief  Lowest-level pixel drawing function required by Adafruit_GFX.
            Does not have an immediate effect -- must call writeDisplay()
            after any drawing operations to refresh display contents.
    @param  x      Pixel column (horizontal).
    @param  y      Pixel row (vertical).
    @param  color  Pixel color (1 = pixel on, 0 = pixel off).
  */
  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

/*!
    @brief  Class for 8x8 pixel single-color matrices.
*/
class Adafruit_8x8matrix : public Adafruit_LEDBackpack, public Adafruit_GFX {
public:
  /*!
    @brief  Constructor for 8x8 pixel single-color matrices.
  */
  Adafruit_8x8matrix(void);

  /*!
    @brief  Lowest-level pixel drawing function required by Adafruit_GFX.
            Does not have an immediate effect -- must call writeDisplay()
            after any drawing operations to refresh display contents.
    @param  x      Pixel column (horizontal).
    @param  y      Pixel row (vertical).
    @param  color  Pixel color (1 = pixel on, 0 = pixel off).
  */
  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

/*!
    @brief  Class for bi-color matrices.
*/
class Adafruit_BicolorMatrix : public Adafruit_LEDBackpack,
                               public Adafruit_GFX {
public:
  /*!
    @brief  Constructor for 8x8 pixel bi-color matrices.
  */
  Adafruit_BicolorMatrix(void);

  /*!
    @brief  Lowest-level pixel drawing function required by Adafruit_GFX.
            Does not have an immediate effect -- must call writeDisplay()
            after any drawing operations to refresh display contents.
    @param  x      Pixel column (horizontal).
    @param  y      Pixel row (vertical).
    @param  color  Pixel color (LED_OFF, LED_GREEN, LED_YELLOW or LED_RED).
  */
  void drawPixel(int16_t x, int16_t y, uint16_t color);
};

#define RAW_BITS 0 ///< Issue 7-segment data as raw bits

/*!
    @brief  Class for 7-segment numeric displays.
*/
class Adafruit_7segment : public Adafruit_LEDBackpack {
public:
  /*!
    @brief  Constructor for 7-segment numeric displays.
  */
  Adafruit_7segment(void);

  /*!
    @brief   Issue single character to display.
    @param   c Character to write (ASCII character, not numeric).
    @return  1 if character written, else 0 (non-ASCII characters).
  */
  size_t write(char c);

  /*!
    @brief   Write characters from buffer to display.
    @param   buffer Character array to write
    @param   size   Number of characters to write
    @return  Number of characters written
  */
  size_t write(const char *buffer, size_t size);

  /*!
    @brief  Print byte-size numeric value to 7-segment display.
    @param  c     Numeric value.
  */
  void print(char c);

  /*!
    @brief  Print unsigned byte-size numeric value to 7-segment display.
    @param  b     Numeric value.
    @param  base  Number base (default = RAW_BITS = raw bits)
  */
  void print(unsigned char b, int base = RAW_BITS);

  /*!
    @brief  Print integer value to 7-segment display.
    @param  n     Numeric value.
    @param  base  Number base (default = DEC = base 10)
  */
  void print(int n, int base = DEC);

  /*!
    @brief  Print unsigned integer value to 7-segment display.
    @param  n     Numeric value.
    @param  base  Number base (default = DEC = base 10)
  */
  void print(unsigned int n, int base = DEC);

  /*!
    @brief  Print long integer value to 7-segment display.
    @param  n     Numeric value.
    @param  base  Number base (default = DEC = base 10)
  */
  void print(long n, int base = DEC);

  /*!
    @brief  Print unsigned long integer value to 7-segment display.
    @param  n     Numeric value.
    @param  base  Number base (default = DEC = base 10)
  */
  void print(unsigned long n, int base = DEC);

  /*!
    @brief  Print double-precision float value to 7-segment display.
    @param  n       Numeric value.
    @param  digits  Fractional-part digits.
  */
  void print(double n, int digits = 2);

  /*!
    @brief  Print from a String object to 7-segment display.
    @param  c  String object, passed by reference.
  */
  void print(const String &c);

  /*!
    @brief  Print from a C-style string array to 7-segment display.
    @param  c  Array of characters.
  */
  void print(const char c[]);

  /*!
    @brief  Print byte-size numeric value w/newline to 7-segment display.
    @param  c     Numeric value.
  */
  void println(char c);

  /*!
    @brief  Print unsigned byte-size numeric value w/newline to 7-segment
            display.
    @param  b     Numeric value.
    @param  base  Number base (default = RAW_BITS = raw bits)
  */
  void println(unsigned char b, int base = RAW_BITS);

  /*!
    @brief  Print integer value with newline to 7-segment display.
    @param  n     Numeric value.
    @param  base  Number base (default = DEC = base 10)
  */
  void println(int n, int base = DEC);

  /*!
    @brief  Print unsigned integer value with newline to 7-segment display.
    @param  n     Numeric value.
    @param  base  Number base (default = DEC = base 10)
  */
  void println(unsigned int n, int base = DEC);

  /*!
    @brief  Print long integer value with newline to 7-segment display.
    @param  n     Numeric value.
    @param  base  Number base (default = DEC = base 10)
  */
  void println(long n, int base = DEC);

  /*!
    @brief  Print unsigned long integer value w/newline to 7-segment display.
    @param  n     Numeric value.
    @param  base  Number base (default = DEC = base 10)
  */
  void println(unsigned long n, int base = DEC);

  /*!
    @brief  Print double-precision float value to 7-segment display.
    @param  n       Numeric value.
    @param  digits  Fractional-part digits.
  */
  void println(double n, int digits = 2);

  /*!
    @brief  Print from a String object w/newline to 7-segment display.
    @param  c  String object, passed by reference.
  */
  void println(const String &c);

  /*!
    @brief  Print from a C-style string array w/newline to 7-segment display.
    @param  c  Array of characters.
  */
  void println(const char c[]);

  /*!
    @brief  Print newline to 7-segment display (rewind position to start).
  */
  void println(void);

  /*!
    @brief  Write raw segment bits into display buffer.
    @param  x        Character position (0-3).
    @param  bitmask  Segment bits.
  */
  void writeDigitRaw(uint8_t x, uint8_t bitmask);

  /*!
    @brief  Set specific digit # to a numeric value.
    @param  x    Character position.
    @param  num  Numeric (not ASCII) value.
    @param  dot  If true, light corresponding decimal.
  */
  void writeDigitNum(uint8_t x, uint8_t num, bool dot = false);

  /*!
    @brief  Set specific digit # to a character value.
    @param  x    Character position.
    @param  c    Character (ASCII).
    @param  dot  If true, light corresponding decimal.
  */
  void writeDigitAscii(uint8_t x, uint8_t c, bool dot = false);

  /*!
    @brief  Set or unset colon segment.
    @param  state  'true' to enable colon, 'false' for off.
  */
  void drawColon(bool state);

  /*!
    @brief  General integer-printing function used by some of the print()
            variants.
    @param  n     Numeric value.
    @param  base  Base (2 = binary).
  */
  void printNumber(long n, uint8_t base = 2);

  /*!
    @brief  General float-printing function used by some of the print()
            variants.
    @param  n           Numeric value.
    @param  fracDigits  Fractional-part digits.
    @param  base        Base (default DEC = base 10).
  */
  void printFloat(double n, uint8_t fracDigits = 2, uint8_t base = DEC);

  /*!
    @brief  Light display segments in an error-indicating configuration.
  */
  void printError(void);

  /*!
    @brief  Issue colon-on directly to display (bypass buffer).
  */
  void writeColon(void);

private:
  uint8_t position; ///< Current print position, 0-3
};

/*!
    @brief  Class for four-digit alphanumeric displays.
*/
class Adafruit_AlphaNum4 : public Adafruit_LEDBackpack {
public:
  /*!
    @brief  Constructor for four-digit alphanumeric displays.
  */
  Adafruit_AlphaNum4(void);

  /*!
    @brief  Write single character of alphanumeric display as raw bits
            (not a general print function).
    @param  n        Character index (0-3).
    @param  bitmask  Segment bitmask.
  */
  void writeDigitRaw(uint8_t n, uint16_t bitmask);

  /*!
    @brief  Write single ASCII character to alphanumeric display.
    @param  n      Character index (0-3).
    @param  ascii  ASCII character.
    @param  dot    If true, also light corresponding dot segment.
  */
  void writeDigitAscii(uint8_t n, uint8_t ascii, bool dot = false);
};

#endif // Adafruit_LEDBackpack_h
