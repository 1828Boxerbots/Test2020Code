/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Spark.h>
#include "Constants.h"
#include "Util.h"
#include <frc/ADXRS450_Gyro.h>
#include <frc/Timer.h>

class DriveTrainSubsystem : public frc2::SubsystemBase {
 public:
  DriveTrainSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void MoveTank(double leftY, double rightY);
  void Init();
  void Stop();
  void DriveForwardInSeconds(double goalTime);
  void TurnInRelativeDegrees(double angle);

 private:
 #ifndef NOHW
  frc::Spark m_leftMotor{PWM_LEFTMOTOR};
  frc::Spark m_rightMotor{PWM_RIGHTMOTOR};
  const double STOP = 0.0;
   frc::Timer time;
   frc::ADXRS450_Gyro m_gyro{SPI::Port::kOnboardCS0};
  #endif
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
