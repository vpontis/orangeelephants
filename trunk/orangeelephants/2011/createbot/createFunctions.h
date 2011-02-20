#ifndef _CREATEFUNCTIONS_H_
#define _CREATEFUNCTIONS_H_

void accel(int initSpeed, int finalSpeed);
void createDrive(int finalSpeed);
void createInitialize();
void moveToDistance(int distance, int speed);
void moveToDistanceAccel(int distance, int initSpeed, int finalSpeed);
void moveClawUp();
void moveClawDown(int nDistance);
void pickUpDropOff();
void slowReleaseClaw();
void slowCloseClaw();
void pickUpBlocks();

void moveClaw(int position);

void setClaw(int position);


void turn(float deg, int vel);
void accelTurn(float deg, int vel);

void moveToShort(int distance, int speed);




#endif
