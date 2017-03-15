#include "AutonomousMain.h"

AutonomousMain::AutonomousMain(){
	//if(DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kBlue){
		AddSequential(new Drive(0.5, 0.0, -0.6, -0.65));
		AddSequential(new Drive(3.0, -0.7, 0.0, 0.0));
		AddSequential(new Shooting(10.0));
		//shoot
		//AddSequential(new Drive(2.0, 0.75, -0.1, 0.0));
	/*} else {
		AddSequential(new Drive(0.5, 0.0, 0.5, 0.0));
		AddSequential(new Drive(0.5, 0.0, 0.0, 0.5));
		AddSequential(new Drive(0.5, -0.75, 0.0, 0.0));
		//shoot
		AddSequential(new Drive(2.0, 0.75, 0.1, 0.0));
	}*/

	//AddSequential(new Drive(1.5, 0.0, -0.5, 0.0));
	/*AddSequential(new DriveFromPlayerStation(SmartDashboard::GetNumber("PlayerStation", 1.0), SmartDashboard::GetNumber("Gear", 1.0)));

	if(SmartDashboard::GetNumber("Gear", 0.0) != 2)
		AddSequential(new Drive(1, 0, 0, 0.25));

	AddSequential(new DriveToGearPost());
	AddSequential(new Drive(2, 0.0, 0.5, 0.0));
	AddSequential(new Drive(2, 0.0, -0.5, 0.0));


	if(SmartDashboard::GetNumber("Gear", 0.0) == 2){
		AddSequential(new Drive(3, 0.7, 0, 0.0));
		AddSequential(new Drive(2, 0.0, 0.5, 0.0));
	}*/
}
