#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {  
  alpha4.begin(0x70);
}

void loop() {
  int photo = analogRead(A0);

  int ascii0 = '0' + photo / 1000 % 10;
  int ascii1 = '0' + photo / 100 % 10; 
  int ascii2 = '0' + photo / 10 % 10;
  int ascii3 = '0' + photo / 1 % 10;
    
  alpha4.writeDigitAscii(0, ascii0);
  alpha4.writeDigitAscii(1, ascii1); 
  alpha4.writeDigitAscii(2, ascii2);
  alpha4.writeDigitAscii(3, ascii3);
 
  alpha4.writeDisplay();
  delay(200);
}
