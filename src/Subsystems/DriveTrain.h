#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class DriveTrain:public Subsystem{
	private:
		std::unique_ptr<CANTalon> _FrontLeft;
		std::unique_ptr<CANTalon> _FrontRight;
		std::unique_ptr<CANTalon> _BackLeft;
		std::unique_ptr<CANTalon> _BackRight;

		std::unique_ptr<frc::RobotDrive> _Drive;
	public:
		DriveTrain();
		void InitDefaultCommand();
		void Drive(float X, float Y, float Rotation, float GyroAngle);
};

#endif
