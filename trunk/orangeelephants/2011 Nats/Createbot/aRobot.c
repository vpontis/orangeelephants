#include "createFunctions.c"

int main()
{  
	enable_servos();
	createInitialize();
	calibrateArm();
	openClaw(); 
	moveArm(ARM_POS_DOWN); 
	while (1) {
		if (a_button()) {
			closeClaw(); 
			moveArm(ARM_POS_UP); 
			smoothTurn(90,188); 
		}
		if (b_button()) {
			closeClaw(); 
	
			//move towards first set of blocks
			createMove(NORMAL_SPEED, 1.60); //
			turn(90); 
			openClaw();		 
			createMove(NORMAL_SPEED, 1.00); 	
			//createCenter(0);
			
			//pick up first set of blocks
			createMove(SLOW_SPEED, 1.8); 
			sleep(.5); 
			closeClaw(); 
			sleep(1); 
			moveArm(ARM_POS_UP);  
			
			//move towards second set of blocks
			createMove(-NORMAL_SPEED, 1.1); 
			turn(-90); 
			createMove(NORMAL_SPEED, 1.84); 
			turn(90); 
			
			//drop first set of blocks on top of second
			createMove(NORMAL_SPEED, .8); 
			createCenter(0,5); 
			createMove(SLOW_SPEED, 1.05);  		
			sleep(.5); 
			openClaw(); 
			sleep(.5); 
			
			//********Perfect up until here*****************\\
			
			
			//move to other side of board
			moveArm(ARM_POS_UP); 
			createMove(-NORMAL_SPEED, 1.2); 
			turn(90); 
			createMove(NORMAL_SPEED, .88); 
			turn(-90); 
			createMove(FAST_SPEED, 3.1); 
			
			//wall allignment
			turn(90); 
			createMove(-NORMAL_SPEED, 2.3); 
			
			/*//2nd wall allignment
			createMove(NORMAL_SPEED, .795); //backs up so distance matches that of the blocks
			turn(90); 
			createMove(-NORMAL_SPEED, 2.2); */
			
			//pick up third set of blocks
			createMove(NORMAL_SPEED, .75); //backs up so distance matches that of the blocks
			turn(90); 			
			createCenter(0,5); 
			moveArm(ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 1); 
			sleep(.5); 
			closeClaw(); 
			sleep(.5); 		

			//goes back to side B
			moveArm(ARM_POS_UP); 
			createMove(-NORMAL_SPEED, 1.00); 
			turn(90); 
			createMove(-NORMAL_SPEED, 1.05); 
			turn(-90);
			createMove(FAST_SPEED, 3.22);

			/* createMove(NORMAL_SPEED, 1); 
			createMove(25, 3); 					//wall allignment
			createMove(-NORMAL_SPEED, .67); 
			*/
			
			//Drop off blocks near starting box.
			moveArm(ARM_POS_DOWN); //save time
			turn(-90);
			createMove(NORMAL_SPEED,1.2);
			bmd(ARM_MOTOR_PORT); 
			openClaw(); 
			moveArm(ARM_POS_UP); 
			
			//Move to and pick up stack of four
			createMove(-NORMAL_SPEED, 3.49); //wall allignment
			createMove(NORMAL_SPEED, .7); 
			turn(90); 
			createMove(NORMAL_SPEED, 1.9); //wall allignment
			
			createMove(-NORMAL_SPEED, 1.29); 
			moveArm(ARM_POS_MID); 
			turn(-90); 
			turn(-90); 
			createCenter(0,5); 
			moveArm(ARM_POS_DOWN); 
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 1); 
			sleep(.5); 
			closeClaw(); 
			sleep(.5); 
			
			//Drop off stack of four on stack of two
			moveArm(ARM_POS_UP); 
			createMove(-SLOW_SPEED, 2); 
			smoothTurn(90,188);   
			accel(0,400); 
			sleep(2.2); 
			createStop(); 
		}
	}
}
