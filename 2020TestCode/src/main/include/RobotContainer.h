/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include <frc/XboxController.h>
#include "Constants.h"
#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/TurretSubystem.h"
#include <frc2/command/RunCommand.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/LoaderSubsystem.h"
#include "subsystems/ShooterSubsystem.h"



/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  //Controller
  frc::XboxController m_controller{USB_CONTROLLER_ONE};
  DriveTrainSubsystem m_drive;
  TurretSubystem m_turret;
  LoaderSubsystem m_loader;
  ShooterSubsystem m_shooter;

  frc2::RunCommand m_turretTurnLeft{[this] {m_turret.Turn(m_controller.GetAButton(), m_controller.GetBButton());}, {&m_turret}};
  frc2::RunCommand m_turretTurnRight{[this] {m_turret.Turn(m_controller.GetAButton(), m_controller.GetBButton());}, {&m_turret}};
  frc2::RunCommand m_turretStop{[this] {m_turret.Turn(false, false);}, {&m_turret}};

  frc2::RunCommand m_loaderEject{[this] {m_loader.LoadXY(m_controller.GetXButton(), m_controller.GetYButton());}, {&m_loader}};
  frc2::RunCommand m_loaderLoad{[this] {m_loader.LoadXY(m_controller.GetXButton(), m_controller.GetYButton());}, {&m_loader}};
  frc2::RunCommand m_loaderStop{[this] {m_loader.LoadXY(false, false);}, {&m_loader}};

  frc2::RunCommand m_spinShooter{[this] {m_shooter.ShootBump(true);}, {&m_shooter}};
  frc2::RunCommand m_shooterStop{[this] {m_shooter.ShootBump(false);}, {&m_shooter}};

  void ConfigureButtonBindings();
};
