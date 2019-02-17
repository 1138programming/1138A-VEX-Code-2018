#ifndef _COMMANDS_COMMAND_H_
#define _COMMANDS_COMMAND_H_

#include "main.h"
#include <vector>
#include "libIterativeRobot/subsystems/Subsystem.h"

namespace libIterativeRobot {

enum Status {
  Idle = 0,
  Running,
  Finished,
  Interrupted
};

class Command {
  private:
    std::vector<Subsystem*> subsystemRequirements;
  protected:
    void requires(Subsystem* aSubsystem);
  public:
    static const int DefaultCommandPriority = 0;

    int priority = 50; // Commands can only be interrupted by commands with a higher priority
    Status status = Idle; // Keeps track of the status of the command

    std::vector<Subsystem*>& getRequirements();

    virtual bool canRun() = 0; // Whether or not the command can run right now. If false, it is ignored
    virtual void initialize() = 0; // Set up the command for running
    virtual void execute() = 0; // Run the command
    virtual bool isFinished() = 0; // Whether or not the command is finished. The execute() function is called continuously until this is true or the command is interrupted
    virtual void end() = 0; // Run when command is finished
    virtual void interrupted() = 0; // Run when command was interrupted by one with a higher priority

    void run(); // Runs this command. May be called anywhere.
    void stop(); // Stops this command while it is running. May be called anywhere.

    // ...and finally, the constructor!
    Command();
};

}; // namespace libIterativeRobot

#endif // _COMMANDS_COMMAND_H_
