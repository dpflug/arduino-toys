byte led = LED_BUILTIN;
byte alternate = 0;
unsigned long t;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  delay(5000);
  for (byte i=0;i<5;i++) {
    t = micros();
    if (digitalRead(led)==LOW) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
    Serial.println(micros()-t);
  }
  for (byte i=0;i<5;i++) {
    t = micros();
    if (alternate) {
      digitalWrite(led, HIGH);
      alternate = 1;
    } else {
      digitalWrite(led, LOW);
      alternate = 0;
    }
    Serial.println(micros()-t);
  }
}
