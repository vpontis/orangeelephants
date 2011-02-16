#include "createFunctions.c"

int main()
{
	printf("JESSE!!!! Tomorrow is Valentine's Day! ;) <3 <3\n");
	printf("I think you should do something for your fave robot...\n");
	printf("Press the A button to test stacking blocks..\n");
	printf("Press the down button to calibrate the claw.\n");
	while(1)
	{
		if(a_button())
		{
			createInitialize();
			enable_servos();
			set_servo_position(CLAW_PORT,500);
			sleep(.5);
			
			moveToDistanceAccel(-500, 10, 200);
			
			pickUpBlocks();
			
			sleep(.5);
			turn(170, 100);
			printf("Turn completed.\n");
			
			sleep(.5);	
			moveToDistanceAccel(-530, 10, 275);
			printf("Moved back to original blocks. \n");
			
			moveToDistanceAccel(70, 10, 100);
			
			moveClawDown(ARM_PARTIAL_DOWN);
			
			slowReleaseClaw();
			printf("Claw opened.\n");
			
			moveToDistance(200, 250);
			printf("Backed away, program done. \n");
		}
		
		if(b_button())
		{
			createInitialize();
			moveToDistance(50, 300);
			moveToDistanceAccel(600, 100, 400);
			moveToDistanceAccel(-600, 0, 400);
		}
		
		if(down_button())
		{
			moveClawUp();
			moveClawDown(ARM_POS_DOWN);
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
