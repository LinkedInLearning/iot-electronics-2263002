void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(6, 127);
  delay(1000);
  analogWrite(6, 255);
  delay(1000);
}
