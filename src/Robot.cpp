/*------------------------------------------------*/
/* candyBot2018                                   */
/* Created by: Casey Jones                        */
/* Drive code for the 2018 Summer Parade Bot      */
/* Motor Controller Type: Victors                 */
/*------------------------------------------------*/

#include <iostream>
#include <string>
#include "WPILib.h"
#include <Joystick.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Drive/DifferentialDrive.h"
#include <PWMSpeedController.h>
//#include "DifferentialDrive.h"
#include <SpeedController.h>

class Robot : public frc::IterativeRobot {

private:
	frc::Joystick stick {0};

	DifferentialDrive *robotDrive;

	Victor *driveMotorLeft;

	Victor *driveMotorRight;

	double stickY;
	double stickZ;
	bool quickTurn;
public:

	void RobotInit() {
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

		driveMotorLeft = new Victor(1);
		driveMotorRight = new Victor(2);

		robotDrive = new DifferentialDrive(*driveMotorLeft, *driveMotorRight);

	}

	void AutonomousInit() override {
		m_autoSelected = m_chooser.GetSelected();
		// m_autoSelected = SmartDashboard::GetString(
		// 		"Auto Selector", kAutoNameDefault);
		std::cout << "Auto selected: " << m_autoSelected << std::endl;

		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void AutonomousPeriodic() {
		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void TeleopInit() {}

	void TeleopPeriodic() {
		stickY = stick.GetRawAxis(1);
		stickZ = stick.GetRawAxis(2);
		quickTurn = stick.GetRawButton(3);

		if (stickY > 0  or stickY < -0.1) {
			stickY = 0;
		}

		if (stickZ < 0.1) {
			stickZ = 0;
		}

		robotDrive->CurvatureDrive(-stickY, stickZ, quickTurn);
	}

	void TestPeriodic() {}

private:
	frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
};

START_ROBOT_CLASS(Robot)
