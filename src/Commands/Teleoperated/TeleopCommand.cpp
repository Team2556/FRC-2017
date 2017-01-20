#include "TeleopCommand.h"

TeleopCommand::TeleopCommand():
	_DriveMode(0){
	Requires(drivetrain.get());
}

void TeleopCommand::Initialize(){

}

void TeleopCommand::Execute(){
	if(oi->Xbox1.get()->GetAButton())
		_DriveMode = 0; // Front
	if(oi->Xbox1.get()->GetBButton())
		_DriveMode = -1; // Left
	if(oi->Xbox1.get()->GetYButton())
		_DriveMode = 1; // Right

	drivetrain.get()->Drive(DeadSens(oi->Xbox1.get()->GetX(frc::XboxController::kLeftHand), 0.025, 0.85), DeadSens(oi->Xbox1.get()->GetY(frc::XboxController::kLeftHand), 0.025, 0.85), DeadSens(oi->Xbox1.get()->GetX(frc::XboxController::kRightHand), 0.025, 0.85), _DriveMode * 90.0);
}

bool TeleopCommand::IsFinished(){
	return false;
}

void TeleopCommand::End(){
	drivetrain.get()->Drive(0.0, 0.0, 0.0, 0.0);
}

void TeleopCommand::Interrupted(){

}

int TeleopCommand::GetDriveMode(){
	return _DriveMode;
}
