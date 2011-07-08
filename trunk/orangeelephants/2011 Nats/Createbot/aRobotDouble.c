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
			shut_down_in(117.5); 
			int startTime = seconds(); 
			closeClaw(); 
				
			//move towards first set of blocks
			createMove(NORMAL_SPEED, 1.569); //
			turn(-90); 
			openClaw();		 
			createMove(NORMAL_SPEED, 1.00); 	
			
			//pick up first set of blocks
			createMove(SLOW_SPEED, 1.8); 
			closeClaw(); 
			sleep(.5); 
			moveArm(ARM_POS_UP);  
			
			//move towards second set of blocks
			createMove(-NORMAL_SPEED, .6); 
			turn(90); 
			createMove(NORMAL_SPEED, 1.915); 
			turn(-90); 
			
			//drop first set of blocks on top of second
			createMove(NORMAL_SPEED, .1); 
			//createCenter(0,6,MIN_CONFIDENCE_SHORT); 
			createMove(SLOW_SPEED, 2.3);  	
			createMove(-SLOW_SPEED,.49); 
			sleep(.5); 
			openClaw(); 
			sleep(.5);
			
			//move to other side of board
			moveArm(ARM_POS_UP); 
			createMove(-FAST_SPEED, .25); 
			//adjustTurn(); 
			turn(-90); 
			createMove(NORMAL_SPEED, .7); 
			turn(90); 
			while((seconds()-startTime)<30) {}
			createMove(FAST_SPEED, 3); 
			while (1) {
				createMove(-FAST_SPEED, 1.5); 
				createMove(FAST_SPEED, 1.5); 
			}
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
			shut_down_in(117.5); 
			int startTime = seconds(); 
			closeClaw(); 
	
			//move towards first set of blocks
			createMove(NORMAL_SPEED, 1.569); //
			turn(90); 
			openClaw();		 
			createMove(NORMAL_SPEED, 1.00); 	
			
			//pick up first set of blocks
			createMove(SLOW_SPEED, 1.8); 
			closeClaw(); 
			sleep(.5); 
			moveArm(ARM_POS_UP);  
			
			//move towards second set of blocks
			createMove(-NORMAL_SPEED, .6); 
			turn(-90); 
			createMove(NORMAL_SPEED, 1.915); 
			turn(90); 
			
			//drop first set of blocks on top of second
			createMove(NORMAL_SPEED, .1); 
			//createCenter(0,6,MIN_CONFIDENCE_SHORT); 
			createMove(SLOW_SPEED, 2.3);  	
			createMove(-SLOW_SPEED,.49); 
			sleep(.5); 
			openClaw(); 
			sleep(.5);
			
			//move to other side of board
			moveArm(ARM_POS_UP); 
			createMove(-FAST_SPEED, .25); 
			//adjustTurn(); 
			turn(90); 
			createMove(NORMAL_SPEED, .7); 
			turn(-90); 
			while((seconds()-startTime)<30) {}
			createMove(FAST_SPEED, 3); 
			while (1) {
				createMove(-FAST_SPEED, 1.5); 
				createMove(FAST_SPEED, 1.5); 
			}
		}
	}
}
