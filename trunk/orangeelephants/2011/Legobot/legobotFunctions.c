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
			mav(L_MOTOR, speed);
			mav(R_MOTOR, speed);
			sleep(time);
		}
	}
	else//if you are decelerating
	{
		while(speed>finalSpeed)
		{
			speed += increm; 
			mav(L_MOTOR, speed);
			mav(R_MOTOR, speed);
			sleep(time);
		}
	}
	
	mav(L_MOTOR, finalSpeed);
	mav(R_MOTOR, finalSpeed);
	
}


void moveToDistance(float distance, int speed) {
	mrp(0, speed, cmToTicks(distance)); //left wheel
	mrp(3, speed, cmToTicks(distance)); //right wheel
	bmdMotors();
}

float cmToTicks(float cmDistance) {                // return ticks the motors need to turn to go that distance
	return (float) (cmDistance * TICK_PER_CM);        
}

void bmdMotors() {     //wait until driving motors finish moving
	bmd(L_MOTOR);
	bmd(R_MOTOR);	
}

void lowerBlockerLeft(){ //lower left blocker and move forward 20 cm (subject to change)
	set_servo_position(2,1100);
	sleep(1);
	moveToDistance(20,200);
	sleep(1);
	//when blocker is vertical: position 1800 
	//when blocker hits the ground and is horizontal: position 650 
}

void lowerBlockerRight(){ //lower right blocker and move forward 20 cm (subject to change)
	set_servo_position(0,650);
	sleep(1);
	moveToDistance(20,200);
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
	860.76							CAUSED A 90 DEG TURN
	
	/*************** 9.564 ticks per degree **************
				LEFT/RIGHT FROM THE BACK OF THE ROBOT   */			
void turn(int speed, int degree){
	
	int ticks = degree*9.564;
	//right turn
	if(degree > 0){
		while(1){
			mav(R_MOTOR,speed);
			mav(L_MOTOR,-speed);
			
			if(get_motor_position_counter(3) >= ticks){
				clear_motor_position_counter(3);
				clear_motor_position_counter(0);
				mav(R_MOTOR,0);
				mav(L_MOTOR,0);
				break;
			}
		}
	}
	
	//left turn
	if(degree < 0){
		while(1){
			mav(L_MOTOR,speed);
			mav(R_MOTOR,-speed);
			//neg. ticks so that the motor_position remains positive
			if(get_motor_position_counter(0) >= -ticks){
				clear_motor_position_counter(3);
				clear_motor_position_counter(0);
				mav(L_MOTOR,0);
				mav(R_MOTOR,0);
				break;
			}
		}
	}	
}

