/*
legobot_motor.h
/*Created 2/14/09
Mark Allen Vismonte
A header file for the legobot_motor.c file
*/

#ifndef legobot_motor_h
#define legobot_motor_h

/** \brief Wheelbase distance in cm
*/
#define LEGOBOT_DIAMETER 17

/** \brief number of motor ticks for 360 degrees
*/
#define TICKS_PER_REV 1020.4

/** \brief circumference of Legobot wheel in cm
*/
#define WHEEL_CIRCUMFERENCE 15.5822864  //25.6545444 big wheels 

/** \brief tick value used to compensate for motor dislocation
*/
#define MOTOR_OFFSET -2679

/** \brief tick speed to move arm motor at.
*/
#define TILT_SPEED 1000

#define SLOW_SPEED 200
#define NORMAL_SPEED 500
#define FAST_SPEED 750

#include "boolean.h"
void moveToDistance(double distance, int speed);
void moveToDistanceTurn(double distance, int speedL, int speedR);
void turn_arc_sweep(boolean leftArc, float outerRadius, int speed, float move_distance);
void turn(double angle);
void turnSlow(double angle);
void stopMovement();
void moveStraight(int velocity);
void turnArc(boolean leftArc, float outerRadius,float outerSpeed, float amountDegrees);
int cmToTicks(float cmDistance);
void bmdMotors();
void lowerArm();
void raiseArm();
void lowNeutralArm();
void highNeutralArm();
void sweepNeutralArm();
void neutralArm();
void neutralArmSlow();
void moveServoPosition();
void clawOpen();
void clawClose();
void lookForColor(int colorModel, int speed, int numBlobSightings,  float distOut, int cmBackup);

#endif
