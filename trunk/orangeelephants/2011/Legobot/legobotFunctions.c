#include "legobotConstants.h"
#include "legobotFunctions.h"
#include "boolean.h"
// *******************USE CENTIMETERS*********************
// **************Blockers start on ground, then call setStartingBlockers() ************************

void legobotAccel(int initSpeed,int finalSpeed){
        
        int increm = (finalSpeed-initSpeed)/20;
        int speed = initSpeed;
        
        float time = abs((finalSpeed-initSpeed)/2500);  //delay is .1 sec for accel from 0-500
        
        if(speed<finalSpeed)		//if you are accelerating
        {
                while(speed<finalSpeed)
                {
                        speed = speed+increm; 
                        moveStraight(speed); 
                        sleep(time);
     
			}
		}		
        else				//if you are decelerating
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
        mrp(L_MOTOR, speed, cmToTicks(distance));    //left wheel
        mrp(R_MOTOR, speed, cmToTicks(distance));    //right wheel
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

void bmdMotors() {                                 //wait until driving motors finish moving
        bmd(L_MOTOR);
        bmd(R_MOTOR);   
}

		

void lowerBlockerLeft(){		//lower left blocker and move forward 20 cm (subject to change)
        //for the left motor
        //requires callibration of motors in beginning
        clear_motor_position_counter(L_BLOCKER_MOTOR);
        mrp(L_BLOCKER_MOTOR, L_BLOCKER_MOTOR_SPEED, L_BLOCKER_MOTOR_DISTANCE);
        sleep(1);
        off(L_BLOCKER_MOTOR);
}

void lowerBlockerRight(){		//lower right blocker and move forward 20 cm (subject to change)
        set_servo_position(0,R_BLOCKER_SERVO_POSITION);
        sleep(1);
        //when blocker is vertical: position 50
        //when blocker hits the ground and is horizontal: position 1100
}



void setStartingBlockers() {             //angle the blockers to fit in the starting box
	set_servo_position(0,930);       //angled value; vertical value = 510
	mrp(L_BLOCKER_MOTOR,160,160);    //angled value; vertical value = 270
}

void raiseBlockersVertical(){            //raise to vertical AFTER leaving the starting box
	set_servo_position(0,510);       //move to vertical
	mrp(L_BLOCKER_MOTOR, 160,110);   //move to vertical from angled
}

void moveGate(int speed)                 //open or close the gate holding the biofuels (ping-pong balls)
{
	if (speed>0)	
		mrp(GATE_MOTOR, speed, GATE_DOWN_POS); 
	else
		mrp(GATE_MOTOR, speed, -GATE_DOWN_POS);
	
	bmd(GATE_MOTOR); 
}


/*Turns the Legobot a certain degree, a negative degree will result in a left turn
  while a positive degree will result in a right turn.
  The turn also pivots the robot.
  
        axle is 13.75 cm
        3.14159c * 2 * 13.75 = circumference
        1/4 of circumference = 21.60
        21.60 * 79.7ticks = 1721.52    		 CAUSED A 180 DEG TURN
     			    860.76               CAUSED A 90 DEG TURN
        
        /*************** 9.564 ticks per degree **************
                                LEFT/RIGHT FROM THE BACK OF THE ROBOT   */                      

void turn(int degree, int speed){ 
    clear_motor_position_counter(L_MOTOR); 
    clear_motor_position_counter(R_MOTOR); 
    int ticks = degree*TICKS_PER_DEGREE; 
    //ticks is negative if the degree is negative (makes a left turn)
    //otherwise, ticks is positive and makes a right turn
    //in other words, you don't need an if/else statement here
    mrp(R_MOTOR,speed,-ticks);
    mrp(L_MOTOR,speed,ticks);
    bmdMotors();
}


/*
        -brief Turns legobot in an arc using the mrp command
        -param leftArc True if going left, false if going right
        -param outerRadius Sets outer radius of the arc in centimeters
        -param outerSpeed Speed of outside wheel between 0-1000
        -param amountDegrees Tells the robot how much of the circle to turn in degrees
*/

void turnArc(boolean leftArc, float outerRadius,float outerSpeed, float amountDegrees) 
{
        float ratio = (outerRadius - AXLE_LENGTH/10)/(outerRadius);
        float outerCircumference = 2 * PI * outerRadius * (1/13.57);
        float innerCircumference = outerCircumference * ratio;
        float innerSpeed = outerSpeed * ratio; 
	if(leftArc)
	{
                mrp(L_MOTOR, innerSpeed, innerCircumference*1020.4*(amountDegrees/360.0)); //1020.4 is ticks per rev
                mrp(R_MOTOR, outerSpeed, outerCircumference*1020.4*(amountDegrees/360.0));
        }
        else
        {
                mrp(R_MOTOR, innerSpeed, innerCircumference*1020.4*(amountDegrees/360.0));
                mrp(L_MOTOR, outerSpeed, outerCircumference*1020.4*(amountDegrees/360.0));
        }
        bmdMotors();
}
