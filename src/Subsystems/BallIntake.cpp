#include "BallIntake.h"
#include "../RobotMap.h"

BallIntake::BallIntake() : Subsystem("BallIntake") {
	_IntakeMotor.reset(new frc::Talon(0));
}

void BallIntake::InitDefaultCommand() {

}

void BallIntake::Set(float Power){
	_IntakeMotor->Set(Power);
}