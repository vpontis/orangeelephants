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
	scraperStart();
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

void openClawPartial() {
	setClaw(CLAW_OPEN_PARTIAL);
}

void closeClaw(){
	setClaw(CLAW_CLOSE_POS);
}

void scraperStart(){
	set_servo_position(SCRAPERL_SERVO, SCRAPERL_START);
	set_servo_position(SCRAPERR_SERVO, SCRAPERR_START);
}

void scraperNeutral(){
	set_servo_position(SCRAPERL_SERVO, SCRALERL_NEUTRAL);
	set_servo_position(SCRAPERR_SERVO, SCRAPERR_NEUTRAL);
}

void scraperDown(){
	set_servo_position(SCRAPERL_SERVO, SCRAPERL_DOWN);
	set_servo_position(SCRAPERR_SERVO, SCRAPERR_DOWN);
}
