#include "createFunctions.h"
#include "createConstants.h"



void createInitialize()
{
	int conVal = create_connect();
	if(conVal == 0){
		printf("Connection success. Setting to full mode...");
	}
	else{
		printf("Connection failed.");
	}
	create_full();
}



//Moves the claw to pinch the blocks up until it hits the sensor
void moveArmUp(){
	
	mav(ARM_MOTOR_PORT, ARM_UP_VELOCITY);
	while (digital(ARM_TOUCH_PORT) == 0) //keep moving up until the touch sensor is triggered
	{
		sleep(0.1);
	}
	mav(ARM_MOTOR_PORT,0);
	clear_motor_position_counter(0);
}


void moveArm(int position, int speed)	{
	
	mtp(ARM_MOTOR_PORT, speed, position);
	bmd(ARM_MOTOR_PORT);
}


void slowReleaseClaw()
{	
	int clawPos = get_servo_position(CLAW_PORT); 
	int clawPosIncrement = CLAW_OPEN_POS/50; 
	
	while (clawPos < (CLAW_OPEN_POS - clawPosIncrement)) {//to prevent the claw from going too far
		set_servo_position(CLAW_PORT, clawPos); 
		clawPos += clawPosIncrement; 
		sleep(.1); 
	}
	
	set_servo_position(CLAW_PORT, CLAW_OPEN_POS);
}

void slowCloseClaw()
{	
	int clawPos = get_servo_position(CLAW_PORT); 
	int clawPosIncrement = clawPos/20; 
	
	while (clawPos >= clawPosIncrement) {//so to stop it from giving a negative servo value
		set_servo_position(CLAW_PORT, clawPos); 
		clawPos -= clawPosIncrement; 
		sleep(.1); 
	}
	set_servo_position(CLAW_PORT, 0);
}

void setClaw(int position)
{		
	int currPos = get_servo_position(CLAW_PORT);
	printf("Init servo position is %d.\n", currPos);
	int numIncrements = 10;
	int increment = abs(position-currPos)/numIncrements;
	printf("The increment is %d.\n", increment);
	
	int counter = 1;
	
	if(position < currPos)	{//to close the claw
		while(counter <= numIncrements)	{
			currPos-=increment;
			set_servo_position(CLAW_PORT, currPos);
			sleep(.1);
			counter += 1;
		}
	}
	else if(position > currPos)	{//to open the claw
		while( counter <= numIncrements){
			currPos += increment;
			set_servo_position(CLAW_PORT, currPos);
			sleep(.1);
			counter += 1;
		}
	}
	
	set_servo_position(CLAW_PORT, position);

	printf("Final servo position is %d.\n", get_servo_position(CLAW_PORT));
}

void pickUpBlocks()
{
	slowCloseClaw();
	moveArmUp();
}

void openClaw()	{
	setClaw(CLAW_OPEN_POS);
}

void closeClaw()	{
	setClaw(CLAW_CLOSE_POS);
}

/*
//picks up two blocks and lifts them to a height of two blocks then lets them go and puts the claw back down
void stackBlocks() { 
	
	set_servo_position(CLAW_PORT,CLAW_OPEN_POS); //790 = default value to clench
	sleep(.5);  //pause before clench 
	
	
	slowCloseClaw();
	sleep(1); //pause in between moving and clench
	
	moveClawUp();
	moveClawDown(ARM_PARTIAL_DOWN);
	
	sleep(1); 
	slowReleaseClaw();
	sleep(1); 
	
	moveClawDown(ARM_POS_DOWN - ARM_PARTIAL_DOWN); //Test this value. needs to go all the awy down. 
}
*/
