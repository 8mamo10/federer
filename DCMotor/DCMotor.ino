const int ENABLE = 7;
const int CH1 = 5;
const int CH2 = 3;

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  Serial.begin(9600);

  Serial.println("1:Normal rotaion");
  Serial.println("2:Reverse rotation");
  Serial.println("4:PWM Low speed");
  Serial.println("5:PWM Middle speed");
  Serial.println("6:PWM High speed");
  Serial.println("0:STOP");

  digitalWrite(ENABLE, LOW);
  delay(500);
}

void loop() {
  if (Serial.available() > 0) {
    char val = Serial.read();
    if (val == '1') {
      Serial.println("1:Normal rotaion");
      digitalWrite(ENABLE, HIGH);
      digitalWrite(CH1, HIGH);
      digitalWrite(CH2, LOW);
    } else if (val == '2') {
      Serial.println("2:Reverse rotation");
      digitalWrite(ENABLE, HIGH);
      digitalWrite(CH1, LOW);
      digitalWrite(CH2, HIGH);
    } else if (val == '4') {
      Serial.println("4:PWM Low speed");
      digitalWrite(ENABLE, HIGH);
      analogWrite(CH1,255);
      delay(100);
      analogWrite(CH1, 127);
      digitalWrite(CH2, LOW);
    } else if (val == '5') {
      Serial.println("5:PWM Middle speed");
      digitalWrite(ENABLE, HIGH);
      analogWrite(CH1, 255);
      delay(100);
      analogWrite(CH1, 181);
      digitalWrite(CH2, LOW);
    } else if (val == '6') {
      Serial.println("6:PWM High speed");
      digitalWrite(ENABLE, HIGH);
      analogWrite(CH1, 255);
      digitalWrite(CH2, LOW);
    } else if (val == '0') {
      Serial.println("0:STOP");
      digitalWrite(ENABLE, LOW);
    }
  }
}
