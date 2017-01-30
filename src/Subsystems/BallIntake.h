#ifndef BallIntake_H
#define BallIntake_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class BallIntake : public Subsystem {
	private:

	public:
		std::unique_ptr<frc::Talon> _IntakeMotor;

		BallIntake();
		void InitDefaultCommand();
		void Set(float Power);
};

#endif  // BallIntake_H
