#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter():Subsystem("Shooter"){
	_ShooterMotor.reset(new frc::Talon(2));
	_TankMotor.reset(new frc::Talon(3));
}

void Shooter::InitDefaultCommand(){

}

void Shooter::Set(double ShooterSpeed, double TankSpeed){
	_ShooterMotor->Set(ShooterSpeed);
	_TankMotor->Set(TankSpeed);
}
