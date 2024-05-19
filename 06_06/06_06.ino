#include "Adafruit_seesaw.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

Adafruit_seesaw ss;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  if (!ss.begin(0x36)) {
    Serial.println("ERROR! seesaw not found");
    while (1);
  } else {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }
}

void loop() {
  float tempC = ss.getTemp();
  uint16_t capread = ss.touchRead(0);

  Serial.print("Temperature: "); Serial.print(tempC); Serial.println("*C");
  Serial.print("Capacitive: "); Serial.println(capread);

  lcd.setCursor(0, 0);
  char str[50];
  sprintf(str, "Temp: %d.%02d *C  ", (int)tempC, (int)(tempC * 100) % 100);
  lcd.println(str);

  lcd.setCursor(0, 1);
  sprintf(str, "Cap :  %04d       ", (int)capread);
  lcd.println(str);

  delay(1000);
}
