int val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(0);

  // analog 0-1023 -> digital 0-255
  Serial.println(val/4);
  analogWrite(3, val/4);
  delay(500);
}
