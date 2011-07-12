#include "createFunctions.c"

void sideA();
void sideB();

void sideA() {
	int startTime = seconds(); 
	moveSupport(SUPPORT_POS_UP); 
	//move towards far blocks
	createMove(FAST_SPEED, .6); 
	fastTurn(90); 
	moveArm(ARM_POS_DOWN); 
	while((get_create_rbump(.01) != 1)&&(get_create_lbump(.01) != 1)) { 
		moveStraight(-FAST_SPEED);
	} 
	createStop(); 
	createMove(NORMAL_SPEED, .65); 
	fastTurn(-90); 
		
	//pick up blocks
	createMove(FAST_SPEED, .6); 
	touchSensorMovement(); 
	closeClaw(); 
	sleep(.1); //test this value <- may remove
	moveArm(ARM_POS_UP);  
		
	//move towards blocks close to starting box	2
	createMove(-FAST_SPEED, .4); 
	sleep(.5); 
	fastTurn(90); 
	createMove(NORMAL_SPEED, 1.95); 
	fastTurn(-90); 
		
	//stack 2 on 2
	createCenter(0, 13, MIN_CONFIDENCE_LONG); //look at this tomorrow
	createMove(SLOW_SPEED, 1.5);
	moveArm(ARM_POS_MID); 	
	createMove(-SLOW_SPEED, .4); 
	moveArm(ARM_POS_DOWN+1200);
	openClaw(); 
	sleep(.5);
	createMove(-FAST_SPEED, .2); //1077182464 1017731536
	bmd(ARM_MOTOR_PORT); 
	touchSensorMovement();
	closeClaw(); 
	
	//move to startingbox
	createMove(-SLOW_SPEED, .2); 
	/* create_drive(-50,1); 
		sleep(4); 
	*/
	fastTurn(90); 
	createMove(NORMAL_SPEED, .2); 
	createMove(SLOW_SPEED, .2); 
	openClaw(); 
	sleep(.5); 

	//move to the other side
	moveArm(ARM_POS_UP);
	createMove(-FAST_SPEED, 1.3); 
	fastTurn(-90); 
	while ((seconds()-startTime)<29.8) {}
	createMove(FAST_SPEED, 3);
}

void sideB() {
	int startTime = seconds(); 
	moveSupport(SUPPORT_POS_UP); 
	//move towards far blocks
	createMove(FAST_SPEED, .6); 
	fastTurn(-90); 
	moveArm(ARM_POS_DOWN); 
	while((get_create_rbump(.01) != 1)&&(get_create_lbump(.01) != 1)) { 
		moveStraight(-FAST_SPEED);
	} 
	createStop(); 
	createMove(NORMAL_SPEED, .61); 
	fastTurn(90); 
		
	//pick up blocks
	createMove(FAST_SPEED, .6); 
	touchSensorMovement(); 
	closeClaw(); 
	sleep(.1); //test this value <- may remove
	moveArm(ARM_POS_UP);  
		
	//move towards blocks close to starting box	2
	createMove(-FAST_SPEED, .4); 
	sleep(.5); 
	fastTurn(-90); 
	createMove(NORMAL_SPEED, 1.95); 
	fastTurn(90); 
		
	//stack 2 on 2
	createCenter(0, 13, MIN_CONFIDENCE_LONG); //look at this tomorrow
	createMove(SLOW_SPEED, 1.6);
	moveArm(ARM_POS_MID); 	
	createMove(-SLOW_SPEED, .4); 
	moveArm(ARM_POS_DOWN+1200);
	openClaw(); 
	sleep(.5);
	createMove(-FAST_SPEED, .1); //1077182464 1017731536
	bmd(ARM_MOTOR_PORT); 
	touchSensorMovement();
	closeClaw(); 
	
	//move to startingbox
	createMove(-SLOW_SPEED, .4); 
	/* create_drive(-50,1); 
		sleep(4); 
	*/
	fastTurn(-90); 
	createMove(NORMAL_SPEED, .2); 
	createMove(SLOW_SPEED, .2); 
	openClaw(); 
	sleep(.5); 

	//move to the other side
	moveArm(ARM_POS_UP);
	createMove(-FAST_SPEED, 1.3); 
	fastTurn(90); 
	while ((seconds()-startTime)<29.8) {}
	createMove(FAST_SPEED, 3);
}

int main() {
	enable_servos();
	createInitialize();
	calibrateArm();
	sleep(.05); 
	openClaw(); 
	moveArm(ARM_POS_DOWN);
	moveSupport(SUPPORT_POS_DOWN); 
	
	printf("Main Menu \n Press A for side A and B for side B.\n");
	printf("Voltage: %d", get_create_battery_voltage(.01)); 
	
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
			if (black_button()) {
			printf("Voltage: %d", get_create_battery_voltage(.1)); 
		}
	}
}
