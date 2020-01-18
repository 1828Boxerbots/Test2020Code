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
        
        leftY = Util::Limit(leftY, -.7, .7);
        rightY = Util::Limit(rightY, -.7, .7);
        frc::SmartDashboard::PutNumber("Drive Left", leftY);
        frc::SmartDashboard::PutNumber("Drive Right", rightY);

         #ifndef NOHW
        m_leftMotor.Set(leftY);
        m_rightMotor.Set(rightY);
        #endif
  }
  void DriveTrainSubsystem::Stop()
  {
    #ifndef NOHW
    m_leftMotor.Set(STOP);
    m_rightMotor.Set(STOP);
    #endif
  }
  void DriveTrainSubsystem::DriveForwardInSeconds(double goalTime)
{
    if(goalTime > 0)
    {
    double endTime = time.Get() + goalTime;
      MoveTank(1.0, 1.0);
      while(time.Get() < endTime){}
    }
      Stop();
}
void TurnInRelativeDegrees(double angle)
{
  #ifndef NOHW
  m_gyro.Reset();
  m_gyro.Calibrate();
  #endif
}

  void DriveTrainSubsystem::Init()
  {
    #ifndef NOHW
    m_rightMotor.SetInverted(false);
    m_leftMotor.SetInverted(true);
    #endif
  }