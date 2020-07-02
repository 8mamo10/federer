#include <DHT.h>

#define DHT_Pin 8
#define DHT_Type DHT11

DHT dht(DHT_Pin, DHT_Type);

float humidity = 0.0f;
float tempC = 0.0f;
float tempF = 0.0f;
float discomfortIndex = 0.0f;
bool isFahrenheit = true;

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11");
  dht.begin();
}

void loop() {
  delay(2000);
  humidity = dht.readHumidity();
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(isFahrenheit);
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Read failure!");
    return;
  }
  discomfortIndex = 0.81f * tempC + 0.01f * humidity * (0.99f * tempC - 14.3f) + 46.3f;
  Serial.print("湿度: ");
  Serial.print(humidity);
  Serial.print(", 温度: ");
  Serial.print(tempC);
  Serial.print("[℃]");
  Serial.print(", 華氏: ");
  Serial.print(tempF);
  Serial.print("[F]");
  Serial.print(", 不快指数: ");
  Serial.println(discomfortIndex);
}
