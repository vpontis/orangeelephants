/*
legobot_motor.h
Created 2/14/09
Mark Allen Vismonte
A header file for the legobot_motor.c file
*/

#ifndef legobot_motor_h
#define legobot_motor_h

//Motor and Servo port declarations

/** \brief Left motor port.
*/
#define L_MOTOR 2

/** \brief Right motor port.
*/
#define R_MOTOR 3

/** \brief Front arm port.
*/
#define FRONT_ARM 3

/** \brief Back arm port.
*/
#define BACK_ARM 4

/** \brief The amount of ticks to turn 1degree.

	Conversion factors, TICKS_PER_DEGREE is for the turn method
	TICKS_PER_MM is used for moving straight and arcing
*/
#define TICKS_PER_DEGREE 5.4817275

/** \brief The amount of ticks to move 1mm.
*/
#define TICKS_PER_MM 5.002012496

/** \brief The amount of ticks turned in one iteration.
*/
#define TICKS_PER_ITERATION 100

//Different speeds defined in ticks per second
#define MAX_SPEED 1000
#define TEST_SPEED 500

/** \brief The diameter of the Legobot in millimeters.
*/
#define LEGOBOT_DIAMETER 170

#include "boolean.h"


void move(int velocityL, int velocityR);
void move_distance(float distance);
void turn_off(void);
void turn_arc(boolean leftArc, float outerRadius, int speed, float move_distance);
void turn_arc_degrees(boolean leftArc, float outerRadius, int speed, float degrees);
void move_direct_distance(int speed, float distance);
void lock_arms(void);
void release_arms(void);
void ice(void);
void bmd_motors(void);

/** \brief Used for \ref ice function to work properly.
	\see ice
*/
boolean doIce = false;

#endif
