#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();


String data="";
uint8_t emoji[]={0,0,0,0,0,0,0,0};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
matrix.begin(0x70);  // pass in the address
print_emoji(emoji,"green");
}

void loop() {

  if (Serial.available()>0)
  {
    data=Serial.readStringUntil('\n');
    Serial.println(data);
  
  }
  
  if (data!="")
  {
    
    emoji[0]=(val(data.substring(1,9)));
    //Serial.println(val(data.substring(1,9)));
    emoji[1]=(val(data.substring(11,19)));
    //Serial.println(val(data.substring(11,19)));
    emoji[2]=(val(data.substring(21,29)));
    //Serial.println(val(data.substring(21,29)));
    emoji[3]=(val(data.substring(31,39)));
    //Serial.println(val(data.substring(31,39)));
    emoji[4]=(val(data.substring(41,49)));
    //Serial.println(val(data.substring(41,49)));
    emoji[5]=(val(data.substring(51,59)));
    //Serial.println(val(data.substring(51,59)));
    emoji[6]=(val(data.substring(61,69)));
    //Serial.println(val(data.substring(61,69)));
    emoji[7]=(val(data.substring(71,79)));
   //Serial.println(val(data.substring(71,79)));    
    data="";
    print_emoji(emoji,"green");
  }
}

int val(String str)
{
  int v=0;
  for (int i=0;i<8;i++)
  {
    if (str[i]=='1')
    {
        v=v+power(2,(7-i));
    }
  }
  return v;
}

int power(int base,int exponent)
{
  int c=1;
  for (int i=0;i<exponent;i++)
  {
    c=c*base;
  }
  return c;
}

void print_emoji( uint8_t emoji[],String color)
{
  matrix.clear();
  if (color=="red")
  {
    matrix.drawBitmap(0, 0,emoji, 8, 8, LED_RED); 
  }
  else
  {
    matrix.drawBitmap(0, 0,emoji, 8, 8, LED_GREEN);
  }
  matrix.writeDisplay();
  delay(500);
}
