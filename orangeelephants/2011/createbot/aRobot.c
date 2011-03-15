#include "createFunctions.c"
#include "createMotor.c"

int main()
{
	printf("Press the A to run side A.\n");
	printf("Press the up button to calibrate the claw.\n");
	
	createInitialize();
	
	while(1)
	{
		
		if(a_button())
		{	
			//initialization
			shut_down_in(120);
			enable_servos();
			
			//Leg 1, starts and drops off airplane
			scraperNeutral();//puts treads up, so ready to scrape and not interfeing with claw
			//set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
			moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
			smoothTurn(-90, 200);//Faces North
			accel(0, 500);
			moveToDist(1040, 500);//Travels North the length of the board
			accel(500, 50);
			//moveToDist(150, NORMAL_SPEED);
			moveToDist(-7, 200);//Backs up from wall to allow turn
			smoothTurn(90, 200);//Turns towards runway, robot faces West
			//Going in for airplane dropoff
			moveStraight(-150);//Runs into West PVC
			sleep(1.75);
			moveStraight(0);
			mtp(GRABBER_PORT, 1000, 180);//drops off airplane
			bmd(GRABBER_PORT);
			sleep(.5);
			//Completed the airplane dropoff
			
			//Leg 2, picks up first set of blocks
			moveToDist(225+25, NORMAL_SPEED);//backs up before turning to head back 
			smoothTurn(-94, 200);//Turns to face North
			moveToDist(30, 100);
			moveStraight(100);//Wall alignment w/ North PVC
			mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN);//puts claw down on the ground
			openClawPartial();//opens claws to grab blocks
			accel(0, -1400);//drives back to align with blocks
			accel(-1400, 0);
			smoothTurn(-94, 200);//turns West to face blocks
			bmd(ARM_MOTOR_PORT);//wait for arm to be down
			moveToDist(90+40, 100);//drive forward to pick up blocks
			closeClaw();//close claw, grab blocks
			moveToDist(-200, 100);//pulls blocks back
			openClawPartial();//opens claw to allow for second grab
			moveToDist(90, 100);//drives forward to align blocks
			moveStraight(-100);//backs up to allow for pickup
			sleep(0.35);
			create_stop();
			closeClaw();//grabs the blocks 
			sleep(0.25);
			mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, ARM_POS_START+2000);//picks up the blocks
			
			//Leg 3, stacks blocks in starting zone
			accel(0, -200);
			moveToDist(-50,200);//backs up holding blocks
			accel(-200, 0);
			bmd(ARM_MOTOR_PORT);
			smoothTurn(-82, 200);//Turns to face South
			accel(0, 300);
			moveToDist(250, 300);//Runs into South PVC
			accel(300, 50);
			sleep(1);
			moveToDist(-4, 100);//replaces previous two lines
			smoothTurn(-73, 200);//Face West
			
			accel(0,150);
			//sleep(1);
			moveToDist(25, 150);//goes forward to align with West PVC
			accel(150,0);
			
			mtp(ARM_MOTOR_PORT, -100, ARM_POS_START+1000);
			accel(0, -300);
			sleep(1.1);//drives back to put scraper over botguy
			accel(-300, -100);
			sleep(0.4);
			scraperDown();
			
			accel(0, 150);
			sleep(1);
			accel(150, 100);
			scraperNeutral();	
			create_stop();
			bmd(ARM_MOTOR_PORT);
			slowReleaseClaw();
			//Drop off first set
			
			mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, ARM_POS_START+2000);//picked up blocks
			
			openClawPartial();
			moveToDist(-120, 300); //backing up
			//---------------------------------------------------------------------------//
			//***************************************************************************//
			//---------------------------------------------------------------------------//
			
			smoothTurn(-90, 200);
			
			moveStraight(500); 
			sleep(.75);
			
			
			smoothTurn(-90, 200); //turn left prior to alignment
			moveStraight(500); //wall align 1
			sleep(1);
			moveStraight(150); //wall align 2 (slower, shorter)
			sleep(.4);
			
			mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN); //lower arm
			moveStraight(-115); //back up
			sleep(.7);
			smoothTurn(83, 200); //turn to face north
			
			
			//go in for first grab attempt
			moveToDist(185, 300); 
			openClawPartial();
			moveToDist(330, 300);  
			smoothTurn(-20, 50); //turn to get blocks in claw range
			moveToDist(20-10, 300);
			//first grab
			bmd(ARM_MOTOR_PORT); 
			closeClaw();
			moveToDist(-150, 100); //back up a bit
			openClaw(); //open again
			
			moveToDist(100, 100); //go forward again
			moveStraight(-100); //back up a bit
			sleep(0.35);
			create_stop();
			closeClaw(); 
			
			mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, 200);//picked up blocks
			sleep(1);
			
			
			accel(0, -300); //back up accelarate
			sleep(1);
			accel(-300, 0); //back up decelarate
			turn(15, 50); //turn back to be straight 
			
			accel(0, -300); //go backward into PVC
			sleep(.75);
			accel(-300, -100);
			sleep(.75);			
			moveArmUp(); 
			turn(71, 200); //face other blocks
			accel(0, 200);
			accel(200, 100);
			sleep(.3);
			
			create_stop();
			
			moveToDist(-60, 200);
			slowReleaseClaw();
			moveToDist(-200, 100);
			disable_servos();
			ao();

		}
		
		if(black_button())//calibrates the airplane
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
