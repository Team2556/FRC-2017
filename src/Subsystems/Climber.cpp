#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber():Subsystem("Climber"){
	_ClimberMotor.reset(new frc::Talon(1));
}

void Climber::InitDefaultCommand(){

}

void Climber::Set(double Power){
	_ClimberMotor->Set(Power);
}
