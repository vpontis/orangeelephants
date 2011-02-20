
//motor port constants for CBC v2

const int RIGHT_TOUCH_PORT = 8; //digital senor
const int LEFT_TOUCH_PORT = 9; //digital sensor
const int LIGHT_SENSOR_PORT = 0; //port of light sensor
const int ARM_SENSOR_PORT = 10; //port for arm touch sensor


//motor port constants for CBC v1
/*
const int RIGHT_TOUCH_PORT = 0; //digital senor
const int LEFT_TOUCH_PORT = 1; //digital sensor
const int LIGHT_SENSOR_PORT = 8; //port of light sensor
const int ARM_SENSOR_PORT = 2; //port for arm touch sensor
*/
//wheel driving constants

const int NORMAL_SPEED = 520;
const int FAST_SPEED = 750;
/*
const int NORMAL_SPEED = 750;
const int FAST_SPEED = 980;
*/
//const int MODIFIER = 3100;


#define MOTOR_OFFSET -3050
//arm tilting constants
const int ARM_UP = 3050;//Old value 3050
const int ARM_DOWN = -3000; //-5600
const int ARM_LOW_NEUTRAL = -2500; //-4600
const int ARM_HIGH_NEUTRAL = -500;
const int ARM_NEUTRAL = 500; //-3600
const int TILT_SPEED = 1000;
const int ARM_SWEEP_NEUTRAL = -1250;
const int ARM_ISLAND_SWEEP = 2835;//Old  ,2135 ,2020, 2060, 1560, 1410
//const int MODIFIER = 3100; //offset; corresponds to initial position

