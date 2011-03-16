#include "createFunctions.c"
#include "createMotor.c"

int main()
{
	printf("Press the up button to calibrate the claw or down to test code.\n");	
	createInitialize();
	
	while(1)
	{
		while(1)	{
			if(up_button())//calibrates arm and opens claw
			{
				moveArmUp();
				moveArm(ARM_POS_START, ARM_DOWN_VELOCITY);
					
				enable_servos();
				set_servo_position(CLAW_PORT, 1200);
				printf("Now press the black button to calibrate the airplane.\n");
				break;
			}
			
			if(down_button())	{
				turn(-110 , 150); //turn to align totally Sotuh
				accel(0, 300); //go backward into Sotuh PVC
				sleep(.75);
				accel(300, 100);
				sleep(.75);	//wall align
				moveArmUp(); //makes sure arm is totally up
				smoothTurn(-72.5, 200); //face other blocks
				accel(0, 100);//goes forwards towards other blocks and pushes them
				sleep(.6);
				accel(100, 60);
				sleep(1);
				create_stop();
				moveToDist(-60, 130); //pulls back to drop off blocks
				slowReleaseClaw(); //opens claw to drop off blocks
				moveToDist(-100, 150);//backs away from structure
			}
		}
		
		while(1)	{
			if(black_button())//calibrates the airplane
			{
				beep();
				clear_motor_position_counter(GRABBER_PORT);
				mtp(GRABBER_PORT, NORMAL_SPEED, 0);
				beep();
				printf("Now press the a button to run the code.\n");
				break;
			}
		}
		
		while(1)	{//keep in allows a button to run code w/o further indenting
		if(a_button())
		{	
			int initSeconds = seconds();
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
			sleep(2.75);
			moveStraight(0);
			mtp(GRABBER_PORT, 300, 160);//drops off airplane
			bmd(GRABBER_PORT);
			sleep(.5);
			//Completed the airplane dropoff
			
			//Leg 2, picks up first set of blocks
			moveToDist(225+25, 500);//backs up before turning to head back 
			smoothTurn(-94, 200);//Turns to face North
			moveToDist(30, 100);
			moveStraight(100);//Wall alignment w/ North PVC
			mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN);//puts claw down on the ground
			openClawPartial();//opens claws to grab blocks
			accel(0, -1400+250);//drives back to align with blocks
			accel(-1400+250, 0);
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
			
			//Leg 3, scrapes down botguy and stacks blocks in starting zone
			//accel(0, -200);
			//moveToDist(-7,200);//backs up holding blocks, old is -47
			//accel(-200, 0);
			//accel(0, -100);
			//accel(-100, 0);
			//bmd(ARM_MOTOR_PORT);
			moveStraight(-50);
			sleep(.8);
			smoothTurn(-90, 200);//Turns to face South
			accel(0, 250);
			//moveToDist(440, 250);//Runs into South PVC, passes over black tape
			sleep(2.1);
			accel(250, 50);
			sleep(.4);//Runs into South PVC
			moveToDist(-4, 100);//Backs up from South PVC to allow for turn
			turn(-79, 150);//Face West to drop off first set of blocks
			accel(0, 150);
			sleep(1.2+2.2);//Run into west PVC wall to align
			accel(150, 0);
			mtp(ARM_MOTOR_PORT, -100, ARM_POS_START+1000);//start lowering the blocks
			accel(0, -300);//begin backing up
			sleep(1.1);//drives back to put scraper over botguy
			accel(-300, -100);
			sleep(0.4);
			scraperDown();//puts down scraper
			accel(0, 150);
			sleep(1.2+1.8);//drives forward and scrapes down botguy and aligns with west PVC
			accel(150, 100);//slow down
			scraperNeutral();//puts treads back up for future turning	
			create_stop();
			accel(0, -150);//back up to set blocks down because it was hitting PVC
			sleep(.8);
			accel(-150,0);
			bmd(ARM_MOTOR_PORT);//wait for blocks to be all the way lowered
			slowReleaseClaw();//drop off first two blocks
			
			//Leg 4, picks up second set of blocks			
			//mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, ARM_POS_START+2000);//picks up arm after dropping off blocks
			openClawPartial();//puts claw in open position, ready to get new blocks
			moveToDist(-120-110, 300); //back up into botguy
			smoothTurn(-90, 200); //turn North 
			moveStraight(500); //drive North
			sleep(.75);
			smoothTurn(-90, 200); //turn to West to allow for PVC alignment
			moveStraight(500); //algin with West PVC
			sleep(.7);
			moveStraight(150); //continue aligning with the wall
			sleep(.3);
			mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN); //lower arm to get ready to pick up blocks 
			moveStraight(-115); //back up to allow for turn
			sleep(.7);
			smoothTurn(83, 200); //turn to face North and pursue blocks	
			//go in for first grab attempt
			moveToDist(185+330, 300); //drive towards blocks, old val 185
			//openClawPartial();
			//moveToDist(330, 300);  
			smoothTurn(-20, 50); //turn to get blocks in claw range
			moveToDist(20-10, 300);//drive at blocks
			//first grab
			bmd(ARM_MOTOR_PORT); //wait until the claw is on the ground
			closeClaw();//close the claw to grab the blocks
			moveToDist(-150, 100); //back up a bit pulling the blocks for alignment
			openClaw(); //open claw again to allow for grab
			moveToDist(100, 100); //go forward again pushing blocks for alignment
			moveStraight(-100); //back up a bit
			sleep(0.35);
			create_stop();
			closeClaw();//close claw on the second set of blocks
			mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, 200);//pick up second set of blocks
			sleep(1);
			
			//Leg 5, stack second set of blocks
			accel(0, -300); 
			sleep(2); //back up towards the South PVC
			accel(-300, 0); 
			turn(-152 , 150); //turn to align totally Sotuh
			accel(0, 100); //go backward into Sotuh PVC
			//sleep(.25);
			accel(100, 20);
			moveArmUp(); //makes sure arm is totally up
			smoothTurn(-72.5, 200); //face other blocks
			accel(0, 100);//goes forwards towards other blocks and pushes them
			sleep(.25);
			accel(100, 60);
			sleep(.5);
			create_stop();
			moveToDist(-60, 130); //pulls back to drop off blocks
			slowReleaseClaw(); //opens claw to drop off blocks
			moveToDist(-100, 150);//backs away from structure
			disable_servos();
			beep();
			printf("The total time is %d.\n",initSeconds-seconds());
			ao();

		}
		}//keep, ends while loop
 
	}
}
	
