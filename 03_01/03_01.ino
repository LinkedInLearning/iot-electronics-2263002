void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  int button = digitalRead(2);
  digitalWrite(LED_BUILTIN, button);
}
