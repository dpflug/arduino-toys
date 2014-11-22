const byte led = LED_BUILTIN;
const int pattern [] = { 300, 50, 150, 50, 150, 100, 200, 200, 200, 500, 300, 100, 300, 2000 };
const byte pattern_size = sizeof(pattern)/sizeof(pattern[0]);

void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blink_pat(pattern, pattern_size);
  for(int x=0;x<5;x++) {
    breathe();
    delay(500);
  }
  delay(200);
  for(int x=0;x<5;x++) {
    breathe();
    delay(250);
  }
}

void blink_pat(const int pat [], const int t_size) {
  for (int x=0; x<t_size; x++) {
    if (digitalRead(led) == HIGH) {
      digitalWrite(led, LOW);
    } else {
      digitalWrite(led, HIGH);
    }
    delay(pat[x]);
  }
}

void breathe() {
  for(int i=0;i<=255;i++){
    analogWrite(led, i);
    delay(1);
  }
  for(int i=255;i>=0;i--){
    analogWrite(led, i);
    delay(2);
  }
}
