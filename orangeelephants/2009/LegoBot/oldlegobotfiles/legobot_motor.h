/**
legobot_motor.h
Created 1/27/09
Mark Allen Vismonte
Header file associated with legobot_main.c
*/
#ifndef legobot_motor
#define legobot_motor


#include "boolean.h"//includes the boolean.h file to be able to use booleans

void turn(int degrees, boolean turnRight);

void deployBlockers(void);

void withdrawBlockers(void);

void initMotors(void);

void disableMotors(void);

void moveMotorsAt(int leftVelocity, int rightVelocity);

void moveTogetherAt(int velocity);

void stopMotors(void);

void turnWheel(int servoPosition);

void turnWheelMaxLeft(void);

void turnWheelMaxRight(void);

void turnWheelMiddle(void);

void setBlockerPosition(boolean leftBlocker, int position);

#endif
