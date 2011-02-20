#ifndef legobotFunctions_h
#define legobotFunctions_h

void moveToDistance(float distance, int speed);   //move to distance distance and at speed speed
float cmToTicks(float cmDistance);                 // number of ticks in that distance

void bmdMotors();     							// make sure motors finish turning 
void lowerBlockerLeft();                           // lower left blocker and move forward -- left viewed from the back
void lowerBlockerRight();                          //lower right blocker and move forward -- right viewed from the back

#endif
