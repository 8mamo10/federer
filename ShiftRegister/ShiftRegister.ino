int tDelay = 200;
int rclkPin = 11;
int srclkPin = 9;
int dsPin = 12;

//byte leds = 0;
byte leds = B00000000;

void setup() {
  pinMode(rclkPin, OUTPUT);
  pinMode(srclkPin, OUTPUT);
  pinMode(dsPin, OUTPUT);
}

void loop() {
  leds = 0;
  digitalWrite(rclkPin, LOW);
  shiftOut(dsPin, srclkPin, LSBFIRST, leds);
  digitalWrite(rclkPin, HIGH);

  delay(tDelay);

  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    //bitSet(leds, i+1);
    digitalWrite(rclkPin, LOW);
    shiftOut(dsPin, srclkPin, LSBFIRST, leds);
    //shiftOut(dsPin, srclkPin, MSBFIRST, leds);
    digitalWrite(rclkPin, HIGH);

    delay(tDelay);

    //bitClear(leds, i);
  }
}
