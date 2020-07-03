#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  lcd.print("8mamo10 ^^");
  lcd.setCursor(0, 1);
  lcd.print("Let's enjoy!");
}

void loop() {
  lcd.noBlink();
  delay(3000);
  lcd.blink();
  delay(3000);

  lcd.noCursor();
  delay(500);
  lcd.cursor();
  delay(1000);

  lcd.noDisplay();
  delay(2000);
  lcd.display();
  delay(1000);
}
