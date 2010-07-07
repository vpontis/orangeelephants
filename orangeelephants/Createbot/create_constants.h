#ifndef _CREATE_CONSTANTS_H_
#define _CREATE_CONSTANTS_H_

//servo port numbers 
const int DOZERL_SERVO = 0;
const int DOZERR_SERVO = 2;

//motor port numbers
const int ARM_MOTOR = 0; 

//servo consts

const int DOZERL_HIGH_SCRAPE = 1050;
const int DOZERR_HIGH_SCRAPE = 950;

const int DOZERL_TIMEOUT = 1200;
const int DOZERR_TIMEOUT = 800;

const int DOZERL_DOWN = 1024;
const int DOZERR_DOWN = 1024;

const int DOZERL_NEUTRAL = 1500;
const int DOZERR_NEUTRAL = 500; 

const int DOZERL_UP = 2000;
const int DOZERR_UP = 0; 

const int DOZERL_SCRAPE = 999; //1024-25
const int DOZERR_SCRAPE = 1049; //1024+25



//motor consts, positive is low & negative is high
const int ARM_UP = -1800;//-800,-437 
const int ARM_SCRAPE = -425; 
const int ARM_UPPEST= -1600;//-1600
const int ARM_OFFSET = -475;//-1239, -1439, -1300, -1100, -800, -525

//sensor ports
const int LIGHT_SENSOR_PORT=0;

//speeds
const int NORM_SPEED = 250;
const int SLOW_SPEED = 150;

//arm speeds
const int ARM_FAST_SPEED = 500;
const int ARM_NORMAL_SPEED = 425;//350
const int ARM_SLOW_SPEED = 200;

#endif
