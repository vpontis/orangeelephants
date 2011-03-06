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
	if(distance>0)	{
		while(get_motor_position_counter(R_MOTOR) < cmToTicks(distance))	{
			mav(L_MOTOR, speed); 
			mav(R_MOTOR, speed);
			//mrp(R_MOTOR, speed, cmToTicks(distance));    
		}
	}
	else	{
		while(get_motor_position_counter(R_MOTOR) > cmToTicks(distance))	{
			mav(L_MOTOR, -speed); 
			mav(R_MOTOR, -speed);
			//mrp(R_MOTOR, speed, cmToTicks(distance));    
		}
	}
    //bmdMotors();
	mav(L_MOTOR, 0);
	mav(R_MOTOR, 0);
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
        return (float) (cmDistance * TICKS_PER_CM);        
}

void bmdMotors() {                                 //wait until driving motors finish moving
        bmd(L_MOTOR);
        bmd(R_MOTOR);   
}

void lowerBlockerLeft(){		
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


void setStartingBlockers() {         //angle the blockers to fit in the starting box
	set_servo_position(0,930);       //angled value
	mrp(L_BLOCKER_MOTOR,260,165);    //angled value
}

void raiseBlockers(){            //raise higher AFTER leaving the starting box
	set_servo_position(0,775);       //move to highest angle possible
	mrp(L_BLOCKER_MOTOR, 260, 25);   //move to highest angle possible
}

void calibrateGate()                 //open or close the gate holding the biofuels (ping-pong balls)
{
	printf("Press up to open, down to close, black button to finish -- move it to the perpendicular position");
	while (1) 
	{
		if (up_button() == 1) {
			 mrp(GATE_MOTOR,200,-20);
		}
		if(down_button() == 1) {
			mrp(GATE_MOTOR,200,20);
		}
		if(black_button() == 1) {
			break;
		}
	}
	//mrp(GATE_MOTOR, GATE_MOTOR_SPEED,-400);
}

void gateOpen() 
{
	mrp(GATE_MOTOR, GATE_MOTOR_SPEED, GATE_OPEN_POS);
	bmd(GATE_MOTOR);
}

void gateClose()
{
	mrp(GATE_MOTOR, GATE_MOTOR_SPEED, -GATE_OPEN_POS);
	bmd(GATE_MOTOR);
}

//        axle is 13.75 cm

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
        -param True if going left, false if going right
        -param outerRadius Sets outer radius of the arc in centimeters
        -param outerSpeed Speed of outside wheel between 0-1000
        -param amountDegrees Tells the robot how much of the circle to turn in degrees
*/


void turnArc(boolean leftArc, float outerRadius, float outerSpeed, float amountDegrees) 
{
    float ratio = (outerRadius - LEGOBOT_DIAMETER)/(outerRadius);
	float outerCircumference = 2 * PI * outerRadius * (0.073343)*1.3;
    float innerCircumference = outerCircumference * ratio;
    float innerSpeed = outerSpeed * ratio; 
	if(leftArc)
	{
           mrp(L_MOTOR, innerSpeed, innerCircumference*TICKS_PER_REV*(amountDegrees/360.0)); //1020.4 is ticks per rev
           mrp(R_MOTOR, outerSpeed, outerCircumference*TICKS_PER_REV*(amountDegrees/360.0));
	}
    else
    {
           mrp(R_MOTOR, innerSpeed, innerCircumference*TICKS_PER_REV*(amountDegrees/360.0));
           mrp(L_MOTOR, outerSpeed, outerCircumference*TICKS_PER_REV*(amountDegrees/360.0));
    }
    bmdMotors();
}
//Inner: 3+, 4.5

//////Marked for Deletion
/*  diameter of a wheel = 4.32
	circumference = pi * 4.32 = 13.571
	length of whole rotation with one wheel at center = 3.14159* 2 * 13.75 <- dist btw center of two wheels
	revs/circle = 6.33 */

void pivot(boolean aroundLeftWheel, float degrees, int speed) 
{
	int ticks = degrees /360 * 6646.166464987; // fraction of circle's circumference / ticks for a whole circle
											   // 1 circle = circle with radius distance between middle of the wheels
	if(aroundLeftWheel == 1) {
		mrp(R_MOTOR, speed, ticks);
		bmd(0);
	}
	else {
		mrp(L_MOTOR, speed, ticks);
		bmd(3);
	}
}	
//6.366 = revs per big circle



