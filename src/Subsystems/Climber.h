#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Climber : public Subsystem {
	private:

	public:
		std::unique_ptr<frc::Talon> _ClimberMotor;

		Climber();
		void InitDefaultCommand();
		void Set(float Power);
};

#endif  // Climber_H
