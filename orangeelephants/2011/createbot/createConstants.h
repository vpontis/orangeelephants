#ifndef _CREATECONSTANTS_H_
#define _CREATECONSTANTS_H_

const double  STOP_DISTANCE_RATIO = 0.4; //needs callibration

const int  ARM_DOWN_VELOCITY = -400; //needs callibration
const int  ARM_UP_VELOCITY = 750; //needs callibration


const int  CLAW_OPEN_POS = 700; 
const int  CLAW_TOTAL_OPEN = 1200;

const int  ARM_POS_DOWN = -8500;
const int  ARM_POS_START = -6375;//up down position for the claw to start
const int  ARM_PARTIAL_DOWN  = -600;

//motor & Ssensor ports
const int  ARM_MOTOR_PORT = 0; 
const int  CLAW_PORT = 2; 
const int  ARM_TOUCH_PORT = 15;



#endif
