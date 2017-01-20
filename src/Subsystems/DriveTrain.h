#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class DriveTrain:public Subsystem{
	private:

	public:
		/*CANTalon* _FrontLeft;
		CANTalon* _FrontRight;
		CANTalon* _BackLeft;
		CANTalon* _BackRight;*/
		std::unique_ptr<CANTalon> _FrontLeft;
		std::unique_ptr<CANTalon> _FrontRight;
		std::unique_ptr<CANTalon> _BackLeft;
		std::unique_ptr<CANTalon> _BackRight;
		//frc::RobotDrive* _Drive;
		std::unique_ptr<frc::RobotDrive> _Drive;

		DriveTrain();
		void InitDefaultCommand();
		void Drive(float X, float Y, float Rotation, float GyroAngle);
};

#endif
