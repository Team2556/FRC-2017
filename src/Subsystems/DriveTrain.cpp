#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain():Subsystem("DriveTrain"){
	_FrontLeft = new CANTalon(FRONT_LEFT_MOTOR);
	_FrontRight = new CANTalon(FRONT_RIGHT_MOTOR);
	_BackLeft = new CANTalon(BACK_LEFT_MOTOR);
	_BackRight = new CANTalon(BACK_RIGHT_MOTOR);

	_FrontRight->SetInverted(true);
	_BackRight->SetInverted(true);

	_Drive = new frc::RobotDrive(_FrontLeft, _BackLeft, _FrontRight, _BackRight);
}

void DriveTrain::InitDefaultCommand(){

}

void DriveTrain::Drive(float X, float Y, float Rotation, float GyroAngle){
	_Drive->MecanumDrive_Cartesian(X, Y, Rotation, GyroAngle);
}
