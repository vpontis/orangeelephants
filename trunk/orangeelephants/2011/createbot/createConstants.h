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

//Up/down positions for the claw on the forklift 
//Top is 0 and as you descend the position is negative
const int  ARM_POS_DOWN = -8050;
const int  ARM_POS_START = -6375;//up down position for the claw to start
const int  ARM_PARTIAL_DOWN  = -600;

//Opening/closing positions of the claw
const int  CLAW_OPEN_START = 1000;
const int  CLAW_OPEN_POS = 800;
const int  CLAW_OPEN_PARTIAL = 350;
const int  CLAW_CLOSE_POS = 0;

//Motor, Sensor, & Servo ports
const int  ARM_MOTOR_PORT = 0; 
const int  CLAW_PORT = 2; 
const int  ARM_TOUCH_PORT = 15;
const int  GRABBER_PORT = 0;
const int SCRAPERL_SERVO = 1; 
const int SCRAPERR_SERVO = 3;

//speed
const int FAST_SPEED = 1500;
const int NORMAL_SPEED = 500;

//positions at the start of game for scraper
const int SCRAPERL_START = 0; 
const int SCRAPERR_START = 1750; 

//neutral positions for scraper during game
const int SCRALERL_NEUTRAL = 920; 
const int SCRAPERR_NEUTRAL = 850; 

//positions for scraper when going for botguy
const int SCRAPERL_DOWN = 1900;
const int SCRAPERR_DOWN = 0;

//positions for grabber
const int GRABBER_UP = 1400;
const int GRABBER_DOWN = 750;

#endif
