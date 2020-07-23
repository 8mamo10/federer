#include <IRremote.h>
#include <Stepper.h>

const int REV_PIN = 12;

const int MOTOR_STEPS = 2048;

Stepper myStepper(MOTOR_STEPS, 8, 10, 9, 11);

IRrecv irrecv(REV_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn();
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch (results.value) {
      case 0xFF906F:
        myStepper.step(512);
        delay(1000);
        break;
      case 0xFFE01F:
        myStepper.step(-512);
        delay(1000);
        break;
    }
    irrecv.resume();

    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
