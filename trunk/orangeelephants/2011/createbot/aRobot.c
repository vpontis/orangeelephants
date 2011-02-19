#include "createFunctions.c"

int main()
{
	printf("Press the A button to test stacking blocks..\n");
	printf("Press the down button to calibrate the claw.\n");
	createInitialize();
	while(1)
	{
		if(a_button())//function to test moveToDistance values
		{			
			int speed = 500;
			while(speed>=100)	{
				set_create_distance(0);
				moveToDistance(700, speed);
				printf("%d  ", get_create_distance(.1)-700);
				
				sleep(1);
				
				set_create_distance(0);
				moveToDistance(-700, speed);
				printf("%d  ", -get_create_distance(.1)-700);
				
				sleep(1);
				speed-=100;
			}			
		
			printf("\n");
			
		}
		
		if(b_button())
		{
			sleep(.5);
			moveToDistance(50, 200);
			moveClaw(ARM_POS_DOWN+20);
			slowCloseClaw(600);
			moveToDistance(90, 200);
			moveToDistance(180, 200);
			moveClaw(ARM_POS_START+500);
			turn(-85, 100);
			moveToDistance(-50, 200);//align with wall
			moveToDistance(1700, 400);
			turn(-80, 200);
			moveToDistance(-350, 200);
			set_servo_position(CLAW_PORT,CLAW_OPEN_POS);
			moveToDistance(200,200);
		}
				
		if(up_button())//calibrates arm and opens claw
		{
			moveClawUp();
			moveClaw(ARM_POS_START);
					
			enable_servos();
			set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
		}  
	}
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
			moveToDistance(-5, 100);
			printf("Moved back to original blocks. \n");
			moveToDistance(80, 100);
			moveClawDown(ARM_PARTIAL_DOWN);
			slowReleaseClaw();
			printf("Claw opened.\n");
			moveToDistance(200, 250);
			printf("Backed away, program done. \n");
*/
