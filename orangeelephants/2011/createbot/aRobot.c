#include "createFunctions.c"

void openClaw(int position);
void closeClaw(int position);

int main()
{
	printf("Press the A to test from runway to pick up blocks.\n");
	printf("Press the up button to calibrate the claw.\n");
	
	createInitialize();
	
	while(1)
	{
		if(a_button())
		{
			enable_servos();
			set_servo_position(CLAW_PORT,950);
			
			moveToDist(-150, 200);
			turn(-73, 200);
			moveToDist(-930, 400);
			turn(-78, 200);
			
			moveClaw(ARM_POS_DOWN);
			
			moveToShort(-50, 100);
			setClaw(0);
			moveToDist(150, 100);
			
			setClaw(400);
			moveToDist(-100, 100);

			setClaw(0);
			
			moveClaw(ARM_POS_START+1000);//picked up blocks
			
			moveToDist(120, 200);
			turn(80, 200);
			
			moveToDist(-850, 400);
			moveToShort(50, 100);
			turn(74, 200);
			
			moveToDist(-350, 300);
			moveToDist(120, 200);
			
			moveClaw(ARM_POS_START);
			setClaw(800);
			moveToDist(500, 300);
						
		}
		
		if(right_button())
		{
			enable_servos();
			printf("Servos enabled.\n");
			sleep(3);
			
			set_servo_position(CLAW_PORT,500);
			printf("Set servo position 500.\n");
			sleep(3);
			
			closeClaw(0);
			printf("Set servo position 0.\n");
			sleep(3);
	
			closeClaw(500);
			printf("Set servo position 500.\n");
			sleep(3);
	
			closeClaw(900);
			printf("Set servo position 900.\n");
			sleep(3);
			
		}
		
		if(b_button())
		{
			sleep(.5);
			moveToDist(50, 200);
			moveClaw(ARM_POS_DOWN+20);
			slowCloseClaw(600);
			moveToDist(90, 200);
			moveToDist(180, 200);
			moveClaw(ARM_POS_START+500);
			turn(-85, 100);
			moveToDist(-50, 200);//align with wall
			moveToDist(1700, 400);
			turn(-80, 200);
			moveToDist(-350, 200);
			set_servo_position(CLAW_PORT,CLAW_OPEN_POS);
			moveToDist(200,200);
		}
				
		if(up_button())//calibrates arm and opens claw
		{
			moveClawUp();
			moveClaw(ARM_POS_START);
					
			enable_servos();
			set_servo_position(CLAW_PORT, 1200);
		}  
	}
}
		
void openClaw(int position)	{
	int currPos = get_servo_position(CLAW_PORT);
	printf("Init servo position is %d.\n", currPos);
	int increment = abs(position-currPos)/10;
	
	int counter = 1;
	
	while( counter <= 10){
		currPos += increment;
		set_servo_position(CLAW_PORT, currPos);
		sleep(.1);
		counter += 1;
	}
	printf("Final servo posit is %d.\n", get_servo_position(CLAW_PORT));
}

void closeClaw(int position)	{
	int currPos = get_servo_position(CLAW_PORT);
	printf("Init servo position is %d.\n", currPos);
	int increment = abs(position-currPos)/10;
	printf("The increment is %d.\n", increment);
	
	int counter = 1;
	
	if(position < currPos)	{//to close the claw
		while(counter <= 10)	{
			currPos-=increment;
			set_servo_position(CLAW_PORT, currPos);
			sleep(.1);
			counter += 1;
		}
	}
	else if(position > currPos)	{//to open the claw
		while( counter <= 10){
			currPos += increment;
			set_servo_position(CLAW_PORT, currPos);
			sleep(.1);
			counter += 1;
		}
	}
	
	set_servo_position(CLAW_PORT, position);

	printf("Final servo posit is %d.\n", get_servo_position(CLAW_PORT));
}

//decel test
/*	int speed=500;
			
			while(speed>0)
			{
				createDrive(speed);
				sleep(.5);
				
				set_create_distance(0);\
				createDrive(0);
				printf("Decel from %d, distance is %d.\n", speed, get_create_distance(.1));
				speed -= 100;
			}*/


/*Stack Blocks
			createInitialize();
			enable_servos();
			set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
			sleep(.5);
			moveToDistanceAccel(-30, -100, -400);
			pickUpBlocks();
			sleep(.5);
			turn(170, 100);
			printf("Turn completed.\n");
			sleep(.5);	
			moveToDistanceAccel(-55, -100, -400);
			moveToDist(-5, 100);
			printf("Moved back to original blocks. \n");
			moveToDist(80, 100);
			moveClawDown(ARM_PARTIAL_DOWN);
			slowReleaseClaw();
			printf("Claw opened.\n");
			moveToDist(200, 250);
			printf("Backed away, program done. \n");
*/
