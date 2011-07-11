#ifndef _CREATECONSTANTS_H_
#define _CREATECONSTANTS_H_

//Constant for deceleration distance in the moveToDistance function
const double  STOP_DISTANCE_RATIO = 0.6; //ratio of speed
const double  TURN_COMP_RATIO = 1.0; //ratio for turning

//light sensor
const int LIGHT_PORT = 0;

//Velocities to move the claw up and down the forklift
const int  ARM_DOWN_VELOCITY = -400; //needs callibration
const int  ARM_UP_VELOCITY = 750; //needs callibration

//Up/down positions for claw on the arm
const int  ARM_POS_UP = 6300;
const int  ARM_POS_DOWN = 0;
const int  ARM_POS_MID = 5600; 
const int  ARM_POS_LOW = 600;
const int  SUPPORT_POS_DOWN = 1900;
const int  SUPPORT_POS_UP = 650; 

//Opening/closing positions of the claw
const int  CLAWL_OPEN_POS = 1835;
const int  CLAWR_OPEN_POS = 215; 
const int  CLAWR_CLOSE_POS = 1225; 
const int  CLAWL_CLOSE_POS = 790; 

//Motor, Sensor, & Servo ports
const int  ARM_MOTOR_PORT = 1; 
const int  CLAWL_SERVO_PORT = 0; //servo port 1 fried
const int  CLAWR_SERVO_PORT = 3; 
const int  SUPPORT_SERVO_PORT = 2; 
const int  TOUCH_SENSOR_PORT = 14; //digital port 8 fried


//speed
const int FAST_SPEED = 500;
const int NORMAL_SPEED = 400;
const int SLOW_SPEED = 100; 


//vision constants
const int MIN_CONFIDENCE_SHORT = 10;
const int MIN_CONFIDENCE_LONG = 0;
const int X_MAX = 159;
const int MIN_BLOB_AREA = 1500;

//misc 


#endif
