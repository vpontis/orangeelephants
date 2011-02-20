#include "createFunctions.c"

int main()
{
	printf("Press the A button to test stacking blocks..\n");
	printf("Press the down button to calibrate the claw.\n");
	createInitialize();
	while(1)
	{
		if(a_button())
		{
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
		}
		
		if(b_button())
		{
			//createInitialize();
			//enable_servos();
			//set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
			createInitialize();
			
			sleep(.5);
			
			//moveToDistance(140, 200);
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
		
		if(right_button())
		{
			set_create_distance(0);
			moveToVictor(800, 400);
			printf("The error in distance is %d.", 800-get_create_distance(.1));
			sleep(2);
			
			set_create_distance(0);
			moveToVictor(-700, 400);
			printf("The error in distance is %d.", -700-get_create_distance(.1));

		}
		
		if(up_button())
		{
			moveClawUp();
			moveClaw(ARM_POS_START);
					
			enable_servos();
			
			sleep(1);
			set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
		}   
		
		if(left_button())
		{
			enable_servos();
			set_servo_position(CLAW_PORT, 820);
			printf("At starting position of 820.\n");
			sleep(2);	
			printf("Now moving to position 120.\n");	
			setClaw(120);
			printf("At position 120.\n");
			sleep(2);
			printf("Now moving to position 500.\n");
			setClaw(600);
			printf("Now at position 500.\n");
			
			moveToDistance(100,100);
			
			sleep(19);
			
			beep();
			beep();
			
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
