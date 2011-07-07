#ifndef legobotConstants_h
#define legobotConstants_h

/*Left and right positions are 
from looking from the back*/

//Sensor Ports
const int LIGHT_SENS = 0;

//Motor ports
const int L_MOTOR = 3;
const int R_MOTOR = 0;

//Servo ports
const int ARM_PORT = 0;
const int CLAW_PORT = 2;

//Speeds
const int ARM_INCR = 3; //increments used for while loops
const int CLAW_INCR = 6;

//Distances
const float TICKS_PER_CM = 58;

//Positions
const int ARM_VERT = 400;
const int ARM_HORIZONTAL = 1200;
//const int ARM_INTERMEDIATE = 550;
const int CLAW_OPEN = 1800;
const int CLAW_CLOSE = 1200;

//misc
const float TICKS_PER_REV = 4373.10; //( 3.14159* 2 * 12 <- dist btw center of two wheels ) * TICKS_PER_CM (58) = 4373.10
#endif
