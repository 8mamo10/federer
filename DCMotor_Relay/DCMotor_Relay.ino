const int ENABLE = 7;
const int CH1 = 5;
const int CH2 = 3;

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  Serial.begin(9600);

  Serial.println("1: SW ON");
  Serial.println("2: SW OFF");
  Serial.println("0: Forced STOP");

  digitalWrite(ENABLE, LOW);
  delay(500);
}

void loop() {
  if (Serial.available() > 0) {
    char val = Serial.read();
    if (val == '1') {
      Serial.println("1: SW ON");
      digitalWrite(ENABLE, HIGH);
      digitalWrite(CH1, HIGH);
      digitalWrite(CH2, LOW);
    } else if (val == '2') {
      Serial.println("2: SW OFF");
      digitalWrite(ENABLE, HIGH);
      digitalWrite(CH1, LOW);
      digitalWrite(CH2, LOW);
    } else if (val == '0') {
      Serial.println("0: Forced STOP");
      digitalWrite(ENABLE, LOW);
    }
  }
}
