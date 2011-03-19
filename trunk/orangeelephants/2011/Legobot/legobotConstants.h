#ifndef legobotConstants_h
#define legobotConstants_h

/*Left and right positions are 
from looking from the back*/

//Sensor Ports
const int LIGHT_PORT = 0;

//Motor ports
const int L_MOTOR = 3;
const int R_MOTOR = 2;
const int L_BLOCKER_MOTOR = 1;
const int GATE_MOTOR = 0;

//Servo ports
const int R_BLOCKER_SERVO = 0;
 
//Speeds
const int FAST_SPEED = 900;
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
const int GATE_OPEN_POS = -700; 

//Distances
const float TICKS_PER_REV = 1020.4;
const float TICKS_PER_DEGREE = 7.034;


//misc
const float PI = 3.141592654;
const float LEGOBOT_DIAMETER = 13.9; 
const float LEGOBOT_CIRCUMFERENCE = 43.668137835;
const float WHEEL_CIRCUMFERENCE = 17.5929;
const float TICKS_PER_CM = 58;

#endif

// 13.571 = cirumference of wheel
