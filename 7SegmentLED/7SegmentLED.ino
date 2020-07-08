int tDelay = 500;
int rclkPin = 11;
int srclkPin = 9;
int dsPin = 12;

byte seven_leds[12] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11100110, // 9
  B00000001, // D.P
  B00000000, // OFF
};

void setup() {
  pinMode(rclkPin, OUTPUT);
  pinMode(dsPin, OUTPUT);
  pinMode(srclkPin, OUTPUT);
}

void loop() {
  digitalWrite(rclkPin, LOW);
  shiftOut(dsPin, srclkPin, LSBFIRST, seven_leds[11]);
  digitalWrite(rclkPin, HIGH);

  delay(tDelay);

  for (int i = 0; i < 11; i++) {
    digitalWrite(rclkPin, LOW);
    shiftOut(dsPin, srclkPin, LSBFIRST, seven_leds[i]);
    digitalWrite(rclkPin, HIGH);

    delay(tDelay);
  }
}
