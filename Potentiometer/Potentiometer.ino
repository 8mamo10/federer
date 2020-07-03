int analogPin = 3;
int val = 0;
float v_convert = 0.0f;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);
  v_convert = (float)val / 1023.0f * 5.0f;

  Serial.print("value / volt: ");
  Serial.print(val);
  Serial.print(" / ");
  Serial.println(v_convert);

  delay(2000);
}
