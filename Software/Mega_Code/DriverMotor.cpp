//
// Created by Sixtium on 2022-11-06.
//

#include "DriverMotor.h"

DriverMotor::DriverMotor(int position){
  AF_DCMotor motor(position);
  this->motor = motor;
  this->setSpeed(0);
}

void DriverMotor::setSpeed(int speed){
    if(speed == 0) {
        this->motor.run(RELEASE);
    } else if(speed < 0) {
        this->motor.run(BACKWARD);
    } else {
        this->motor.run(FORWARD);
    }
    motor.setSpeed(speed);
}
