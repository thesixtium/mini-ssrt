//
// Created by Sixtium on 2022-11-06.
//

#ifndef MEGA_CODE_DRIVERMOTOR_H
#define MEGA_CODE_DRIVERMOTOR_H

#include <AFMotor.h>

class DriverMotor {
private:
    AF_DCMotor motor = 0;

public:
    DriverMotor(int position);
    void setSpeed(int speed);
};


#endif //MEGA_CODE_DRIVERMOTOR_H
