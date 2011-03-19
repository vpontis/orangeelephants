#include "createFunctions.c"
#include "createMotor.c"

int main()
{
	
	enable_servos();
	scraperStart();
	set_servo_position(GRABBER_PORT, GRABBER_UP);
	set_servo_position(CLAW_PORT, CLAW_OPEN_START);
	printf("Press the up button to calibrate the claw or down to test code.\n");	
	
	while(1)
	{
		while(1)	{
			if(up_button())//calibrates arm and opens claw
			{
				moveArmUp();
				moveArm(ARM_POS_START, ARM_DOWN_VELOCITY);
				
				set_servo_position(CLAW_PORT, 1200);
				printf("Now press the A button to run side A. \n");
				printf("Now press the B button to run side B. \n");
				break;
			}
			
			if(down_button())	{
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN + 1750);
				bmd(ARM_MOTOR_PORT);
				printf("POSITION 1");
				
			}
		}
		
		
		while(1)	{//keep in allows a button to run code w/o further indenting
			if(a_button())
			{	
				//initialization
				wait_for_light(LIGHT_PORT_A);
				shut_down_in(120);
				createInitialize();
				int initSeconds = seconds();
				
				//Leg 1, starts and drops off airplane
				scraperNeutral();//puts treads up, so ready to scrape and not interfeing with claw
				//set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
				moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
				smoothTurn(-90, 200);//Faces North
				accel(0, 500);
				moveToDist(1100, 500);//Travels North the length of the board
				accel(500, 50);
				//moveToDist(150, NORMAL_SPEED);
				moveToDist(-7, 200);//Backs up from wall to allow turn
				smoothTurn(90, 200);//Turns towards runway, roboct faces middle PVC
				//Going in for airplane dropoff
				moveStraight(-200);//Runs into middle PVC
				sleep(2.75);
				create_stop();
				releasePlane();
				//Completed the airplane dropoff
				
				//Leg 2, picks up first set of blocks
				moveToDist(225+25, 500);//backs up before turning to head back 
				smoothTurn(-90, 200);//Turns to face North
				moveStraight(100);//Wall alignment w/ North PVC
				sleep(.6);
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN+1700);//puts claw down on the ground
				openClaw();//opens claws to grab blocks
				accel(0, -1400+250);//drives back to align with blocks
				accel(-1400+250, 0);
				smoothTurn(-90, 200);//turns to middle PVC to face blocks
				moveToDist(120, 100);//drive forward to pick up blocks
				bmd(ARM_MOTOR_PORT);//wait for arm to be down
				closeClaw();//close claw, grab blocks
				moveToDist(-200, 100);//pulls blocks back
				openClawPartial();//opens claw to allow for second grab
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN+700);//puts claw down on the groun
				moveToDist(90, 100);//drives forward to align blocks
				//moveStraight(-100);//backs up to allow for pickup
				//sleep(0.35);
				create_stop();
				bmd(ARM_MOTOR_PORT);
				closeClaw();//grabs the blocks 
				sleep(0.25);
				mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, ARM_POS_START+2500);//picks up the block
				
				
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
				sleep(2.1); //Runs into South PVC, passes over black tape
				accel(250, 50);
				sleep(.4);//Runs into South PVC
				moveToDist(-4, 100);//Backs up from South PVC to allow for turn
				mtp(ARM_MOTOR_PORT, -100, ARM_POS_START+1700);//start lowering the blocks
				turn(-70, 130);//Face outer PVC
				accel(0, 150);
				sleep(1.2+2.2);//Run into outer PVC wall to align
				accel(150, 0);
				accel(0, -300);//begin backing up
				sleep(1.1);//drives back to put scraper over botguy
				accel(-300, -100);
				sleep(0.4);
				scraperDown();//puts down scraper
				//mtp(ARM_MOTOR_PORT, -100, ARM_POS_START+1000);//start lowering the blocks
				accel(0, 150);
				sleep(1.2+1.8);//drives forward and scrapes down botguy and aligns with outer PVC
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
				moveToDist(-60, 300); //back up into botguy
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN+2000);
				
				smoothTurn(90, 200);
				moveStraight(150);
				sleep(.6);
				moveToDist(-1170, 500);
				turn(85, 200);
				
				moveToDist(95, 300);//drive at blocks
				//first grab
				bmd(ARM_MOTOR_PORT); //wait until the claw is on the ground
				closeClaw();//close the claw to grab the blocks
				moveToDist(-350, 100); //back up a bit pulling the blocks for alignment
				openClawPartial(); //open claw again to allow for grab
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN-700);//puts claw down on the ground
				moveToDist(150, 100); //go forward again pushing blocks for alignment
				//moveStraight(-100); //back up a bit
				//sleep(0.2);
				create_stop();
				bmd(ARM_MOTOR_PORT);
				closeClaw();//close claw on the second set of blocks
				mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, 50);//pick up second set of blocks
				sleep(.75);
				
				//Leg 5, stack second set of blocks
				turn(-90, 100);
				accel(0, 300); 
				sleep(2.4); //back up towards the South PVC
				accel(300, 100); 
				//turn(5, 150); //turn to align totally Sotuh
				accel(0, 100); //go backward into Sotuh PVC
				sleep(.25);
				accel(100, 20);
				//run_for(3, moveArmUp()); //makes sure arm is totally up
				smoothTurn(-90, 200); //face other blocks
				
				accel(0, 100);//goes forwards towards other blocks and pushes them
				sleep(.3);
				accel(100, 60);
				sleep(.5);
		
				create_stop();
				moveToDist(-65, 130); //pulls back to drop off blocks
				slowReleaseClaw(); //opens claw to drop off blocks
				moveToDist(-25, 150);//backs away from structure
				disable_servos();
				beep();
				printf("The total time is %d.\n",initSeconds-seconds());
				ao();
			}
			if(b_button())
			{	
				//initialization
				wait_for_light(LIGHT_PORT_B);
				shut_down_in(120);
				createInitialize();
				
				int initSeconds = seconds();
			
				//Leg 1, starts and drops off airplane
				scraperNeutral();//puts treads up, so ready to scrape and not interfeing with claw
				//set_servo_position(CLAW_PORT,CLAW_TOTAL_OPEN);
				moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
				smoothTurn(93, 210);//Faces North
				accel(0, 500);
				moveToDist(1100, 500);//Travels North the length of the board
				accel(500, 50);
				//moveToDist(150, NORMAL_SPEED);
				moveToDist(-7, 200);//Backs up from wall to allow turn
				smoothTurn(-90, 200);//Turns towards runway, robot faces middle PVC
				//Going in for airplane dropoff
				moveStraight(-250);//Runs into middle PVC
				sleep(2.75);
				create_stop();
				releasePlane();
				//Completed the airplane dropoff
				
				//Leg 2, picks up first set of blocks
				moveToDist(225+25, 500);//backs up before turning to head back 
				smoothTurn(94, 200);//Turns to face North
				moveStraight(100);//Wall alignment w/ North PVC
				sleep(.6);
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN+1700);//puts claw down on the ground
				openClaw();//opens claws to grab blocks
				accel(0, -1400+250);//drives back to align with blocks
				accel(-1400+250, 0);
				smoothTurn(94, 200);//turns middle PVC to face blocks
				moveToDist(150, 100);//drive forward to pick up blocks
				bmd(ARM_MOTOR_PORT);//wait for arm to be down
				closeClaw();//close claw, grab blocks
				moveToDist(-200, 100);//pulls blocks back
				openClawPartial();//opens claw to allow for second grab
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN+700);//puts claw down on the groun
				moveToDist(90, 100);//drives forward to align blocks
				//moveStraight(-100);//backs up to allow for pickup
				//sleep(0.35);
				create_stop();
				bmd(ARM_MOTOR_PORT);
				closeClaw();//grabs the blocks 
				sleep(0.25);
				mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, ARM_POS_START+2500);//picks up the blocks
				
				//Leg 3, scrapes down botguy and stacks blocks in starting zone
				//accel(0, -200);
				//moveToDist(-7,200);//backs up holding blocks, old is -47
				//accel(-200, 0);
				//accel(0, -100);
				//accel(-100, 0);
				//bmd(ARM_MOTOR_PORT);
				moveStraight(-50);
				sleep(.8);
				smoothTurn(90, 200);//Turns to face South
				accel(0, 250);
				sleep(2.1); //Runs into South PVC, passes over black tape
				accel(250, 50);
				sleep(.4);//Runs into South PVC
				moveToDist(-4, 100);//Backs up from South PVC to allow for turn
				mtp(ARM_MOTOR_PORT, -100, ARM_POS_START+1700);//start lowering the blocks
				turn(70, 130);//Face outer PVC to drop off first set of blocks
				accel(0, 150);
				sleep(1.2+2.2);//Run into outer PVC wall to align
				accel(150, 0);
				accel(0, -300);//begin backing up
				sleep(1.1);//drives back to put scraper over botguy
				accel(-300, -100);
				sleep(0.4);
				scraperDown();//puts down scraper
				//mtp(ARM_MOTOR_PORT, -100, ARM_POS_START+1000);//start lowering the blocks
				accel(0, 150);
				sleep(1.2+1.8);//drives forward and scrapes down botguy and aligns with outer PVC
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
				moveToDist(-60, 300); //back up into botguy
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN+1750); //lower arm to get ready to pick up blocks 	
			
				smoothTurn(-90, 200);
				moveStraight(150);
				sleep(.6);
				moveToDist(-1150, 500);
				turn(-90, 200);
				
				moveToDist(115, 300);//drive at blocks
				//first grab
				bmd(ARM_MOTOR_PORT); //wait until the claw is on the ground
				closeClaw();//close the claw to grab the blocks
				moveToDist(-350, 100); //back up a bit pulling the blocks for alignment
				openClawPartial(); //open claw again to allow for grab
				mtp(ARM_MOTOR_PORT, ARM_DOWN_VELOCITY, ARM_POS_DOWN-700);//puts claw down on the ground
				moveToDist(150, 100); //go forward again pushing blocks for alignment
				//moveStraight(-100); //back up a bit
				//sleep(0.2);
				create_stop();
				bmd(ARM_MOTOR_PORT);
				closeClaw();//close claw on the second set of blocks
				mtp(ARM_MOTOR_PORT, ARM_UP_VELOCITY, 50);//pick up second set of blocks
				sleep(.75);
				
				
				//Leg 5, stack second set of blocks
				turn(90, 100);
				accel(0, 300); 
				sleep(2.4); //back up towards the South PVC
				accel(300, 100); 
				//turn(-5, 150); //turn to align totally Sotuh
				accel(0, 100); //go backward into Sotuh PVC
				sleep(.25);
				accel(100, 20);
				//run_for(3, moveArmUp()); //makes sure arm is totally up
				smoothTurn(91, 190); //face other blocks
				
				accel(0, 120);//goes forwards towards other blocks and pushes them
				sleep(.3);
				accel(120, 60);
				sleep(.5);
		
				create_stop();
				moveToDist(-80, 130); //pulls back to drop off blocks
				slowReleaseClaw(); //opens claw to drop off blocks
				moveToDist(-25, 300);//backs away from structure
				disable_servos();
				beep();
				printf("The total time is %d.\n",initSeconds-seconds());
				ao();
			}
		}//keep, ends while loop
 
	}
}
	
