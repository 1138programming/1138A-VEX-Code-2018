// #include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
//
// #include "libIterativeRobot/Robot.h"
//
// #include "api.h"
//
// DriveToPosition::DriveToPosition(int leftTarget, int rightTarget) {
//   requires(Robot::robotBase);
//   this->leftTarget = leftTarget;
//   this->rightTarget = rightTarget;
//   this->motorSpeed = 0;
//   this->startTime = pros::millis();
// }
//
// DriveToPosition::DriveToPosition(int leftTarget, int rightTarget, int motorSpeed) {
//   requires(Robot::robotBase);
//   this->leftTarget = leftTarget;
//   this->rightTarget = rightTarget;
//   this->motorSpeed = motorSpeed;
//   this->startTime = pros::millis();
// }
//
// bool DriveToPosition::canRun() {
//   printf("DriveToPosition(%d, %d)\n", leftTarget, rightTarget);
//   return true; // This is the default value anyways, so this method can be removed
// }
//
// void DriveToPosition::initialize() {
//   // Perform any initialization steps for this command here, not in the
//   // constructor
//   this->endTime = pros::millis() + ((((abs(leftTarget) + abs(rightTarget)) / 2) / (motorSpeed ? motorSpeed : 150)) * 150) + 500;
//   Robot::robotBase->moveBaseTo(leftTarget, rightTarget, motorSpeed);
// }
//
// void DriveToPosition::execute() {
//   // Code that runs when this command is scheduled to run
// }
//
// bool DriveToPosition::isFinished() {
//   if ((pros::millis() - startTime) < 250) return false;
//   return Robot::robotBase->baseAtTarget() || pros::millis() > endTime; // This is the default value anyways, so this method can be removed
// }
//
// void DriveToPosition::end() {
//   // Code that runs when isFinished() returns true.
//   Robot::robotBase->moveBase(0, 0);
// }
//
// void DriveToPosition::interrupted() {
//   // Code that runs when this command is interrupted by another one
//   // with a higher priority.
// }
