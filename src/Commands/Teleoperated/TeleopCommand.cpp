#include "TeleopCommand.h"

TeleopCommand::TeleopCommand(){
	Requires(drivetrain.get());
}

void TeleopCommand::Initialize(){

}

void TeleopCommand::Execute(){
	drivetrain.get()->Drive(oi->Xbox1.get()->GetX(frc::XboxController::kLeftHand), oi->Xbox1.get()->GetY(frc::XboxController::kLeftHand), oi->Xbox1.get()->GetX(frc::XboxController::kRightHand), 0.0);
}

bool TeleopCommand::IsFinished(){
	return false;
}

void TeleopCommand::End(){
	drivetrain.get()->Drive(0.0, 0.0, 0.0, 0.0);
}

void TeleopCommand::Interrupted(){

}
