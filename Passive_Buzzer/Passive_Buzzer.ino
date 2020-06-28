#include <pitches.h>

//int duration = 200;
int duration = 100;
int pin = 8;
int melody[] = {
 NOTE_C5,  0, NOTE_D5,  0, NOTE_E5,  0, NOTE_F5,  0, NOTE_E5,  0, NOTE_D5,  0, NOTE_C5,  0,  0,  0,
 NOTE_E5,  0, NOTE_F5,  0, NOTE_G5,  0, NOTE_A5,  0, NOTE_G5,  0, NOTE_F5,  0, NOTE_E5,  0,  0,  0,
 NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0,
 NOTE_C5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_E5,  0, NOTE_D5,  0, NOTE_C5,  0,  0,  0 };

void setup() {
}

void loop() {
  tone(pin, 262, duration);
  delay(duration);
  tone(pin, 294, duration);
  delay(duration);
  tone(pin, 330, duration);
  delay(duration);
  tone(pin, 349, duration);
  delay(duration);
  tone(pin, 392, duration);
  delay(duration);
  tone(pin, 440, duration);
  delay(duration);
  tone(pin, 494, duration);
  delay(duration);
  tone(pin, 523, duration);
  delay(3000);

  for (int i = 0; i < 64; i++) {
    tone(pin, melody[i], duration);
    delay(duration);
  }
}
