#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "CommandBase.h"

#include "Commands/Autonomous/AutonomousMain.h"
#include "Commands/Teleoperated/TeleopCommand.h"

#include "IMU.h"

std::unique_ptr<IMU> NavX;

class Robot:public frc::IterativeRobot{
	private:
		std::unique_ptr<frc::Command> AutonomousC;
		std::unique_ptr<TeleopCommand> TeleopC;
		std::unique_ptr<frc::Compressor> Comp;
		frc::SendableChooser<frc::Command*> chooser;
	public:
		void RobotInit() override{
			CommandBase::init();

			/*chooser.AddDefault("Default Auto", new ExampleCommand());
			chooser.AddObject("My Auto", new MyAutoCommand());
			frc::SmartDashboard::PutData("Auto Modes", &chooser);*/

			AutonomousC.reset(new AutonomousMain());
			TeleopC.reset(new TeleopCommand());
			NavX.reset(new IMU(SPI::Port::kMXP));

			Comp.reset(new frc::Compressor(11));

			// This code streams camera 0 to the dashboard using WPILib's CameraServer
			// frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
		}

		void DisabledInit() override{
			Comp->SetClosedLoopControl(false);
		}

		void DisabledPeriodic() override{
			frc::Scheduler::GetInstance()->Run();
			GlobalPeriodic();
		}

		void AutonomousInit() override{
			/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
			 if (autoSelected == "My Auto") {
			 autonomousCommand.reset(new MyAutoCommand());
			 }
			 else {
			 autonomousCommand.reset(new ExampleCommand());
			 }

			AutonomousC.reset(chooser.GetSelected());*/
			Comp->SetClosedLoopControl(true);
			if (AutonomousC.get() != nullptr){
				AutonomousC->Start();
			}
		}

		void AutonomousPeriodic() override{
			frc::Scheduler::GetInstance()->Run();
			GlobalPeriodic();
		}

		void TeleopInit() override{
			/*if (autonomousCommand != nullptr){
				autonomousCommand->Cancel();
			}*/
			Comp->SetClosedLoopControl(true);
			if(TeleopC.get() != nullptr)
				TeleopC->Start();
		}

		void TeleopPeriodic() override{
			frc::Scheduler::GetInstance()->Run();
			GlobalPeriodic();
		}

		void TestPeriodic() override{
			frc::LiveWindow::GetInstance()->Run();
			GlobalPeriodic();
		}

		void GlobalPeriodic(){

		}
};

START_ROBOT_CLASS(Robot)
