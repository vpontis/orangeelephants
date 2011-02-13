#ifndef _CREATEFUNCTIONS_H_
#define _CREATEFUNCTIONS_H_

void accel(int initSpeed, int finalSpeed);
void createDrive(int finalSpeed);
void createInitialize();
void moveToDistance(int distance, int speed);
void moveClawUp();
void moveClawDown(int nDistance);
void pickUpDropOff();
void slowReleaseClaw();
void slowCloseClaw();
void pickUpBlocks();

void turn(float deg, int vel);



#endif
