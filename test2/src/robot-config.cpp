#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller con = controller(primary);
motor leftMotorA = motor(PORT11, ratio18_1, false);
motor leftMotorB = motor(PORT17, ratio18_1, false);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);

motor rightMotorA = motor(PORT13, ratio18_1, true); 
motor rightMotorB = motor(PORT9, ratio18_1, true); 
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);

inertial TurnGyroSmart = inertial(PORT8);
smartdrive Drivetrain= smartdrive(LeftDriveSmart, RightDriveSmart, TurnGyroSmart,319.19, 320, 165, mm, 1);
motor trayMotor = motor(PORT16, ratio36_1, false);
motor leftIntake = motor(PORT12, ratio18_1, false);
motor rightIntake = motor(PORT4, ratio18_1, true);
motor armMotor = motor(PORT10, ratio18_1, true);
// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain gyro
  wait(200, msec);
  TurnGyroSmart.calibrate();
  Brain.Screen.print("Calibrating Gyro for Drivetrain");
  // wait for the gyro calibration process to finish
  while (TurnGyroSmart.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}