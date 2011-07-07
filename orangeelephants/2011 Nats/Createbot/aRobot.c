#include "createFunctions.c"

int main()
{  
	enable_servos();
	createInitialize();
	
	calibrateArm();
	openClaw(); 
	moveArm(ARM_POS_DOWN);
	printf("Main Menu \n Press B to execute code. Press L/R or A for testing.");
	while (1) {
		
		if (a_button()) {
			beep();
		}
		if (left_button()) {
			printf("Turning Compensation Ratio: %f \n", TURN_COMP_RATIO); 
			turn(-90); 
		}
		if (right_button()) {
			printf("Turning Compensation Ratio: %f \n", TURN_COMP_RATIO); 
			turn(90); 
		}
		if (b_button()) {
			shut_down_in(119.5); 
			closeClaw(); 
	
			//move towards first set of blocks
			createMove(NORMAL_SPEED, 1.585); //
			turn(90); 
			openClaw();		 
			createMove(NORMAL_SPEED, 1.00); 	
			
			//pick up first set of blocks
			createMove(SLOW_SPEED, 1.8); 
			closeClaw(); 
			sleep(.5); 
			moveArm(ARM_POS_UP);  
			
			//move towards second set of blocks
			createMove(-NORMAL_SPEED, 1.1); 
			turn(-90); 
			createMove(NORMAL_SPEED, 1.84); 
			turn(90); 
			
			//drop first set of blocks on top of second
			createMove(NORMAL_SPEED, .8); 
			//createCenter(0,6,MIN_CONFIDENCE_SHORT); 
			createMove(SLOW_SPEED, 1.15);  	
			createMove(-SLOW_SPEED,.7); 
			openClaw(); 
			sleep(.5);
			
			//move to other side of board
			moveArm(ARM_POS_UP); 
			createMove(-NORMAL_SPEED, .3); 
			turn(90); 
			createMove(NORMAL_SPEED, .7); 
			turn(-90); 
			createMove(FAST_SPEED, 2.45); 
			
			//pick up third set of blocks
			turn(90); 
			createMove(-NORMAL_SPEED,.85); 
			turn(90); 			
			moveArm(ARM_POS_MID); 
			//createCenter(0,6,MIN_CONFIDENCE_SHORT); 
			moveArm(ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 2.2);  
			closeClaw(); 
			sleep(.5); 		

			//goes back to side B
			moveArm(ARM_POS_MID); 
			createMove(-NORMAL_SPEED, .4); 
			turn(90); 
			createMove(-NORMAL_SPEED, 1.25); 
			turn(-90);
			createMove(FAST_SPEED, 3.69);
			createMove(-NORMAL_SPEED, .2); 
			
			//Drop off blocks near starting box.
			moveArm(ARM_POS_DOWN); 
			turn(-84);
			createMove(NORMAL_SPEED,1.3);
			bmd(ARM_MOTOR_PORT); 
			openClaw(); 
			sleep(.5); 
			moveArm(ARM_POS_UP); 
			
			//Move to stack of four
			while( get_create_rbump(.01) != 1) { 
				moveStraight(-FAST_SPEED);
			}
			createStop(); 
			createMove(NORMAL_SPEED, .60); 
			turn(-90); 
			createMove(NORMAL_SPEED, .7); 
			moveArm(ARM_POS_MID); 
			
			//pick up stack of four
			//createCenter(0,6,MIN_CONFIDENCE_SHORT); 
			moveArm(ARM_POS_DOWN); 
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 3); 
			closeClawIncrement(); 
			sleep(.5); 
			
			//Drop off stack of four on stack of two
			moveArm(ARM_POS_UP); 
			createMove(-SLOW_SPEED, 2); 
			smoothTurn(90,180);   
			createMove(SLOW_SPEED, 2.9); 
			createStop(); 
			createCenter(0,15,MIN_CONFIDENCE_LONG); 
			accel(0,200);  
			accel(200,0); 
			createStop(); 
			createCenter(0,7,MIN_CONFIDENCE_SHORT); 
			createMove(SLOW_SPEED, 2); 
			createMove(-SLOW_SPEED, .5); 
			moveArm(ARM_POS_DOWN); 
			sleep(.5); 
			openClawIncrement(); 
			sleep(.5); 
			createMove(-FAST_SPEED, .6); 
		}
	}
}
