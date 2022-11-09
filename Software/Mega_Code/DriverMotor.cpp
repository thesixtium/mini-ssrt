//
// Created by Sixtium on 2022-11-06.
//

#include "DriverMotor.h"

DriverMotor::DriverMotor(int position){
  AF_DCMotor motor(position);
  this->motor = motor;
  this->set_speed(current_speed);
}

void DriverMotor::set_speed(int target_speed){
    target_speed %= 255;
    if(target_speed == 0) {
        this->motor.run(RELEASE);
    } else if(target_speed < 0) {
        this->motor.run(BACKWARD);
    } else {
        this->motor.run(FORWARD);
    }
    
    this->current_speed = target_speed;
    motor.setSpeed(this->current_speed);
}

void DriverMotor::change_speed(int change){
    this->current_speed += change%255;
    this->set_speed(this->current_speed);
}
