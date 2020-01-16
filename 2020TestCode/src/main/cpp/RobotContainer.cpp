/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem)
 {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
  m_drive.SetDefaultCommand(frc2::RunCommand(
    [this] 
    {
      m_drive.MoveTank(m_controller.GetY(frc::GenericHID::kLeftHand), m_controller.GetY(frc::GenericHID::kRightHand));
    }
    ,{&m_drive}));
    frc::SmartDashboard::PutNumber("Turret Angle", m_turret.m_turretAngle);
}

void RobotContainer::ConfigureButtonBindings() 
{
  //5 = Bumper left, 6 = Bumper right
  frc2::JoystickButton(&m_controller, 1).WhenPressed(&m_turretTurnLeft);
  frc2::JoystickButton(&m_controller, 2).WhenPressed(&m_turretTurnRight);

  // Configure your button bindings here

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
