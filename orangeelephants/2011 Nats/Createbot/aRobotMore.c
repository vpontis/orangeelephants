#include "createFunctions.c"

void sideA();
void sideB();

void sideA() {
	int startTime = seconds(); 

	//move towards far blocks
	createMove(FAST_SPEED, .7); 
	turn(90); 
	moveArm(ARM_POS_LOW); 
	while( get_create_rbump(.01) != 1) { 
		moveStraight(-FAST_SPEED);
	} 
	createStop(); 
	createMove(NORMAL_SPEED, .6); 
	turn(-90); 
		
	//pick up blocks
	touchSensorMovement(); 
	closeClaw(); 
	sleep(.1); 
	moveArm(ARM_POS_UP);  
		
	//move towards blocks close to starting box
	createMove(-FAST_SPEED, .2); 
	turn(90); 
	createMove(NORMAL_SPEED, 1.95); 
	turn(-90); 
		
	//stack 2 on 2
	createCenter(0, 6, MIN_CONFIDENCE_LONG); 
	createMove(SLOW_SPEED, .5);
	moveArm(ARM_POS_MID); 	
	createMove(-SLOW_SPEED, .2); 
	openClawIncrement(); 
	moveArm(ARM_POS_DOWN);
	createMove(-SLOW_SPEED, 1); 
	bmd(ARM_MOTOR_PORT); 
	touchSensorMovement();
	closeClawIncrement(); 
	
	//move to startingbox
	createMove(-SLOW_SPEED, .2); 
	create_drive(-50, 1); 
	sleep(4); 
	createMove(NORMAL_SPEED, .6); 
	openClawIncrement(); 

	//move to the other side
	moveArm(ARM_POS_UP);
	createMove(-FAST_SPEED, 1); 
	turn(-90); 
	while ((seconds()-startTime)<29.6) {}
	createMove(FAST_SPEED, 3);
}

int main() {
	enable_servos();
	createInitialize();
	calibrateArm();
	openClaw(); 
	moveArm(ARM_POS_MID);
	moveSupport(SUPPORT_POS_DOWN); 
	
	printf("Main Menu \n Press A for side A and B for side B.\n");
	
	while (1) {
		
		if (a_button()) {
			//wait_for_light(LIGHT_PORT); 
			run_for(110,sideA); 
			create_stop(); 
			disable_servos(); 
			beep(); 
			ao(); 
		}

		if (b_button()) {
			//wait_for_light(LIGHT_PORT); 
			run_for(110, sideB); 
			create_stop(); 
			disable_servos(); 
			beep(); 
			ao(); 
		} 
	}
}
