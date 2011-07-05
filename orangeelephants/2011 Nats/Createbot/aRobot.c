#include "createFunctions.c"

int main()
{  
	enable_servos();
	createInitialize();
	calibrateArm();
	openClaw(); 
	moveArm(ARM_POS_DOWN); 
	while (1) {
		if (b_button()) {
			closeClaw(); 
	
			//move towards first set of blocks
			createMove(NORMAL_SPEED, 1.60); 	
			turn(90); 
			openClaw();		 
			createMove(NORMAL_SPEED, 1.00); 	
			//createCenter(0);
			
			//pick up first set of blocks and move towards second set of blocks
			createMove(SLOW_SPEED, 1.8); 
			sleep(.5); 
			closeClaw(); 
			sleep(1); 
			moveArm(ARM_POS_UP);  
			createMove(-NORMAL_SPEED, 1.1); 
			turn(-90); 
			createMove(NORMAL_SPEED, 1.84); 
			turn(90); 
			
			//drop first set of blocks on top of second
			createMove(NORMAL_SPEED, .7); 
			createCenter(0,5); 
			createMove(SLOW_SPEED, 1.5);  		
			sleep(.5); 
			openClaw(); 
			sleep(.5); 
			
			//********Perfect up until here*****************\\
			
			
			//aligns first two sets of blocks on top of each other
			createMove(-SLOW_SPEED, .9); 
			moveArm(ARM_POS_MID); 
			bmd(ARM_MOTOR_PORT); 
			closeClawIncrement(); 
			sleep(.5); 
			openClaw(); 
			sleep(.5); 
			
			//move to other side of board
			moveArm(ARM_POS_UP); 
			createMove(-NORMAL_SPEED, .85); 
			turn(90); 
			createMove(NORMAL_SPEED, .95); 
			turn(-90); 
			createMove(FAST_SPEED, 3.1); 
			turn(-90); 
			createMove(NORMAL_SPEED, 2.3); 
			
			//picks up third set of blocks
			createMove(-NORMAL_SPEED, .72); 
			turn(-90); 
			createMove(-NORMAL_SPEED, 2.2); 
			createMove(NORMAL_SPEED, 1.1); 
			createCenter(0,5); 
			moveArm(ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 1); 
			sleep(.5); 
			closeClaw(); 
			sleep(1); 
			
			moveArm(ARM_POS_UP); 
			
			//goes back to side B
			createMove(-NORMAL_SPEED, 1.00); 
			turn(90); 
			createMove(-NORMAL_SPEED, 1.2); 
			turn(-90);
			createMove(FAST_SPEED, 2.9);
			turn(90);
			/* createMove(NORMAL_SPEED, 1); 
			createMove(25, 3); 
			createMove(-NORMAL_SPEED, .67); 
			*/
			createMove(NORMAL_SPEED,.95);
			turn(-90); 		
		}
	}
}
