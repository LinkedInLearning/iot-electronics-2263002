#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {  
  alpha4.begin(0x70);
}

void loop() {
  Wire.requestFrom(0x08, 4);
  
  int ascii0 = Wire.read();
  int ascii1 = Wire.read();
  int ascii2 = Wire.read();
  int ascii3 = Wire.read();
    
  alpha4.writeDigitAscii(0, ascii0);
  alpha4.writeDigitAscii(1, ascii1); 
  alpha4.writeDigitAscii(2, ascii2);
  alpha4.writeDigitAscii(3, ascii3);
 
  alpha4.writeDisplay();
  delay(200);
}
