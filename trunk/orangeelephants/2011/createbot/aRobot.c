#include "createFunctions.c"
#include "createMotor.c"

int main()
{
	printf("Press the B to run side B.\n");
	printf("Press the up button to calibrate the claw.\n");
	
	createInitialize();
	
	while(1)
	{
		
		if(a_button())
		{
			enable_servos();
			//set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
			
			moveToDistAccel(-5, NORMAL_SPEED);	
			//moveArm(ARM_POS_START+500, ARM_UP_VELOCITY);
			
			smoothTurn(-90, 200);
			
			accel(0, -1500);
			moveToDist(600, 1500);
			accel(-1500, 0);
			
			//moveToDist(150, NORMAL_SPEED);
			create_drive_straight(-60);
			sleep(2);
			create_drive_straight(-20);
			smoothTurn(90, 200);
			
			//Going in for airplane dropoff
			moveToDistAccel(-20, NORMAL_SPEED);
			mtp(GRABBER_PORT, 300, 180);
			bmd(GRABBER_PORT);
			mtp(GRABBER_PORT, -300, 0);
			bmd(GRABBER_PORT);
			mtp(GRABBER_PORT, 300, 100);
			bmd(GRABBER_PORT);
			mtp(GRABBER_PORT, -300, 0);
			bmd(GRABBER_PORT);
			mtp(GRABBER_PORT, 300, 100);
			bmd(GRABBER_PORT);
			//Completed the airplane dropoff
			
			moveToDist(200, NORMAL_SPEED);
			smoothTurn(90, 200);
			
			accel(0, -1300);
			accel(-1300, 0);
			
			smoothTurn(90, 200);
			set_servo_position(CLAW_PORT,950);
			
			mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT);
			
			//go in for first grab attempt
			moveToDist(50, 100);
			closeClaw();
			moveToDist(-210, 100);
			openClaw();
			
			moveToDist(60, 100);
			
			create_drive_straight(100);
			sleep(0.30);
			create_stop();
			closeClaw();
			//Second grab attempt
			
			sleep(0.25);
			moveArm(ARM_POS_START+2000, ARM_UP_VELOCITY);//picked up blocks
			
			moveToDist(-130, 200);
			smoothTurn(-90, 200);
			
			moveToDist(300, 400);
			create_drive_straight(-100);
			sleep(3);
			moveToDist(-50, 100);
			smoothTurn(-90, 200);
			
			create_drive_straight(-130);
			sleep(2);
			moveToDist(-100, 300);
			moveArm(ARM_POS_START+1500, -100);
			slowReleaseClaw();
			//Drop off first set
			
			
			moveToDist(-200, 300);
						
		}
		
		if(b_button())
		{
			enable_servos();
			//set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
			
			moveToDistAccel(-5, NORMAL_SPEED);	
			//moveArm(ARM_POS_START+500, ARM_UP_VELOCITY);
			
			smoothTurn(90, 200);
			
			accel(0, -1500);
			moveToDist(600, 1500);
			accel(-1500, 0);
			
			//moveToDist(150, NORMAL_SPEED);
			create_drive_straight(-60);
			sleep(2);
			create_drive_straight(-20);
			smoothTurn(-90, 200);
			
			moveToDistAccel(-20, NORMAL_SPEED);
			
			mtp(GRABBER_PORT, 300, 180);
			bmd(GRABBER_PORT);
			mtp(GRABBER_PORT, -1000, 0);
			bmd(GRABBER_PORT);
			mtp(GRABBER_PORT, 1000, 100);
			bmd(GRABBER_PORT);
			//Completed the airplane dropoff
			
			moveToDist(200, NORMAL_SPEED);
			smoothTurn(-90, 200);
			moveToDist(530, NORMAL_SPEED);//used to be 550, normal
			smoothTurn(-90, 200);
			set_servo_position(CLAW_PORT,950);
			mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT);
			//go in for first grab attempt
			moveToDist(155, 100);
			closeClaw();
			moveToDist(-210, 100);
			openClaw();
			
			moveToDist(60, 100);
			
			create_drive_straight(100);
			sleep(0.25);
			create_stop();
			closeClaw();
			//Second grab attempt
			
			sleep(0.25);
			moveArm(ARM_POS_START+2000, ARM_UP_VELOCITY);//picked up blocks
			
			moveToDist(-130, 200);
			smoothTurn(90, 200);
			
			moveToDist(300, 400);
			create_drive_straight(-100);
			sleep(3);
			moveToDist(-50, 100);
			smoothTurn(90, 200);
			
			create_drive_straight(-130);
			sleep(2);
			moveToDist(-100, 300);
			moveArm(ARM_POS_START+1500, -100);
			slowReleaseClaw();
			//Drop off first set
			
			
			moveToDist(-200, 300);
						
		}
	
		
		if(black_button())
		{
			clear_motor_position_counter(GRABBER_PORT);
			mtp(GRABBER_PORT, NORMAL_SPEED, 0);
			
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
