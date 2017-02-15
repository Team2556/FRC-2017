#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter():Subsystem("Shooter"){
	_ShooterMotor.reset(new CANTalon(SHOOTER_MOTOR));
	_TankMotor.reset(new CANTalon(TANK_MOTOR));

	//_ShooterMotor->SetFeedbackDevice(CANTalon::FeedbackDevice::CtreMagEncoder_Absolute);
}

void Shooter::InitDefaultCommand(){

}

void Shooter::Set(double ShooterSpeed, double TankSpeed){
	_ShooterMotor->Set(ShooterSpeed);
	_TankMotor->Set(TankSpeed);
}
