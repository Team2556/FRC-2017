#include "TeleopCommand.h"

TeleopCommand::TeleopCommand():
	_DriveMode(0){
	Requires(drivetrain.get());
	Requires(ballintake.get());
	Requires(gearintake.get());
	Requires(climber.get());
	Requires(shooter.get());
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

	ballintake.get()->Set(oi->Xbox1.get()->GetTriggerAxis(frc::XboxController::kRightHand) - oi->Xbox1.get()->GetTriggerAxis(frc::XboxController::kLeftHand));

	gearintake.get()->Set(oi->Xbox1.get()->GetXButton() ? frc::DoubleSolenoid::Value::kForward : frc::DoubleSolenoid::Value::kReverse);

	climber.get()->Set(oi->Xbox1.get()->GetBumper(frc::XboxController::kRightHand) ? 1.0 : 0.0);
}

bool TeleopCommand::IsFinished(){
	return false;
}

void TeleopCommand::End(){
	drivetrain.get()->Drive(0.0, 0.0, 0.0, 0.0);
	ballintake.get()->Set(0.0);
	gearintake.get()->Set(frc::DoubleSolenoid::kOff);
	climber.get()->Set(0.0);
}

void TeleopCommand::Interrupted(){

}

int TeleopCommand::GetDriveMode(){
	return _DriveMode;
}
