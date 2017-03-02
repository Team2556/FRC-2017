#include "AutonomousMain.h"

AutonomousMain::AutonomousMain(){

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
	AddSequential(new DriveFromPlayerStation(SmartDashboard::GetNumber("PlayerStation", 1.0), SmartDashboard::GetNumber("Gear", 1.0)));

	if(SmartDashboard::GetNumber("Gear", 0.0) != 2)
		AddSequential(new Drive(1, 0, 0, 0.25));

	AddSequential(new DriveToGearPost());
	AddSequential(new Drive(2, 0.0, 0.5, 0.0));
	AddSequential(new Drive(2, 0.0, -0.5, 0.0));


	if(SmartDashboard::GetNumber("Gear", 0.0) == 2){
		AddSequential(new Drive(3, 0.7, 0, 0.0));
		AddSequential(new Drive(2, 0.0, 0.5, 0.0));
	}



	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	//AddSequential(new Drive());
}
