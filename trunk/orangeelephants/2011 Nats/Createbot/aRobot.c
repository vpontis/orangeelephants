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
			createCenter(0,20,MIN_CONFIDENCE_LONG); 
		}
		if (left_button()) {
			turn(90); 
		}
		if (right_button()) {
			turn(-90); 
		}
		if (b_button()) {
			closeClaw(); 
	
			//move towards first set of blocks
			createMove(NORMAL_SPEED, 1.585); //
			turn(90); 
			openClaw();		 
			createMove(NORMAL_SPEED, 1.00); 	
			//createCenter(0);
			
			//pick up first set of blocks
			createMove(SLOW_SPEED, 1.8); 
			closeClaw(); 
			sleep(1); 
			moveArm(ARM_POS_UP);  
			
			//move towards second set of blocks
			createMove(-NORMAL_SPEED, 1.1); 
			turn(-90); 
			createMove(NORMAL_SPEED, 1.815); 
			turn(90); 
			
			//drop first set of blocks on top of second
			createMove(NORMAL_SPEED, .8); 
			createCenter(0,7,MIN_CONFIDENCE_SHORT); 
			createMove(SLOW_SPEED, 1.15);  	
			createMove(-SLOW_SPEED,.6); 
			openClaw(); 
			sleep(.5); 
			
			//********Perfect up until here*****************\\
			
			
			//move to other side of board
			moveArm(ARM_POS_UP); 
			createMove(-NORMAL_SPEED, 1.2); 
			turn(90); 
			createMove(NORMAL_SPEED, .88); 
			turn(-90); 
			createMove(FAST_SPEED, 3.3); 
			
			//wall allignment
			turn(90); 
			/*while( get_create_rbump(.01) != 1) {
				moveStraight(-FAST_SPEED);
			}
			createStop(); */
			createMove(-NORMAL_SPEED,.9); 
			//createMove(-NORMAL_SPEED, 2.25); 
			
			/*//2nd wall allignment
			createMove(NORMAL_SPEED, .795); //backs up so distance matches that of the blocks
			turn(90); 
			createMove(-NORMAL_SPEED, 2.2); */
			
			//pick up third set of blocks
			//createMove(NORMAL_SPEED, .68); //backs up so distance matches that of the blocks
			turn(90); 			
			moveArm(ARM_POS_MID); 
			createCenter(0,7,MIN_CONFIDENCE_SHORT); 
			moveArm(ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 2.2);  
			closeClaw(); 
			sleep(.5); 		

			//goes back to side B
			moveArm(ARM_POS_MID); 
			createMove(-NORMAL_SPEED, .88); 
			turn(90); 
			createMove(-NORMAL_SPEED, 1.05); 
			turn(-90);
			createMove(FAST_SPEED, 3.79);
			createMove(-NORMAL_SPEED, .1); 

			/* createMove(NORMAL_SPEED, 1); 
			createMove(25, 3); 					//wall allignment
			createMove(-NORMAL_SPEED, .67); 
			*/
			
			//Drop off blocks near starting box.
			moveArm(ARM_POS_DOWN); //save time
			turn(-84);
			createMove(NORMAL_SPEED,1.3);
			bmd(ARM_MOTOR_PORT); 
			openClaw(); 
			sleep(.5); 
			moveArm(ARM_POS_UP); 
			
			//Move to and pick up stack of four
			while( get_create_rbump(.01) != 1) {
				moveStraight(-FAST_SPEED);
			}
			createStop(); 
			//createMove(-FAST_SPEED, 3.0); //wall allignment
			createMove(NORMAL_SPEED, .60); 
			turn(-90); 
			//createMove(NORMAL_SPEED, 1.9); //wall allignment
			
			createMove(NORMAL_SPEED, .3); 
			moveArm(ARM_POS_MID); 
			//turn(-90); 
			//turn(-90); 
			createCenter(0,7,MIN_CONFIDENCE_SHORT); 
			moveArm(ARM_POS_DOWN); 
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 3); 
			closeClawIncrement(); 
			sleep(.5); 
			
			//Drop off stack of four on stack of two
			moveArm(ARM_POS_UP); 
			createMove(-SLOW_SPEED, 2); 
			smoothTurn(90,200);   
			createMove(SLOW_SPEED, 2.9); 
			createStop(); 
			createCenter(0,15,MIN_CONFIDENCE_LONG); 
			accel(0,270);  
			accel(270,0); 
			createStop(); 
			createCenter(0,8,MIN_CONFIDENCE_SHORT); 
			createMove(SLOW_SPEED, 2); 
			createMove(-SLOW_SPEED, .43); 
			sleep(.5); 
			openClaw(); 
			sleep(.5); 
			createMove(-FAST_SPEED, .6); 
		}
	}
}
