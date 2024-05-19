#include <Wire.h>

void setup() {
  Wire.begin(0x08);
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

void requestEvent() {
  int photo = analogRead(A0);
  
  if (photo < 400) {
    Wire.write('N');
    Wire.write('C');
    Wire.write('H');
    Wire.write('T');
  } else if (photo < 600) {
    Wire.write('D');
    Wire.write('N');
    Wire.write('K');
    Wire.write('L');
  } else {
    Wire.write('h');
    Wire.write('e');
    Wire.write('l');
    Wire.write('l');
  }
}
