const int sw_pin = 7;
const int x_pin = A0;
const int y_pin = A1;

int sw_state = 0;
int x_pos = 0;
int y_pos = 0;

float x_convert = 0.0f;
float y_convert = 0.0f;

void setup() {
  pinMode(sw_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  sw_state = digitalRead(sw_pin);
  x_pos = analogRead(x_pin);
  y_pos = analogRead(y_pin);
  x_convert = (float)x_pos/1023.0f * 5.0f;
  y_convert = (float)y_pos/1023.0f * 5.0f;

  Serial.print("Switch: ");
  Serial.print(sw_state);
  Serial.println();

  Serial.print("X / Voltage: ");
  Serial.print(x_pos);
  Serial.print(" / ");
  Serial.print(x_convert);
  Serial.println();

  Serial.print("Y / Voltage: ");
  Serial.print(y_pos);
  Serial.print(" / ");
  Serial.print(y_convert);
  Serial.println();

  delay(500);
}
