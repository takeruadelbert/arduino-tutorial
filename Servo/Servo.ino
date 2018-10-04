#include <Servo.h>

Servo servo;
int pos, rotation;

void setup() {
  // put your setup code here, to run once:
  pos = 0;
  rotation = 360;
  int pin_servo = 9;
  servo.attach(pin_servo);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(pos = 0; pos < rotation; pos += 10) {
    servo.write(pos);
    delay(15);
  }

  for(pos = rotation; pos >= 1; pos -= 10) {
    servo.write(pos);
    delay(15);
  }
}
