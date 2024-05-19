int prev = LOW;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int button = digitalRead(2);
  digitalWrite(LED_BUILTIN, button);
  if (prev != button) {
    Serial.println(button);
    prev = button;
  }
  delay(20);
}
