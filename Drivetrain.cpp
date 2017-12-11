#include "Arduino.h"
#include "Drivetrain.h"



//TODO-add encoders? gyro? line tracker
void Drivetrain::init() {
  leftDriveMotor.attach(4, 1000, 2000);
  rightDriveMotor.attach(5, 1000, 2000);
  pinMode(leftLineTrackerPin, INPUT);
  pinMode(rightLineTrackerPin, INPUT);
}

void Drivetrain::driveWithJoystick(int leftMotorSpeed, int rightMotorSpeed) {
  leftDriveMotor.write(leftMotorSpeed);
  rightDriveMotor.write(rightMotorSpeed);
}

void Drivetrain::turn(int turn) {
  leftDriveMotor.write(90 - turn);
  rightDriveMotor.write(90 - turn);
}
void Drivetrain::driveStraight(int speed) {
  leftDriveMotor.write(90 + speed);
  rightDriveMotor.write(90 - speed);
}

void Drivetrain::stopDrive() {
  leftDriveMotor.write(90);
  rightDriveMotor.write(90);
}

void Drivetrain::stopAtLine(){
  if(analogRead(leftLineTrackerPin) < 850 || analogRead(rightLineTrackerPin) < 850){
    stopDrive();
  }
  if (analogRead(leftLineTrackerPin) > 900 || analogRead(rightLineTrackerPin) > 900){
    driveStraight(30);  
  } 
}
