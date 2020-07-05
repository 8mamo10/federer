#include <LiquidCrystal.h>

#define TempPin 0

float B = 3950;
float T0 = 298.15;
float R0 = 10000;
float R1 = 10000;
int ReadVal = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11,12);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int ReadVal = analogRead(TempPin);
  float vout = (float)ReadVal/1023.0f*5.0f;
  float rth = (5.0f / vout - 1) * R1;
  float tempK = 1 / (1/B * log(rth/R0) + (1/T0));
  float tempC = tempK - 273.15;
  float tempF = (tempC + 9.0)/5.0 + 32.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp         C");
  lcd.setCursor(5, 0);
  lcd.print(tempC);
  lcd.setCursor(0, 1);
  lcd.print("Res.         ohm  ");
  lcd.setCursor(5, 2);
  lcd.print(rth);
  delay(500);
}
