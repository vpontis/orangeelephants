#ifndef _CREATEFUNCTIONS_H_
#define _CREATEFUNCTIONS_H_
void createInitialize();

void moveClawUp();
void moveClawDown(int nDistance);
void pickUpDropOff();
void slowReleaseClaw();
void slowCloseClaw();
void pickUpBlocks();

void moveArm(int position, int speed);
void setClaw(int position);

void openClaw();
void closeClaw();

void scraperStart();
void scraperNeutral();
void scraperDown();


#endif
