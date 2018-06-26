/*-----------------------------------------*/
/* pneumaticsTest                          */
/* Created by: Casey Jones                 */
/* used for learning how to use pneumatics */
/*-----------------------------------------*/

#include <iostream>
#include <string>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "WPILib.h"
#include <Joystick.h>
#include "Compressor.h"
#include "Solenoid.h"

class Robot : public frc::IterativeRobot {
private:
	Compressor *compress;
	Solenoid *solo;
	Joystick *stick;
	Timer *timer;

public:
	void RobotInit() {
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

		stick = new Joystick{0};

		compress = new Compressor(0);
		solo = new Solenoid(4);
		compress->SetClosedLoopControl(true);

		timer = new Timer();
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
		if (stick->GetRawButtonPressed(1)) {
			solo->Set(true);
			//timer->Start();
		}
		else if (stick->GetRawButtonPressed(1) == false) {
			solo->Set(false);
			//timer->Stop();
			//timer->Reset();
		}

		/*else if (timer->Get() >= 2.0) {
			solo->Set(false);
			timer->Stop();
			timer->Reset();
		}*/

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
