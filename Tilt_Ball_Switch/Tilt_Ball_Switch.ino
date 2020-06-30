int tiltPin = 2;
int ledPin = 3;

void setup() {
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int digitalVal = digitalRead(tiltPin);
  if (digitalVal == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
