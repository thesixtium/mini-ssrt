//
// Created by Sixtium on 2022-11-06.
//

#include "ArmServo.h"

ArmServo::ArmServo(int pin){
    this->servo.attach(pin);
    this->position = 135;
    this->set_angle(this->position);
}
void ArmServo::change_angle(double change){
    // 90 < Range < 180
    if(change < 0 && this->position > 90){
        this->position += change;
    } else if (change > 0 && this->position < 180) {
        this->position += change;
    }
    this->update();
}

void ArmServo::set_angle(double angle){
    // 90 < Range < 180
    this->position = fmod(angle, 90) + 90;
    this->update();
}

void ArmServo::update() {
    this->servo.write(this->position);
}

double ArmServo::fmod(double a, double b){
    double mod;
    // Handling negative values
    if (a < 0)
        mod = -a;
    else
        mod =  a;
    if (b < 0)
        b = -b;
 
    // Finding mod by repeated subtraction
     
    while (mod >= b)
        mod = mod - b;
 
    // Sign of result typically depends
    // on sign of a.
    if (a < 0)
        return -mod;
 
    return mod;
}
