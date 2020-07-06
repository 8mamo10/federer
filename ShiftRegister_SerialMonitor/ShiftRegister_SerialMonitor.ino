int tDelay = 200;
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
  pinMode(dsPin, OUTPUT);
  pinMode(srclkPin, OUTPUT);
  funcShiftReg(leds);
  Serial.begin(9600);
  Serial.println("Enter LED Number 0 to 7 or 'y' all on 'x' all off.");
}

void loop() {
  if (Serial.available() > 0) {
    char val = Serial.read();
    if (val >= '1' && val <= '8') {
      int led = val - '1';
      bitSet(leds, led);
      funcShiftReg(leds);
      Serial.print("Turned on LED.");
      led = val - '0';
      Serial.println(led, DEC);
    } else if (val == 'y') {
      leds = B11111111;
      funcShiftReg(leds);
      Serial.println("Turned on all LEDS.");
    } else if (val == 'x') {
      leds = B00000000;
      funcShiftReg(leds);
      Serial.println("Turned off all LEDS."); 
    }
  }
}
