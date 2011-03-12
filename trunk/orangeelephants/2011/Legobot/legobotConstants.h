#ifndef legobotConstants_h
#define legobotConstants_h

/*Left and right positions are 
from looking from the back*/

//Motor ports
const int L_MOTOR = 3;
const int R_MOTOR = 0;
const int L_BLOCKER_MOTOR = 2;
const int GATE_MOTOR = 1;

//Servo ports
const int R_BLOCKER_SERVO = 0;
 
//Speeds
const int FAST_SPEED = 950;
const int MED_SPEED = 700;
const int SLOW_SPEED = 500;
const int SUPER_SPEED = 1000;

//Blocker speed(motor) and position(servo)
const int L_BLOCKER_MOTOR_SPEED = -1000; //motor
const int R_BLOCKER_SERVO_POSITION = 1575; //servo
const int L_BLOCKER_MOTOR_DISTANCE = 175;
const int L_BLOCKER_MOTOR_START = 160;


//Gate
const int GATE_MOTOR_SPEED = 1000;
const int GATE_OPEN_POS = -500; 

//Distances
const float TICKS_PER_REV = 1020.4;
const float TICKS_PER_DEGREE = 8.98; 


//misc
const float PI = 3.141592654;
const float LEGOBOT_DIAMETER = 13.75; 
const float LEGOBOT_CIRCUMFERENCE = 43.196899; 
const float WHEEL_CIRCUMFERENCE = 13.6345;
const float TICKS_PER_CM = 74.8396; 

#endif

// 13.571 = cirumference of wheel


