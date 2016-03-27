#include <Servo.h> 
 
Servo servo;

const int PIN_BUTTON = 6;
const int PIN_BUTTON_2 = 7;
const int PIN_SERVO = 5;

#define MIN_WIDTH 1000
#define MAX_WIDTH 2000

int pos = 1500;

void setup() {
    servo.attach(PIN_SERVO);
    servo.writeMicroseconds(pos);
    pinMode(PIN_BUTTON, INPUT_PULLUP);
    pinMode(PIN_BUTTON_2, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(PIN_BUTTON) == LOW) {
    pos = pos + 10;

    if (pos > MAX_WIDTH) {
       pos = MAX_WIDTH; 
    }

    servo.writeMicroseconds(pos);
  }

  if (digitalRead(PIN_BUTTON_2) == LOW) {
    pos = pos - 10;

    if (pos > MIN_WIDTH) {
       pos = MIN_WIDTH; 
    }

    servo.writeMicroseconds(pos);
  }
  
  delay(20);
}
