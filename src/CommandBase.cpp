#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<DriveTrain> CommandBase::drivetrain;
std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name):Command(name){
}

CommandBase::CommandBase():Command(){
}

void CommandBase::init(){
	drivetrain.reset(new DriveTrain());

	oi.reset(new OI());
}
