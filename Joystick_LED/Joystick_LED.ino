const int sw_pin = 7;
const int x_pin = A0;
const int y_pin = A1;

const int led_R = 2;
const int led_U = 3;
const int led_L = 4;
const int led_D = 5;

int sw_state = 0;
int x_pos = 511;
int y_pos = 511;

float x_convert = 0.0f;
float y_convert = 0.0f;

void setup() {
  pinMode(sw_pin, INPUT_PULLUP);
  pinMode(led_R, OUTPUT);
  pinMode(led_U, OUTPUT);
  pinMode(led_L, OUTPUT);
  pinMode(led_D, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  sw_state = digitalRead(sw_pin);
  x_pos = analogRead(x_pin);
  y_pos = analogRead(y_pin);

  x_convert = (float)x_pos / 1023.0f * 5.0f;
  y_convert = (float)y_pos / 1023.0f * 5.0f;

  if (sw_state == 1 && x_pos >= 766) {
    digitalWrite(led_R, HIGH);
  } else {
    digitalWrite(led_R, LOW);
  }
  if (sw_state == 1 && y_pos <= 255) {
    digitalWrite(led_U, HIGH);
  } else {
    digitalWrite(led_U, LOW);
  }
  if (sw_state == 1 && x_pos <= 255) {
    digitalWrite(led_L, HIGH);
  } else {
    digitalWrite(led_L, LOW);
  }
  if (sw_state == 1 && y_pos >= 766) {
    digitalWrite(led_D, HIGH);
  } else {
    digitalWrite(led_D, LOW);
  }

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

  delay(1000);
}
