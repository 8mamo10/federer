int buzzer = 12;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  unsigned char i;
  while (1) {
    for (i = 0; i < 100; i++) {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
    }
    for (i = 0; i < 100; i++) {
      digitalWrite(buzzer, HIGH);
      delay(2);
      digitalWrite(buzzer, LOW);
      delay(2);
    }
    for (i = 0; i < 100; i++) {
      digitalWrite(buzzer, HIGH);
      delay(4);
      digitalWrite(buzzer, LOW);
      delay(4);
    }
    for (i = 0; i < 100; i++) {
      digitalWrite(buzzer, HIGH);
      delay(8);
      digitalWrite(buzzer, LOW);
      delay(8);
    }
  }
}
