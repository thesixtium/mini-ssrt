#include <Servo.h>
#include <math.h>

Servo servo1;
Servo servo2;
double servo1_position = 135;
double servo2_position = 135;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
}

void loop() {
  for(int i = 90; i < 180; i ++){
    servo1.write(i);
    servo2.write(i);
    delay(100);
  }

  for(int i = 90; i < 180; i ++){
    servo1.write(i);
    servo2.write(270-i);
    delay(10);
  }

  for(int i = 90; i < 180; i ++){
    servo1.write(270-i);
    servo2.write(i);
    delay(100);
  }

  for(int i = 90; i < 180; i ++){
    servo1.write(270-i);
    servo2.write(270-i);
    delay(100);
  }
}

void move_arm(double servo1_change, double servo2_change){
  move_servo1(servo1_change);
  move_servo2(servo2_change);
}

void move_servo1(double servo1_change){
  // 90 < Range < 180
  if(servo1_change < 0 && servo1_position > 90){
    servo1_position += servo1_change;
  } else if (servo1_change > 0 && servo1_position < 180) {
    servo1_position += servo1_change;
  }

  servo1.write(servo1_position);
}
void move_servo2(double servo2_change){
  // 90 < Range < 180
  if(servo2_change < 0 && servo2_position > 90){
    servo2_position += servo2_change;
  } else if (servo2_change > 0 && servo2_position < 180) {
    servo2_position += servo2_change;
  }

  servo2.write(servo2_position);
}
