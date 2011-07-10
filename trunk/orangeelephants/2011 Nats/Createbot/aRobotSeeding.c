#include "createFunctions.c"

void sideA();
void sideB();

void sideB() {
	int startTime = seconds(); 
	closeClaw(); 

	//move towards first set of blocks
	createMove(NORMAL_SPEED, 1.493); 
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
	createMove(FAST_SPEED, 2.37); 
		
	//pick up third set of blocks
	turn(-90); 
	createMove(-NORMAL_SPEED,.77); 
	turn(-90); 			
	createCenter(0,7,MIN_CONFIDENCE_SHORT); 
	moveArm(ARM_POS_DOWN);
	bmd(ARM_MOTOR_PORT);   
	touchSensorMovement(); 
	closeClaw(); 
	sleep(.5); 		

	//goes back to side B
	moveArm(ARM_POS_UP); 
	createMove(-FAST_SPEED, .3);
	adjustTurn(); 
	turn(-90); 
	createMove(-FAST_SPEED, .6); 
	turn(90);
	createMove(FAST_SPEED, 2.66);
		
	//Drop off blocks near starting box.
	moveArm(ARM_POS_DOWN); 
	turn(81);
	createMove(FAST_SPEED, .92);
	bmd(ARM_MOTOR_PORT); 
	openClaw(); 
	moveArm(ARM_POS_UP); 
			
	//Move to stack of four
	createMove(-FAST_SPEED, .5); 
	turn(9); 
	int bumperStart = seconds(); 
	while( get_create_rbump(.01) != 1) { 
		moveStraight(-FAST_SPEED);
		if ((seconds() - bumperStart) > 8) {
			break; 
		}
	}
	createStop(); 
	createMove(NORMAL_SPEED, .6); 
	turn(90); 
	createMove(NORMAL_SPEED, .3); 
	moveArm(ARM_POS_MID); 
			
	//pick up stack of four
	moveSupport(SUPPORT_POS_UP); 
	createCenter(0,6,MIN_CONFIDENCE_SHORT); 
	moveArm(ARM_POS_DOWN); 
	bmd(ARM_MOTOR_PORT); 
	touchSensorMovement(); 
	closeClawIncrement(); 
	sleep(.5); 
	
	//Allign and move slightly towards starting box. 
	moveArm(ARM_POS_UP); 
	createMove(-SLOW_SPEED, 2); 
	create_drive(50, 1); 
	sleep(4.4); 
	create_stop();    
	createMove(SLOW_SPEED, 4);
	
	//Incase not enough time, move forward and drop completely down. 
	if ((seconds()-startTime)>140) {
		accel(0,220); 
		accel(220,0); 
		createStop(); 
		moveArm(ARM_POS_DOWN); 
		bmd(ARM_MOTOR_PORT); 
		sleep(.5); 
		openClawIncrement(); 
		sleep(.5); 
		createMove(-FAST_SPEED, .8); 
	}
	else {
		//Drop off stack of four on stack of two
		createCenter(0,8,MIN_CONFIDENCE_LONG); 
		accel(0,220);  
		accel(220,0); 
		createStop(); 
		//createCenter(0,6,MIN_CONFIDENCE_SHORT); 
		createMove(SLOW_SPEED, 1.6);  
		createMove(-SLOW_SPEED, .6); 
		moveArm(ARM_POS_MID); 
		bmd(ARM_MOTOR_PORT); 
		sleep(.5); 
		openClawIncrement(); 
		sleep(.5); 
		moveArm(ARM_POS_UP); 
		bmd(ARM_MOTOR_PORT); 
		createMove(-FAST_SPEED, .6); 
	}
}

/*******************************************************/

void sideA() {
	int startTime = seconds(); 
	closeClaw(); 

	//move towards first set of blocks
	createMove(NORMAL_SPEED, 1.493); 
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
	createMove(FAST_SPEED, 2.37); 
		
	//pick up third set of blocks
	turn(90); 
	createMove(-NORMAL_SPEED,.77); 
	turn(90); 			
	createCenter(0,7,MIN_CONFIDENCE_SHORT); 
	moveArm(ARM_POS_DOWN);
	bmd(ARM_MOTOR_PORT);   
	touchSensorMovement(); 
	closeClaw(); 
	sleep(.5); 		

	//goes back to side B
	moveArm(ARM_POS_UP); 
	createMove(-FAST_SPEED, .3);
	adjustTurn(); 
	turn(90); 
	createMove(-FAST_SPEED, .65); 
	turn(-90);
	createMove(FAST_SPEED, 2.66);
		
	//Drop off blocks near starting box.
	moveArm(ARM_POS_DOWN); 
	turn(-81);
	createMove(FAST_SPEED, .92);
	bmd(ARM_MOTOR_PORT); 
	openClaw(); 
	moveArm(ARM_POS_UP); 
			
	//Move to stack of four
	createMove(-FAST_SPEED, .5); 
	turn(-9); 
	int bumperStart = seconds(); 
	while( get_create_rbump(.01) != 1) { 
		moveStraight(-FAST_SPEED);
		if ((seconds() - bumperStart) > 8) {
			break; 
		}
	}
	createStop(); 
	createMove(NORMAL_SPEED, .6); 
	turn(-90); 
	createMove(NORMAL_SPEED, .3); 
	moveArm(ARM_POS_MID); 
			
	//pick up stack of four
	moveSupport(SUPPORT_POS_UP); 
	createCenter(0,6,MIN_CONFIDENCE_SHORT); 
	moveArm(ARM_POS_DOWN); 
	bmd(ARM_MOTOR_PORT); 
	touchSensorMovement(); 
	closeClawIncrement(); 
	sleep(.5); 
	
	//Allign and move slightly towards starting box. 
	moveArm(ARM_POS_UP); 
	createMove(-SLOW_SPEED, 2); 
	create_drive(-50, 1); 
	sleep(4.4); 
	create_stop();    
	createMove(SLOW_SPEED, 4);
	
	//Incase not enough time, move forward and drop completely down. 
	if ((seconds()-startTime)>145) {
		accel(0,220); 
		accel(220,0); 
		createStop(); 
		moveArm(ARM_POS_DOWN); 
		bmd(ARM_MOTOR_PORT); 
		sleep(.5); 
		openClawIncrement(); 
		sleep(.5); 
		createMove(-FAST_SPEED, .8); 
	}
	else {
		//Drop off stack of four on stack of two
		createCenter(0,8,MIN_CONFIDENCE_LONG); 
		accel(0,220);  
		accel(220,0); 
		createStop(); 
		//createCenter(0,6,MIN_CONFIDENCE_SHORT); 
		createMove(SLOW_SPEED, 1.6);  
		createMove(-SLOW_SPEED, .6); 
		moveArm(ARM_POS_MID); 
		bmd(ARM_MOTOR_PORT); 
		sleep(.5); 
		openClawIncrement(); 
		sleep(.5); 
		moveArm(ARM_POS_UP); 
		bmd(ARM_MOTOR_PORT); 
		createMove(-FAST_SPEED, .6); 
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
			run_for(116,sideA); 
			create_stop(); 
			disable_servos(); 
			beep(); 
			ao(); 
		}

		if (b_button()) {
			wait_for_light(LIGHT_PORT); 
			run_for(116, sideB); 
			create_stop(); 
			disable_servos(); 
			beep(); 
			ao(); 
		}
	}
}
