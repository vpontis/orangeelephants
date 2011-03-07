#ifndef _CREATEMOTOR_H_
#define _CREATEMOTOR_H_

void accel(int initSpeed, int finalSpeed);
void modAccel(int distance, int highSpeed);
void createDrive(int finalSpeed);

void moveToDist(int distance, int speed);
void moveToDistAccel(int distance, int finalSpeed);

void turn(float deg, int vel);
void smoothTurn(float deg, int finalVel);


#endif
