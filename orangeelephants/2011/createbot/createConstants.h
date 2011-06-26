#ifndef _CREATECONSTANTS_H_
#define _CREATECONSTANTS_H_

//Constant for deceleration distance in the moveToDistance function
const double  STOP_DISTANCE_RATIO = 0.6; //ratio of speed

//light sensor
const int LIGHT_PORT_A = 1;
const int LIGHT_PORT_B = 0;

//Velocities to move the claw up and down the forklift
const int  ARM_DOWN_VELOCITY = -400; //needs callibration
const int  ARM_UP_VELOCITY = 750; //needs callibration

//Motor, Sensor, & Servo ports
const int  HOPPER = 0;
const int  SLIDER_BACK = 3;
const int  SLIDER_FRONT = 0;

//speed
const int FAST_SPEED = 1500;
const int NORMAL_SPEED = 500;

//hopper positions
const int  HOPPER_CLOSE = 1850;

//vision constants
const int MIN_CONFIDENCE = 10;
const int X_MAX = 159;
const int MIN_BLOB_AREA = 1500;

#endif
