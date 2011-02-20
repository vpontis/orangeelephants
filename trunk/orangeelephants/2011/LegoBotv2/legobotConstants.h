#ifndef legobotConstants_h
#define legobotConstants_h

/*Left and right positions are 
from looking from the back*/

//Motor ports
const int L_MOTOR = 0;
const int R_MOTOR = 3;
const int L_BLOCKER_MOTOR = 2;
const int GATE_MOTOR = 1;

//Servo ports
const int R_BLOCKER_SERVO = 0;
 

//Blocker speed(motor) and position(servo)
const int L_BLOCKER_MOTOR_SPEED = 100; //motor
const int R_BLOCKER_SERVO_POSITION = 1575; //servo

//Distances
const float TICK_PER_CM = 79.7;
const int L_BLOCKER_MOTOR_DISTANCE = -280;
const int L_BLOCKER_MOTOR_START = -170; 
const int GATE_DOWN_POS = 2750; 
const float TICKS_PER_DEGREE = 9.564; 

#endif