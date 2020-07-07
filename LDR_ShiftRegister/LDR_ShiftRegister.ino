int cds_out = 0;
int rclkPin = 11;
int srclkPin = 9;
int dsPin = 12;
byte leds = B00000000;

void funcShiftReg(byte x) {
  digitalWrite(rclkPin, LOW);
  shiftOut(dsPin, srclkPin, LSBFIRST, x);
  digitalWrite(rclkPin, HIGH);
}

void setup() {
  pinMode(rclkPin, OUTPUT);
  pinMode(srclkPin, OUTPUT);
  pinMode(dsPin, OUTPUT);
  funcShiftReg(leds);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(cds_out);
  int set_led = val / (1023 / 9);

  Serial.println(val);
  Serial.println(set_led);

  if (set_led > 8) {
    set_led = 8;
  }

  leds = B00000000;

  for (int i = 0; i < set_led; i++) {
    leds = leds + (B00000001 << i);
  }
  funcShiftReg(leds);
}
