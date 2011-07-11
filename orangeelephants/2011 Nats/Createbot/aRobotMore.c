#include "createFunctions.c"

void sideA();
void sideB();

void sideA() {
	int startTime = seconds(); 

	//move towards far blocks
	createMove(FAST_SPEED, .5); 
	turn(90); 
	moveArm(ARM_POS_DOWN); 
	while( get_create_rbump(.01) != 1) { 
		moveStraight(-FAST_SPEED);
	} 
	createStop(); 
	createMove(NORMAL_SPEED, .6); 
	turn(-90); 
	createMove(NORMAL_SPEED, .2); 
		
	//pick up blocks
	touchSensorMovement(); 
	closeClaw(); 
	sleep(.5); 
	moveArm(ARM_POS_UP);  
		
	//move towards blocks close to starting box
	createMove(-NORMAL_SPEED, .3); 
	turn(90); 
	createMove(NORMAL_SPEED, 1.95); 
	turn(-90); 
		
	//stack 2 on 2
	createCenter(0, 6, MIN_CONFIDENCE_SHORT); 
	createMove(SLOW_SPEED, 1.6); 
	createMove(-SLOW_SPEED, .4); 
	moveArm(ARM_POS_MID); 
	bmd(ARM_MOTOR_PORT); 
	openClawIncrement(); 
	createMove(-NORMAL_SPEED, .3); 
	moveArm(ARM_POS_DOWN); 
	bmd(ARM_MOTOR_PORT); 
	touchSensorMovement();
	closeClawIncrement(); 
	
	createMove(-SLOW_SPEED, .2); 
	create_drive(-50, 1); 
	sleep(4); 
	createMove(SLOW_SPEED, 1.2); 
	moveArm(ARM_POS_DOWN); 
	bmd(ARM_MOTOR_PORT); 
	
	createMove(-FAST_SPEED,1.5); 
	moveArm(ARM_POS_UP); 
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

	/*	if (b_button()) {
			//wait_for_light(LIGHT_PORT); 
			run_for(110, sideB); 
			create_stop(); 
			disable_servos(); 
			beep(); 
			ao(); 
		} */
	}
}
