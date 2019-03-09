#pragma once

#define RED_BOT
#define _USE_MATH_DEFINES

#include <string>
#include <iostream>
#include <math.h>
#include <frc/AnalogPotentiometer.h>
#include <frc/buttons/POVButton.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include "frc/smartdashboard/SmartDashboard.h"
#include "DalekDrive.h"
#include "MicroLidar.h"
#include "DalekShuffleboard.h"
#include "LineSensor.h"
#include "Arm.h"
#include "Claw.h"
#include "MicroLidar.h"
#include "DalekShuffleboard.h"
#include "LineSensor.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

  enum CANIDs {LEFT_FRONT_MOTOR = 1, LEFT_REAR_MOTOR, RIGHT_FRONT_MOTOR, RIGHT_REAR_MOTOR, SHOULDER_MOTOR, ELBOW_MOTOR, TURRET_MOTOR, CLAW_MOTOR};
  enum DIOS   {FRONT_LEFT_LIDAR = 0, FRONT_RIGHT_LIDAR, RIGHT_FRONT_LIDAR, RIGHT_REAR_LIDAR, LEFT_FRONT_LIDAR_, LEFT_REAR_LIDAR};

 private:
  DalekDrive *m_drive;
  rev::CANSparkMax *m_leftFront;
  rev::CANSparkMax *m_leftRear;
  rev::CANSparkMax *m_rightFront;
  rev::CANSparkMax *m_rightRear;
  MicroLidar *microLidar;
  LineSensor *lineSensor;
  DalekShuffleboard *dalekShuffleboard;
  frc::Joystick *m_fakeStick;
  Arm *m_arm;
  Claw *m_claw;
  frc::Joystick *m_leftStick;
  frc::Joystick *m_rightStick;
  frc::XboxController *m_xbox;
  frc::POVButton *m_dPad[4];
  AHRS *ahrs;
};