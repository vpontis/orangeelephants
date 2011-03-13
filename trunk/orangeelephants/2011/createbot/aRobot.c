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
			scraperNeutral();
			//set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
			
			/*
			moveToDistAccel(-5, NORMAL_SPEED);	
			
			smoothTurn(-90, 200);
			
			accel(0, 1500);
			moveToDist(630, 1500);
			accel(1500, 0);
			
			//moveToDist(150, NORMAL_SPEED);
			create_drive_straight(-60);
			sleep(2);
			create_drive_straight(-20);
			smoothTurn(90, 200);
			
			//Going in for airplane dropoff
			moveToDistAccel(-20, NORMAL_SPEED);
			mtp(GRABBER_PORT, 70, 180);
			bmd(GRABBER_PORT);
			//Completed the airplane dropoff
			
			moveToDist(250, NORMAL_SPEED);
			smoothTurn(-94, 200);
			moveStraight(100);
			sleep(1.25);
			
			accel(0, -1400);
			sleep(.02);
			accel(-1400, 0);
			
			smoothTurn(-94, 200);
			set_servo_position(CLAW_PORT,950);
			
			mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT);
			
			//go in for first grab attempt
			moveToDist(160, 100);
			closeClaw();
			moveToDist(-200, 100);
			openClaw();
			
			moveToDist(110, 100);
			
			create_drive_straight(100);
			sleep(0.40);
			create_stop();
			closeClaw();
			//Second grab attempt
			
			sleep(0.25);
			moveArm(ARM_POS_START+2000, ARM_UP_VELOCITY);//picked up blocks
			
			moveToDistAccel(-130, 200);
			smoothTurn(-85, 200);
			
			accel(0, 300);
			sleep(1.3);
			accel(300, 50);
			sleep(2.5);
	
			moveStraight(-100);
			sleep(.2);
			smoothTurn(-83, 200);
			
			accel(0,150);
			sleep(1.4);
			accel(150,0);
			
			mtp(ARM_MOTOR_PORT,-100, ARM_POS_START+1000);
			accel(0, -300);
			sleep(1.5);
			accel(-300, -100);
			sleep(1);
			scraperDown();
			
			accel(0, 150);
			sleep(1);
			accel(150, 100);
			scraperNeutral();	
			create_stop();
			bmd(ARM_MOTOR_PORT);
			slowReleaseClaw();
			//Drop off first set
			
			moveArm(ARM_POS_START+2000, ARM_UP_VELOCITY);//picked up blocks
			
			*/
			moveToDist(-120, 300);
			
			
			smoothTurn(-90, 200);
			
			moveStraight(500);
			sleep(.45);
			
			smoothTurn(-90, 200); 
			moveStraight(500);
			sleep(1);
			
			
			moveStraight(-100);
			sleep(.4);
			create_stop();
			mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN);
			smoothTurn(90, 200);
			bmd(ARM_MOTOR_PORT);
			closeClaw();
			
			//go in for first grab attempt
			moveToDist(180, 300);
			openClaw();
			moveToDist(400, 300);
			smoothTurn(-15, 50);
			//first grab
			closeClaw();
			moveToDist(-150, 100);
			openClaw();
			
			moveToDist(80, 100);
			moveStraight(-100);
			sleep(0.40);
			create_stop();
			closeClaw();
			
			mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, 200);//picked up blocks
			sleep(1);
			
			
			//Second grab attempt
			accel(0, -300);
			accel(-300, 0);
			turn(15, 50);
			
			accel(0, -300);
			sleep(.75);
			accel(-300, -100);
			sleep(.75);			
			moveArmUp();
			smoothTurn(90, 200);
			accel(0, 300);
			accel(300, 100);
			create_stop();
			moveToDist(-40, 200);
			slowReleaseClaw();

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
			//go in for first attempt
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
			moveStraight(100);
			sleep(3);
			moveToDist(-50, 100);
			smoothTurn(90, 200);
			
			moveStraight(130);
			sleep(2);
			moveToDist(-100, 300);
			moveArm(ARM_POS_START+1500, -100);
			slowReleaseClaw();
			//Drop off first set
			
			
			moveToDist(-200, 300);
			
			
			
						
		}
	
		
		if(black_button())
		{
			beep();
			clear_motor_position_counter(GRABBER_PORT);
			mtp(GRABBER_PORT, NORMAL_SPEED, 0);
			beep();
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
