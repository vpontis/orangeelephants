#ifndef legobotFunctions_h
#define legobotFunctions_h

void moveToDist(float distance, int speed); 
float cmToTicks(float cmDistance);

//void raiseArm();
//void lowerArm();
void moveArm();
void openClaw();
void closeClaw();
void pivot(int aroundLeftWheel, float degrees, int speed);
void moveStraight(int speed	);

#endif

