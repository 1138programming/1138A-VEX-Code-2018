#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/Robot.h"

DriveToPosition::DriveToPosition(int leftTarget, int rightTarget) {
  requires(Robot::robotBase);
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
}

bool DriveToPosition::canRun() {
  printf("DriveToPosition(%d, %d)\n", leftTarget, rightTarget);
  return true; // This is the default value anyways, so this method can be removed
}

void DriveToPosition::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::robotBase->moveBaseTo(leftTarget, rightTarget);
}

void DriveToPosition::execute() {
  // Code that runs when this command is scheduled to run
}

bool DriveToPosition::isFinished() {
  return Robot::robotBase->baseAtTarget(); // This is the default va  lue anyways, so this method can be removed
}

void DriveToPosition::end() {
  // Code that runs when isFinished() returns true.
}

void DriveToPosition::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
