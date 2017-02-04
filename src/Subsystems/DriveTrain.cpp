#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain():Subsystem("DriveTrain"){
	_FrontLeft.reset(new CANTalon(FRONT_LEFT_MOTOR));
	_FrontRight.reset(new CANTalon(FRONT_RIGHT_MOTOR));
	_BackLeft.reset(new CANTalon(BACK_LEFT_MOTOR));
	_BackRight.reset(new CANTalon(BACK_RIGHT_MOTOR));

	_FrontRight->SetInverted(true);
	_BackRight->SetInverted(true);

	_Drive.reset(new frc::RobotDrive(_FrontLeft.get(), _BackLeft.get(), _FrontRight.get(), _BackRight.get()));

	_AngleController.reset(new frc::PIDController(0.0, 0.0, 0.0, NavX.get(), this));
}

void DriveTrain::InitDefaultCommand(){

}

void DriveTrain::Drive(double X, double Y, double Rotation, double GyroAngle){
	_Drive->MecanumDrive_Cartesian(X, Y, Rotation, GyroAngle);
}

void DriveTrain::DriveWithAngle(double X, double Y, double dSetPoint, double GyroAngle){
	_AngleController->SetSetpoint(_AngleController->GetSetpoint() + dSetPoint);
	_Drive->MecanumDrive_Cartesian(X, Y, _AngleController->Get(), GyroAngle);
}

void DriveTrain::PIDWrite(double Output){

}
