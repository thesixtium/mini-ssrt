//
// Created by Sixtium on 2022-11-06.
//

#ifndef MEGA_CODE_DRIVERMOTOR_H
#define MEGA_CODE_DRIVERMOTOR_H

#include <AFMotor.h>

class DriverMotor {
private:
    AF_DCMotor motor = 0;
    int current_speed;

public:
    DriverMotor(int position);
    void set_speed(int target_speed);
    void change_speed(int change);
};


#endif //MEGA_CODE_DRIVERMOTOR_H
