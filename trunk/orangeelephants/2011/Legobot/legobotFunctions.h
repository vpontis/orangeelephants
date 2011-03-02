#ifndef legobotFunctions_h
#define legobotFunctions_h
#include "boolean.h"

void moveToDistance(float distance, int speed);    //move to distance distance and at speed speed
void legobotAccel(int initSpeed,int finalSpeed);
void moveStraight(int speed);

float cmToTicks(float cmDistance);                 // number of ticks in that distance

void stopMotors(); 
void bmdMotors();                                  // make sure motors finish turning 

void setStartingBlockers();
void lowerBlockerLeft();                           //lower left blocker and move forward -- left viewed from the back
void lowerBlockerRight();                          //lower right blocker and move forward -- right viewed from the back
void raiseBlockersVertical();

void moveGate(int speed); 

void turn(int degree, int speed); 
void turnArc(boolean leftArc, float outerRadius,float outerSpeed, float amountDegrees);
void pivot(boolean aroundLeftWheel, float degrees, int speed);

#endif

