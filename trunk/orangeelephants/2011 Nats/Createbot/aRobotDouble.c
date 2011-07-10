#include "createFunctions.c"

void sideA();
void sideB();

void sideB() {
	int startTime = seconds(); 
	closeClaw(); 

	//move towards first set of blocks
	createMove(NORMAL_SPEED, 1.49); 
	turn(-90); 
	openClaw();		 
	createMove(NORMAL_SPEED, 1.00); 	
		
	//pick up first set of blocks
	touchSensorMovement(); 
	closeClaw(); 
	sleep(.5); 
	moveArm(ARM_POS_UP);  
		
	//move towards second set of blocks
	createMove(-NORMAL_SPEED, .6); 
	turn(90); 
	createMove(NORMAL_SPEED, 1.95); 
	turn(-90); 
		
	//drop first set of blocks on top of second
	createMove(NORMAL_SPEED, .1); 
	createCenter(0,6,MIN_CONFIDENCE_SHORT); 
	createMove(SLOW_SPEED, 2.45);  	
	createMove(-SLOW_SPEED,.69); 
	moveArm(ARM_POS_MID); 
	sleep(.5); 
	openClawIncrement(); 
	sleep(.5);
			
	//move to other side of board
	moveArm(ARM_POS_UP); 
	createMove(-FAST_SPEED, .25); 
	//adjustTurn(); 
	turn(-90); 
	createMove(NORMAL_SPEED, .8); 
	turn(90); 
	moveArm(ARM_POS_MID); 
	while((seconds()-startTime)<29.6) {}
	createMove(FAST_SPEED, 3); 
	while(1) {
		createMove(-FAST_SPEED, 1.5); 
		createMove(FAST_SPEED, 1.5); 
	}
}

/*******************************************************/

void sideA() {
	int startTime = seconds(); 
	closeClaw(); 

	//move towards first set of blocks
	createMove(NORMAL_SPEED, 1.49); 
	turn(90); 
	openClaw();		 
	createMove(NORMAL_SPEED, 1.00); 	
		
	//pick up first set of blocks
	touchSensorMovement(); 
	closeClaw(); 
	sleep(.5); 
	moveArm(ARM_POS_UP);  
		
	//move towards second set of blocks
	createMove(-NORMAL_SPEED, .6); 
	turn(-90); 
	createMove(NORMAL_SPEED, 1.92); 
	turn(90); 
		
	//drop first set of blocks on top of second
	createMove(NORMAL_SPEED, .1); 
	createCenter(0,6,MIN_CONFIDENCE_SHORT); 
	createMove(SLOW_SPEED, 2.45);  	
	createMove(-SLOW_SPEED,.69); 
	moveArm(ARM_POS_MID); 
	sleep(.5); 
	openClawIncrement(); 
	sleep(.5);
			
	//move to other side of board
	moveArm(ARM_POS_UP); 
	createMove(-FAST_SPEED, .25); 
	//adjustTurn(); 
	turn(90); 
	createMove(NORMAL_SPEED, .8); 
	turn(-90); 
	moveArm(ARM_POS_MID); 
	while((seconds()-startTime)<29.6) {}
	createMove(FAST_SPEED, 3); 
	while(1) {
		createMove(-FAST_SPEED, 1.5); 
		createMove(FAST_SPEED, 1.5); 
	}
}

int main() {
	enable_servos();
	createInitialize();
	calibrateArm();
	openClaw(); 
	moveArm(ARM_POS_DOWN);
	moveSupport(SUPPORT_POS_DOWN); 
	
	printf("Main Menu \n Press A for side A and B for side B. Press L/R for testing.");
	
	while (1) {
		
		if (a_button()) {
			wait_for_light(LIGHT_PORT); 
			run_for(110,sideA); 
			create_stop(); 
			disable_servos(); 
			beep(); 
			ao(); 
		}

		if (b_button()) {
			wait_for_light(LIGHT_PORT); 
			run_for(110, sideB); 
			create_stop(); 
			disable_servos(); 
			beep(); 
			ao(); 
		}
	}
}
