
const int PIN_B = 11;
const int PIN_P = 10;
const int PIN_Y = 9;
const int PIN_O = 8;

void setup() {
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_P, OUTPUT);
  pinMode(PIN_Y, OUTPUT);
  pinMode(PIN_O, OUTPUT);
}

void loop() {
  int wait_time = 100;
  digitalWrite(PIN_B, 1);
  digitalWrite(PIN_P, 0);
  digitalWrite(PIN_Y, 0);
  digitalWrite(PIN_O, 1);
  delay(wait_time);

  digitalWrite(PIN_B, 1);
  digitalWrite(PIN_P, 1);
  digitalWrite(PIN_Y, 0);
  digitalWrite(PIN_O, 0);
  delay(wait_time);

  digitalWrite(PIN_B, 0);
  digitalWrite(PIN_P, 1);
  digitalWrite(PIN_Y, 1);
  digitalWrite(PIN_O, 0);
  delay(wait_time);

  digitalWrite(PIN_B, 0);
  digitalWrite(PIN_P, 0);
  digitalWrite(PIN_Y, 1);
  digitalWrite(PIN_O, 1);
  delay(wait_time);
}
