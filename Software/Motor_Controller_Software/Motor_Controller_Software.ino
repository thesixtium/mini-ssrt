#include <AFMotor.h>
#include <SoftwareSerial.h>

// D10 is connected to Servo 1, while D9 is connected to Servo 2.
const byte rxPin = 9;
const byte txPin = 10;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);
AF_DCMotor front_right(4);
AF_DCMotor front_left(1);
AF_DCMotor back_right(3);
AF_DCMotor back_left(2);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
    
  // Set the baud rate for the SoftwareSerial object
  mySerial.begin(9600);
  
  //Set initial speed of the motor & stop
  front_right.setSpeed(0);
  front_left.setSpeed(0);
  back_right.setSpeed(0);
  back_left.setSpeed(0);
  
  front_right.run(RELEASE);
  front_left.run(RELEASE);
  back_right.run(RELEASE);
  back_left.run(RELEASE);
}

void loop() {
  if (mySerial.available() > 0) {
    char data = mySerial.read();
    if(data == '*'){
      set_motor(front_right, mySerial.read());
      set_motor(front_left, mySerial.read());
      set_motor(back_right, mySerial.read());
      set_motor(back_left, mySerial.read());
    }
  }
}

void set_motor(AF_DCMotor motor, char data){
  int data_value = ((int)data)%127;
  
  if(data_value == 0) {
    motor.run(RELEASE);
  } else if(data < 0) {
    motor.run(BACKWARD);
  } else {
    motor.run(FORWARD);
  }

  motor.setSpeed(data_value);
}
