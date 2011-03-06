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
			moveToDist(685, 400);
			smoothTurn(-90, 200);
			
			moveArm(ARM_POS_DOWN, ARM_DOWN_VELOCITY);
			
			//go in for first grab attempt
			moveToDist(115, 100);
			closeClaw();
			moveToDist(-210, 100);
			openClaw();
			
			moveToDist(60, 100);
			
			create_drive_straight(-20);
			sleep(0.05);
			create_stop();
			closeClaw();
			sleep(0.25);
			moveArm(ARM_POS_START+2000, ARM_UP_VELOCITY);//picked up blocks
			
			moveToDist(-150, 200);
			smoothTurn(90, 200);
			
			moveToDist(350, 400);
			moveToDist(100, 100);
			
			moveToDist(-50, 100);
			
			smoothTurn(90, 100);
			
			moveToDist(120, 130);
			moveToDist(-100, 300);
			
			moveArm(ARM_POS_START+1500, -100);
			slowReleaseClaw();
			
			moveToDist(-200, 300);
						
		}
		
		if(right_button())
		{
			/*
			while(1){
				printf("CHARGE IS %d \n", get_create_battery_charge(.1));
				printf("CAPACITY IS %d \n", get_create_battery_capacity(.1));
				sleep(1);
			}*/
			
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
			moveArm(ARM_POS_START, ARM_DOWN_VELOCITY);
					
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
