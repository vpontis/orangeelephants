#ifndef _CREATECONSTANTS_H_
#define _CREATECONSTANTS_H_

//Constant for deceleration distance in the moveToDistance function
const double  STOP_DISTANCE_RATIO = 0.6; //ratio of speed

//light sensor
//const int LIGHT_PORT_A = 1;
//const int LIGHT_PORT_B = 0;

//Velocities to move the arm with claw up and down
const int ARM_VELOCITY = 400; //callibrate this value
//const int  ARM_DOWN_VELOCITY = -400; //needs callibration
//const int  ARM_UP_VELOCITY = 750; //needs callibration

//Up/down positions for the claw on the forklift 
//Top is 0 and as you descend the position is negative
const int  ARM_POS_DOWN = -4000;
const int  ARM_POS_START = 0;//up down position for the claw to start

//Opening/closing positions of the claw
/* const int  CLAW_OPEN_START = 1000;
const int  CLAW_OPEN_POS = 800;
const int  CLAW_OPEN_PARTIAL = 350;
const int  CLAW_CLOSE_POS = 0; */

//Motor, Sensor, & Servo ports
const int  ARM_MOTOR_PORT = 1; 

//speed
const int FAST_SPEED = 1500;
const int NORMAL_SPEED = 500;

#endif
