#include <LiquidCrystal.h>

#define TrigPin 2
#define EchoPin 3

float ProDelay = 0;
float Distance = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  ProDelay = pulseIn(EchoPin, HIGH);

  if (ProDelay > 0) {
    lcd.clear();
    Distance = 340*ProDelay/2/10000;

    lcd.setCursor(0, 0);
    lcd.print("Dis.");
    lcd.setCursor(6, 0);
    lcd.print(Distance);
    lcd.setCursor(14, 0);
    lcd.print("cm");
  }
  delay(1000);
}
