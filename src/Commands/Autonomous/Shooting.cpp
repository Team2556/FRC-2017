#include "Shooting.h"

Shooting::Shooting(float timeout) {
	Requires(CommandBase::shooter.get());
	SetTimeout(timeout);
}

// Called just before this Command runs the first time
void Shooting::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Shooting::Execute() {
	shooter->Set(0.8, -0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool Shooting::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Shooting::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shooting::Interrupted() {

}
