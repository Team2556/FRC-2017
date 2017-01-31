#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class DriveTrain:public Subsystem{
	private:

	public:
		std::unique_ptr<CANTalon> _FrontLeft;
		std::unique_ptr<CANTalon> _FrontRight;
		std::unique_ptr<CANTalon> _BackLeft;
		std::unique_ptr<CANTalon> _BackRight;

		std::unique_ptr<frc::RobotDrive> _Drive;

		DriveTrain();
		void InitDefaultCommand();
		void Drive(double X, double Y, double Rotation, double GyroAngle);
};

#endif
