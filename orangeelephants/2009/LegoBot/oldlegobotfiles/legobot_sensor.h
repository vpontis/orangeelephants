/**
legobot_sensor.h
Created 1/27/09
Mark Allen Vismonte
Header file associated with legobot_sensor.c
*/

#ifndef legobot_motor
#define legobot_motor

#include "boolean.h"

int readAnalog(int port);

int getRightIRSensor(void);

int getLeftIRSensor(void);

boolean onBlackLine(boolean leftIR);

boolean bothOnBlackLine(void);

#endif
