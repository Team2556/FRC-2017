#ifndef AutonomousMain_H
#define AutonomousMain_H

#include <Commands/DriveTrain/DriveToGearPost.h>
#include "WPILib.h"
#include "Commands/CommandGroup.h"

class AutonomousMain: public CommandGroup{
	public:
		AutonomousMain();
};

#endif
