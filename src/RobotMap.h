#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

// CAN
// Control System Components
const int PDP = 1;
const int PCM = 2;

// Drivetrain motors
const int FRONT_LEFT_MOTOR = 11;
const int FRONT_RIGHT_MOTOR = 13;
const int BACK_LEFT_MOTOR = 12;
const int BACK_RIGHT_MOTOR = 14;

// Shooter motors
const int SHOOTER_MOTOR = 15;
const int TANK_MOTOR = 16;

// Ball intake motor
const int BALL_MOTOR = 17;

// Climber motor
const int CLIMBER_MOTOR = 18;

#endif  // ROBOTMAP_H
