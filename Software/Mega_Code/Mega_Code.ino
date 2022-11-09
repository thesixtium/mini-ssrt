// https://lastminuteengineers.com/l293d-motor-driver-shield-arduino-tutorial/
#include "ArmServo.h"
#include "DriverMotor.h"

#define COMMUNICATION Serial
#define SERVOS 0

DriverMotor front_right(4);
DriverMotor front_left(1);
DriverMotor back_right(3);
DriverMotor back_left(2);

#IF SERVOS == 1
ArmServo arm_height(9);
ArmServo arm_angle(10);
ArmServo arm_rotation(40);
#ENDIF

int inByte;
int inPackage[3];

void setup() {
  COMMUNICATION.begin(9600);
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
   *         16 -  All Wheels   Forward    Set Speed
   *         17 -  All Wheels   Forward    Change Speed
   *         18 -  All Wheels   Backwards  Set Speed
   *         19 -  All Wheels   Backwards  Change Speed
   *         20 -  All Wheels   Left       Set Speed
   *         21 -  All Wheels   Left       Change Speed
   *         22 -  All Wheels   Right      Set Speed
   *         23 -  All Wheels   Right      Change Speed
   *     Byte 3-5: Specify speed from 0 to 255
   * Servo:
   *     Byte 2: Specifcy Servo and Type
   *         0  -  Arm Angle      Set Angle
   *         1  -  Arm Angle      Change Angle
   *         2  -  Arm Height     Set Angle
   *         3  -  Arm Height     Change Angle
   *         4  -  Arm Rotation   Set Angle
   *         5  -  Arm Rotation   Change Angle
   *     Byte 3-5: Specify angle from 0 to 90
   */
      
  if (COMMUNICATION.available() >= 6) {
    inByte = COMMUNICATION.read();
    if(inByte == 42){
      inPackage[0] = COMMUNICATION.read();
      inPackage[1] = COMMUNICATION.read();
      inPackage[2] = ((COMMUNICATION.read()-48) * 100 ) + ((COMMUNICATION.read()-48) * 10 ) + ((COMMUNICATION.read()-48) * 1 );

      inPackage[1] -= 48;

      COMMUNICATION.print(inPackage[0]);
      COMMUNICATION.print("\t");
      COMMUNICATION.print(inPackage[1]);
      COMMUNICATION.print("\t");
      COMMUNICATION.print(inPackage[2]);
      COMMUNICATION.print("\n");
    
      if(inPackage[0] == 77){ // Motor
        switch(inPackage[1]){
          case 0:
            front_left.set_speed(inPackage[2]);
            break;
          case 1:
            front_left.change_speed(inPackage[2]);
            break;
          case 2:
            front_left.set_speed(-1 * inPackage[2]);
            break;
          case 3:
            front_left.change_speed(-1 * inPackage[2]);
            break;
          case 4:
            back_left.set_speed(inPackage[2]);
            break;
          case 5:
            back_left.change_speed(inPackage[2]);
            break;
          case 6:
            back_left.set_speed(-1 * inPackage[2]);
            break;
          case 7:
            back_left.change_speed(-1 * inPackage[2]);
            break;
          case 8:
            back_right.set_speed(inPackage[2]);
            break;
          case 9:
            back_right.change_speed(inPackage[2]);
            break;
          case 10:
            back_right.set_speed(-1 * inPackage[2]);
            break;
          case 11:
            back_right.change_speed(-1 * inPackage[2]);
            break;
          case 12:
            front_right.set_speed(inPackage[2]);
            break;
          case 13:
            front_right.change_speed(inPackage[2]);
            break;
          case 14:
            front_right.set_speed(-1 * inPackage[2]);
            break;
          case 15:
            front_right.change_speed(-1 * inPackage[2]);
            break;
          case 16:
            front_right.set_speed(inPackage[2]);
            back_right.set_speed(inPackage[2]);
            front_left.set_speed(inPackage[2]);
            back_left.set_speed(inPackage[2]);
            break;
          case 17:
            front_right.change_speed(inPackage[2]);
            back_right.change_speed(inPackage[2]);
            front_left.change_speed(inPackage[2]);
            back_left.change_speed(inPackage[2]);
            break;
          case 18:
            front_right.set_speed(-1 * inPackage[2]);
            back_right.set_speed(-1 * inPackage[2]);
            front_left.set_speed(-1 * inPackage[2]);
            back_left.set_speed(-1 * inPackage[2]);
            break;
          case 19:
            front_right.change_speed(-1 * inPackage[2]);
            back_right.change_speed(-1 * inPackage[2]);
            front_left.change_speed(-1 * inPackage[2]);
            back_left.change_speed(-1 * inPackage[2]);
            break;
          case 20:
            front_right.set_speed(-1 * inPackage[2]);
            back_right.set_speed(-1 * inPackage[2]);
            front_left.set_speed(inPackage[2]);
            back_left.set_speed(inPackage[2]);
            break;
          case 21:
            front_right.change_speed(-1 * inPackage[2]);
            back_right.change_speed(-1 * inPackage[2]);
            front_left.change_speed(inPackage[2]);
            back_left.change_speed(inPackage[2]);
            break;
          case 22:
            front_right.set_speed(inPackage[2]);
            back_right.set_speed(inPackage[2]);
            front_left.set_speed(-1 * inPackage[2]);
            back_left.set_speed(-1 * inPackage[2]);
            break;
          case 23:
            front_right.change_speed(inPackage[2]);
            back_right.change_speed(inPackage[2]);
            front_left.change_speed(-1 * inPackage[2]);
            back_left.change_speed(-1 * inPackage[2]);
            break;
          default:
            break;
        }
      }
      #IF SERVOS == 1
      else if (inPackage[0] == 83){ // Servo
        switch(inPackage[1]){
          case 0:
            arm_angle.set_angle(inPackage[2]);
            break;
          case 1:
            arm_angle.change_angle(inPackage[2]);
            break;
          case 2:
            arm_height.set_angle(inPackage[2]);
            break;
          case 3:
            arm_height.change_angle(inPackage[2]);
            break;
          case 4:
            arm_rotation.set_angle(inPackage[2]);
            break;
          case 5:
            arm_rotation.change_angle(inPackage[2]);
            break;
          default:
            break;
        }
      } #ENDIF
    }
  }
}
