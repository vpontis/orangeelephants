#ifndef legobotFunctions_h
#define legobotFunctions_h

void moveToDist(float distance, int speed); 
float cmToTicks(float cmDistance);

void raiseArm();
void lowerArm();
void interArm();
void openClaw();
void closeClaw();


#endif

