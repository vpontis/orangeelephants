#include "legobotConstants.h"
#include "legobotFunctions.h"
// *******************USE CENTIMETERS*********************

void legobotAccel(int initSpeed,int finalSpeed){
        
        int increm = (finalSpeed-initSpeed)/20;
        int speed = initSpeed;
        
        float time = abs((finalSpeed-initSpeed)/2500);//delay is .1 sec for accel from 0-500
        
        if(speed<finalSpeed)//if you are accelerating
        {
                while(speed<finalSpeed)
                {
                        speed = speed+increm; 
                        moveStraight(speed); 
                        sleep(time);
                }
        }
        else//if you are decelerating
        {
                while(speed>finalSpeed)
                {
                        speed += increm; 
                        moveStraight(speed); 
                        sleep(time);
                }
        }
        
        mav(L_MOTOR, finalSpeed);
        mav(R_MOTOR, finalSpeed);
        
}


void moveToDistance(float distance, int speed) {
		clear_motor_position_counter(L_MOTOR); 
		clear_motor_position_counter(R_MOTOR); 
        mrp(L_MOTOR, speed, cmToTicks(distance)); //left wheel
        mrp(R_MOTOR, speed, cmToTicks(distance)); //right wheel
        bmdMotors();
}

void moveStraight(int speed)
{
	mav(L_MOTOR, speed); 
	mav(R_MOTOR, speed); 
}

void stopMotors()
{
	mav(L_MOTOR, 0); 
	mav(R_MOTOR, 0); 
}

float cmToTicks(float cmDistance) {                // return ticks the motors need to turn to go that distance
        return (float) (cmDistance * TICK_PER_CM);        
}

void bmdMotors() {     //wait until driving motors finish moving
        bmd(L_MOTOR);
        bmd(R_MOTOR);   
}

//void moveBlockersVertical() { //for now left only
		

void lowerBlockerLeft(){ //lower left blocker and move forward 20 cm (subject to change)
        //for the left motor
        //requires callibration of motors in beginning
        clear_motor_position_counter(L_BLOCKER_MOTOR);
        mrp(L_BLOCKER_MOTOR, L_BLOCKER_MOTOR_SPEED, L_BLOCKER_MOTOR_DISTANCE);
        sleep(1);
        off(L_BLOCKER_MOTOR);
}

void lowerBlockerRight(){ //lower right blocker and move forward 20 cm (subject to change)
        set_servo_position(0,R_BLOCKER_SERVO_POSITION);
        sleep(1);
        //when blocker is vertical: position 50
        //when blocker hits the ground and is horizontal: position 1100
}
/*Turns the Legobot a certain degree, a negative degree will result in a left turn
  while a positive degree will result in a right turn.
  The turn also pivots the robot.
  
        axle is 13.75 cm
        3.14159c * 2 * 13.75 = circumference
        1/4 of circumference = 21.60
        21.60 * 79.7ticks = 1721.52     CAUSED A 180 DEG TURN
        860.76                                                  CAUSED A 90 DEG TURN
        
        /*************** 9.564 ticks per degree **************
                                LEFT/RIGHT FROM THE BACK OF THE ROBOT   */                      
void turn(int speed, int degree){
	clear_motor_position_counter(L_MOTOR); 
	clear_motor_position_counter(R_MOTOR); 
    int ticks = degree*TICKS_PER_DEGREE;
	
    //right turn
    if(degree > 0){
		mrp(L_MOTOR,speed,ticks); 
		mrp(R_MOTOR,-speed,ticks); 
		bmdMotors(); 
	}  
        //left turn
	else if(degree < 0){
		mrp(R_MOTOR,speed,ticks); 
		mrp(L_MOTOR,-speed,ticks); 
		bmdMotors(); 
	}       
}

void moveGate(int speed)
{
	if (speed>0)	
		mrp(GATE_MOTOR, speed, GATE_DOWN_POS); 
	else
		mrp(GATE_MOTOR, speed, 0);
	
	bmd(GATE_MOTOR); 
}

