/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
constexpr int USB_CONTROLLER_ONE = 0;

constexpr int PWM_LEFTMOTOR = 2;
constexpr int PWM_RIGHTMOTOR = 3;
constexpr int PWM_SHOOTMOTOR = 5;
constexpr int PWM_TURRETMOTOR = 4;
constexpr int PWM_LOADMOTOR = 9;

#define NOHW
