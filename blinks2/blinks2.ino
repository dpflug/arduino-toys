const byte led = LED_BUILTIN;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  flash(2000);
}

void flash(int len) {
  digitalWrite(led, HIGH);
  delay(len/2);
  digitalWrite(led, LOW);
  delay(len/2);
}