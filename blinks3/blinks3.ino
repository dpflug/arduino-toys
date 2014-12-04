const byte LED=LED_BUILTIN;
unsigned int pat[254];
byte pat_end=255;
byte pat_cursor=0;
unsigned long next_flash=0;
byte led_state=LOW;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Ready for pattern:");}

void loop() {
  if (Serial.available()) {
    unsigned int counter=0;
    do {
      pat[counter]=Serial.parseInt();
      counter++;
    } while (Serial.available());
    pat_end = counter-1;
    set_next_flash(pat[0]);
    Serial.print("Setting pattern to: ");
    for (byte i=0;i<=pat_end;i++) {
      Serial.print(pat[i]);
      if (i<pat_end) {
	Serial.print(", ");
      }
      else {
	Serial.println("");
      }
    }
  }
  blink_pat(pat);
}

void blink_pat(unsigned int pat []) {
  if (pat_end!=255) { // While we have a pattern
    unsigned long t = millis();
    if ((long)(t-next_flash)>=0) {
      blink();
      set_next_flash(pat[pat_cursor]);
      if (pat_cursor==pat_end) {
	pat_cursor=0;
      } else {
	pat_cursor++;
      }
    }
  }
}

unsigned long set_next_flash(unsigned long offset) {
  unsigned long t=millis();
  // Interrupt the current pattern if need be
  unsigned long base=((long)(t-next_flash)>=0) ? next_flash : t;
  next_flash=base+offset;
  return next_flash;
}

byte blink() {
  if (led_state) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
  led_state=~led_state;
  return led_state;
}