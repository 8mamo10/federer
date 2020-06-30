#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(9);
}

void loop() {
  myservo.write(90);
  delay(2000);
  myservo.write(20);
  delay(2000);
  myservo.write(160);
  delay(2000);
}
