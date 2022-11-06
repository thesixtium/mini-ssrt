//
// Created by Sixtium on 2022-11-06.
//

#ifndef MEGA_CODE_ARMSERVO_H
#define MEGA_CODE_ARMSERVO_H

#include <Servo.h>

class ArmServo {
private:
    Servo servo;
    double position;
    void update();
    double fmod(double a, double b);

public:
    ArmServo(int pin);
    void change_angle(double change);
    void set_angle(double angle);
};


#endif //MEGA_CODE_ARMSERVO_H
