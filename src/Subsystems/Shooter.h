#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "CANTalon.h"

class Shooter:public Subsystem{
	private:

	public:
		std::unique_ptr<CANTalon> _ShooterMotor;
		std::unique_ptr<Spark> _TankMotor;

		Shooter();
		void InitDefaultCommand();
		void Set(double ShooterSpeed, double TankSpeed);
};

#endif  // Shooter_H
