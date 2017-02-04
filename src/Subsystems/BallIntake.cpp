#include "BallIntake.h"
#include "../RobotMap.h"

BallIntake::BallIntake():Subsystem("BallIntake"){
	_IntakeMotor.reset(new frc::Talon(0));
	_AgitatorMotor.reset(new frc::Spark(3));
}

void BallIntake::InitDefaultCommand(){

}

void BallIntake::Set(double IntakePower, double AgitatorPower){
	_IntakeMotor->Set(IntakePower);
	_AgitatorMotor->Set(AgitatorPower);
}
