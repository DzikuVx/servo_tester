#include <Servo.h> 
 
Servo servo;

const int PIN_BUTTON = 6;
const int PIN_SERVO = 5;

int pos = 1500;

int prevButtonState = HIGH;
int currentButtonState = HIGH;

void setup() {
    servo.attach(PIN_SERVO);
    servo.writeMicroseconds(pos);
    pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
  
  currentButtonState = digitalRead(PIN_BUTTON);
  
  if (currentButtonState == LOW && prevButtonState == HIGH) {
    pos = pos + 500;
    
    if (pos > 2000) {
       pos = 1000; 
    }
    
    servo.writeMicroseconds(pos);
  }
  
  prevButtonState = currentButtonState;
  
  delay(100);
}
