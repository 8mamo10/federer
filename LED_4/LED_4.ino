const int led_R = 2;
const int led_U = 3;
const int led_L = 4;
const int led_D = 5;

void setup() {
  pinMode(led_R, OUTPUT);
  pinMode(led_U, OUTPUT);
  pinMode(led_L, OUTPUT);
  pinMode(led_D, OUTPUT);
}

void loop() {
  digitalWrite(led_R, HIGH);
  digitalWrite(led_U, HIGH);
  digitalWrite(led_L, HIGH);
  digitalWrite(led_D, HIGH);
}
