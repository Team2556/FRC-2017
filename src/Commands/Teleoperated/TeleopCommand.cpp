#include "TeleopCommand.h"

TeleopCommand::TeleopCommand(){
	Requires(drivetrain.get());
}

void TeleopCommand::Initialize(){

}

void TeleopCommand::Execute(){
	drivetrain.get()->Drive(DeadSens(oi->Xbox1.get()->GetX(frc::XboxController::kLeftHand), 0.025, 0.85), DeadSens(oi->Xbox1.get()->GetY(frc::XboxController::kLeftHand), 0.025, 0.85), DeadSens(oi->Xbox1.get()->GetX(frc::XboxController::kRightHand), 0.025, 0.85), 0.0);
}

bool TeleopCommand::IsFinished(){
	return false;
}

void TeleopCommand::End(){
	drivetrain.get()->Drive(0.0, 0.0, 0.0, 0.0);
}

void TeleopCommand::Interrupted(){

}
