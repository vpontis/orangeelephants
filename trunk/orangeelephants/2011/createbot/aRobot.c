#include "createFunctions.c"
#include "createMotor.c"

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
			
			moveToDist(270, 200);
			smoothTurn(-90, 200);
			moveToDist(730, 400);
			smoothTurn(-90, 200);
			
			moveClaw(ARM_POS_DOWN);
			
			moveToDist(100, 100);
			setClaw(0);
			moveToDist(-210, 100);
			
			setClaw(400);
			moveToDist(100, 100);

			setClaw(0);
			
			moveClaw(ARM_POS_START+1000);//picked up blocks
			
			moveToDist(-240, 200);
			turn(80, 200);
			
			moveToDist(200, 400);
			moveToDist(-50, 100);
			turn(74, 200);
			
			moveToDist(530, 300);
			moveToDist(-240, 200);
			
			moveClaw(ARM_POS_START);
			setClaw(800);
			moveToDist(-680, 300);
						
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
			
			smoothTurn(80, 200);
			sleep(2);
			smoothTurn(-80, 200);
			
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
