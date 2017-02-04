#ifndef BallIntake_H
#define BallIntake_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class BallIntake:public Subsystem{
	private:

	public:
		std::unique_ptr<frc::Talon> _IntakeMotor;
		std::unique_ptr<frc::Spark> _AgitatorMotor;

		BallIntake();
		void InitDefaultCommand();
		void Set(double IntakePower, double AgitatorPower);
};

#endif  // BallIntake_H
