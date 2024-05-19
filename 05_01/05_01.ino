void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogWrite(6, 127);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pwm = analogRead(A0);
  pwm = map(pwm, 0, 1023, 0, 500);
  Serial.println(pwm);
}
