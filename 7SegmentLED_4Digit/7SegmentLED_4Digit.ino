int tDelay = 1;
int rclkPin = 11;
int srclkPin = 9;
int dsPin = 12;
int dig1 = 1;
int dig2 = 2;
int dig3 = 3;
int dig4 = 4;

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

void funcShiftReg(int x) {
  digitalWrite(rclkPin, LOW);
  shiftOut(dsPin, srclkPin, LSBFIRST, seven_leds[x]);
  digitalWrite(rclkPin, HIGH);
}

void setup() {
  pinMode(rclkPin, OUTPUT);
  pinMode(dsPin, OUTPUT);
  pinMode(srclkPin, OUTPUT);
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, LOW);
  digitalWrite(dig3, LOW);
  digitalWrite(dig4, LOW);
  funcShiftReg(12);
}

void loop() {
  // dig1
  delay(tDelay);
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
  funcShiftReg(1);
  delay(tDelay);
  // dig2
  delay(tDelay);
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, LOW);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
  funcShiftReg(2);
  delay(tDelay);
  // dig3
  delay(tDelay);
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, LOW);
  digitalWrite(dig4, HIGH);
  funcShiftReg(3);
  delay(tDelay);
  // dig4
  delay(tDelay);
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, LOW);
  funcShiftReg(4);
  delay(tDelay);
}
