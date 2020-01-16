/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrainSubsystem.h"

DriveTrainSubsystem::DriveTrainSubsystem() {}

// This method will be called once per scheduler run
void DriveTrainSubsystem::Periodic() {}
 void DriveTrainSubsystem::MoveTank(double leftY, double rightY)
  {
        frc::SmartDashboard::PutNumber("Drive Left", leftY);
        frc::SmartDashboard::PutNumber("Drive Right", rightY);
  }