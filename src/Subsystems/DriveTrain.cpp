#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain():Subsystem("DriveTrain"){
	/*_FrontLeft = new CANTalon(FRONT_LEFT_MOTOR);
	_FrontRight = new CANTalon(FRONT_RIGHT_MOTOR);
	_BackLeft = new CANTalon(BACK_LEFT_MOTOR);
	_BackRight = new CANTalon(BACK_RIGHT_MOTOR);

	_FrontRight->SetInverted(true);
	_BackRight->SetInverted(true);*/

	_FrontLeft.reset(new CANTalon(FRONT_LEFT_MOTOR));
	_FrontRight.reset(new CANTalon(FRONT_RIGHT_MOTOR));
	_BackLeft.reset(new CANTalon(BACK_LEFT_MOTOR));
	_BackRight.reset(new CANTalon(BACK_RIGHT_MOTOR));

	_FrontRight->SetInverted(true);
	_BackRight->SetInverted(true);

	//_Drive = new frc::RobotDrive(_FrontLeft, _BackLeft, _FrontRight, _BackRight);
	_Drive.reset(new frc::RobotDrive(_FrontLeft.get(), _BackLeft.get(), _FrontRight.get(), _BackRight.get()));
}

void DriveTrain::InitDefaultCommand(){

}

void DriveTrain::Drive(float X, float Y, float Rotation, float GyroAngle){
	_Drive->MecanumDrive_Cartesian(X, Y, Rotation, GyroAngle);
}
