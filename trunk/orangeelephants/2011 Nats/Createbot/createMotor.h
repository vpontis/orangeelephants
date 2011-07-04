#ifndef _CREATEMOTOR_H_
#define _CREATEMOTOR_H_

void accel(int initSpeed, int finalSpeed);
void createDrive(int finalSpeed);

void moveToDist(int distance, int speed);
void moveToDistanceAccel(int distance, int finalSpeed);
void moveToVictor(int distance, int speed);

void turn(int degrees);
void smoothTurn(float deg, int finalVel);
void moveStraight(int speed);
void createStop();
void createCenter(int ch, int speed);
void createMove(int vel, float time); //distance function based on time


#endif
