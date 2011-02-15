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
			set_servo_position(CLAW_PORT,400);
			sleep(.5);
			
			moveToDistance(-500, 250);
			
			pickUpBlocks();
			
			sleep(.5);
			turn(170, 100);
			printf("Turn completed.\n");
			
			sleep(.5);	
			moveToDistance(-530, 250);
			printf("Moved back to original blocks. \n");
			
			moveToDistance(130, 100);
			
			moveClawDown(ARM_PARTIAL_DOWN);
			
			slowReleaseClaw();
			printf("Claw opened.\n");
			
			moveToDistance(200, 250);
			printf("Backed away, program done. \n");
		}
		
		if(b_button())
		{
			createInitialize();
			moveToDistance(-100,300);
			accelTurn(180, 300);
			moveToDistance(200, 300);
			accelTurn(-180, 500);
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
