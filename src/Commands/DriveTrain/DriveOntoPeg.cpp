#include "DriveOntoPeg.h"

DriveOntoPeg::DriveOntoPeg() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::drivetrain.get());
	SetTimeout(2);
}

// Called just before this Command runs the first time
void DriveOntoPeg::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveOntoPeg::Execute() {
	CommandBase::drivetrain.get()->Drive(0.0, 0.5, 0.0, 0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveOntoPeg::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void DriveOntoPeg::End() {
	CommandBase::drivetrain.get()->Drive(0.0, 0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveOntoPeg::Interrupted() {

}
