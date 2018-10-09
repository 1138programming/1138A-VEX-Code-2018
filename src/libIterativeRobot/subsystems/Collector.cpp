#include "libIterativeRobot/subsystems/Collector.h"
#include "libIterativeRobot/commands/CollectorIdle.h"

Collector::Collector() {
  frontCollectorMotor = Motor::getMotor(frontCollectorMotorPort);
  middleCollectorMotor = Motor::getMotor(middleCollectorMotorPort);
  // Slaving will be tested after initial test
}

void Collector::runCollector(int velocity) {
  frontCollectorMotor->getMotorObject()->move_velocity(velocity);
  middleCollectorMotor->getMotorObject()->move_velocity(velocity);
}

void Collector::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new CollectorIdle());
}
