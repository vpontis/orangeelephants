#ifndef _CREATEMOTOR_H_
#define _CREATEMOTOR_H_

void accel(int initSpeed, int finalSpeed);
void createDrive(int finalSpeed);

void moveToDistance(int distance, int speed);
void moveToDistanceAccel(int distance, int finalSpeed);
void moveToVictor(int distance, int speed);

void turn(float deg, int vel);
void smoothTurn(float deg, int finalVel);
void moveStraight(int speed);
void createStop();
void createCenter(int ch);


#endif
