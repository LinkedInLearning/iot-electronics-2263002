import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

color off = color(4, 79, 111);
color on = color(84, 145, 158);

void setup() {
  size(470, 140);

  // Prints out the available serial ports.
  println(Arduino.list());
  
  // Modify this line, by changing the "0" to the index of the serial
  // port corresponding to your Arduino board (as it appears in the list
  // printed by the line above).
  arduino = new Arduino(this, Arduino.list()[3], 57600);
  
  // Alternatively, use the name of the serial port corresponding to your
  // Arduino (in double-quotes), as in the following line.
  //arduino = new Arduino(this, "/dev/tty.usbmodem621", 57600);
  
  arduino.pinMode(9, Arduino.OUTPUT);
}

void draw() {
  background(off);
  stroke(on);
  
  int photo = arduino.analogRead(0);
  println(photo);
  
  if (photo < 400) {
    arduino.digitalWrite(9, Arduino.HIGH);
    fill(on);
  } else if (photo > 600) {
    arduino.digitalWrite(9, Arduino.LOW);
    fill(off);
  }

  ellipse(225, 70, photo / 16, photo / 16);
}
