// https://lastminuteengineers.com/l293d-motor-driver-shield-arduino-tutorial/
#include "ArmServo.h"
#include "DriverMotor.h"

DriverMotor front_right(4);
DriverMotor front_left(1);
DriverMotor back_right(3);
DriverMotor back_left(2);

ArmServo arm_height(9);
ArmServo arm_angle(10);

int inByte;

void setup() {
  Serial1.begin(9600);
}

void loop() {
  /* Serial protocol
   * Byte 0: Begin transmission with a <
   * Byte 1: Specify actuator type
   *     M - Motor
   *     S - Servo
   * Motor:
   *     Byte 2: Specify Motor, Polarity, and Type
   *         0  -  Front Left   Forward    Set Speed
   *         1  -  Front Left   Forward    Change Speed
   *         2  -  Front Left   Backwards  Set Speed
   *         3  -  Front Left   Backwards  Change Speed
   *         4  -  Back Left    Forward    Set Speed
   *         5  -  Back Left    Forward    Change Speed
   *         6  -  Back Left    Backwards  Set Speed
   *         7  -  Back Left    Backwards  Change Speed
   *         8  -  Back Right   Forwards   Set Speed
   *         9  -  Back Right   Forwards   Change Speed
   *         10 -  Back Right   Backwards  Set Speed
   *         11 -  Back Right   Backwards  Change Speed
   *         12 -  Front Right  Forwards   Set Speed
   *         13 -  Front Right  Forwards   Change Speed
   *         14 -  Front Right  Backwards  Set Speed
   *         15 -  Front Right  Backwards  Change Speed
   *     Byte 3: Specify speed from 0 to 255
   * Servo:
   *     Byte 2: Specifcy Servo and Type
   *         0  -  Arm Angle      Set Angle
   *         1  -  Arm Angle      Change Angle
   *         2  -  Arm Height     Set Angle
   *         3  -  Arm Height     Change Angle
   *         4  -  Arm Rotation   Set Angle
   *         5  -  Arm Rotation   Change Angle
   *     Byte 3: Specify angle from 0 to 90
   * Byte 4: End transmission with a >
   */
  if (Serial1.available()) {
    inByte = Serial1.read();
    if(inByte == 42){
      
    }
  
  }
}
