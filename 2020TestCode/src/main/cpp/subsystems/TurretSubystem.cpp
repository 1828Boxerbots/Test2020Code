/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TurretSubystem.h"

TurretSubystem::TurretSubystem() {}

// This method will be called once per scheduler run
void TurretSubystem::Periodic() {}
void TurretSubystem::Turn(double angle)
{
    m_turretAngle += angle;
    m_turretAngle = Util::Limit(m_turretAngle, LOWERLIMIT, UPPERLIMIT);
    frc::SmartDashboard::PutNumber("Turret Angle", m_turretAngle);
}

void TurretSubystem::Turn(bool aButton, bool bButton)
{
    double motorSpeed;
    if(aButton == true && bButton == false)
    {
        motorSpeed = -MOTORSPEED;
    }
    else if(aButton == false && bButton == true)
    {
        motorSpeed = MOTORSPEED;
    }
    else
    {
        motorSpeed = 0.0;
    }
    #ifndef NOHW
    m_turretMotor.Set(motorSpeed);
    #endif
    frc::SmartDashboard::PutNumber("Turret Speed", motorSpeed);
}
