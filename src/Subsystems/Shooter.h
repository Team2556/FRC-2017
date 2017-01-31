#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Shooter:public Subsystem{
	private:

	public:
		std::unique_ptr<frc::Talon> _ShooterMotor;
		std::unique_ptr<frc::Talon> _TankMotor;

		Shooter();
		void InitDefaultCommand();
		void Set(double ShooterSpeed, double TankSpeed);
};

#endif  // Shooter_H
