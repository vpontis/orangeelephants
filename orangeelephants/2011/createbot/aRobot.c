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
			moveToDist(630, 400);
			smoothTurn(-90, 200);
			
			moveArm(ARM_POS_DOWN);
			
			//go in for first grab attempt
			moveToDist(130, 100);
			closeClaw();
			moveToDist(-210, 100);
			openClaw();
			
			moveToDist(60, 100);
			closeClaw();
			
			moveArm(ARM_POS_START+1000);//picked up blocks
			
			moveToDist(-240, 200);
			smoothTurn(90, 200);
			
			moveToDist(200, 400);
			moveToDist(200, 100);
			moveToDist(-50, 100);
			smoothTurn(90, 200);
			
			moveToDist(230, 300);
			moveToDist(-240, 200);
			
			moveArm(ARM_POS_START);
			openClaw();
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
			moveArmUp();
			moveArm(ARM_POS_START);
					
			enable_servos();
			set_servo_position(CLAW_PORT, 1200);
		}  
	}
}
		
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
			movearmDown(ARM_PARTIAL_DOWN);
			slowReleaseClaw();
			printf("Claw opened.\n");
			moveToDist(200, 250);
			printf("Backed away, program done. \n");
*/
