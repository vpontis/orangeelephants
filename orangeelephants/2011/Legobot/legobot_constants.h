#ifndef legobot_constants_h
#define legobot_constants_h

;

//Sensor Ports 
const int RIGHT_TOUCH_PORT = 8; //digital senor
const int LEFT_TOUCH_PORT = 9; //digital sensor
const int LIGHT_SENSOR_PORT = 0; //port of light sensor
const int ARM_SENSOR_PORT = 15; //port for arm touch sensor

//Motor ports
const int ARM_MOTOR = 0;
const int L_MOTOR = 2;
const int R_MOTOR = 3;
const int CLAW_SERVO = 2;

//arm tilting constants
const int ARM_UP = 3050;
const int ARM_NEUTRAL = 500; 
const int ARM_HIGH_NEUTRAL = -500;
const int ARM_DUCK_GRAB = -2500;
const int ARM_DOWN = -3000; 

#endif
