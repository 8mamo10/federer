#include <DHT.h>
#include <LiquidCrystal.h>

#define DHT_Pin 2
#define DHT_Type DHT11

DHT dht(DHT_Pin, DHT_Type);

float humidity = 0.0f;
float tempC = 0.0f;
float tempF = 0.0f;
float discomfortIndex = 0.0f;
float isFahrenheit = true;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  delay(2000);

  humidity = dht.readHumidity();
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(isFahrenheit);

  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Read failure");
    return;
  }

  discomfortIndex = 0.81f*tempC+0.01f*humidity*(0.99f*tempC-14.3f)+46.3f;

  lcd.setCursor(0, 0);
  lcd.print("Temp.         C");
  lcd.setCursor(8, 0);
  lcd.print(tempC);

  lcd.setCursor(0, 1);
  lcd.print("Humid.        %");
  lcd.setCursor(8, 2);
  lcd.print(humidity);

  delay(2500);

  lcd.setCursor(0, 1);
  lcd.print("Discom.         ");
  lcd.setCursor(8, 2);
  lcd.print(discomfortIndex);
  delay(500);
}
