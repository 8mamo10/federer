#define TrigPin 10
#define EchoPin 11

float ProDelay = 0;
float Distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(10);

  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  ProDelay = pulseIn(EchoPin, HIGH);
  if (ProDelay > 0) {
    Distance = 340 * ProDelay / 2 / 10000;
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println(" cm");
  }
  delay(1000);
}
