#include "createFunctions.c"

int main()
{  
	enable_servos();
	createInitialize();
	calibrateArm();
	openClaw(); 
	moveArm(ARM_POS_DOWN);
	moveSupport(SUPPORT_POS_DOWN); 
	printf("Main Menu \n Press B to execute code. Press L/R or A for testing.");
	while (1) {
		if (left_button()) {
			printf("Turning Compensation Ratio: %f \n", TURN_COMP_RATIO); 
			turn(-90); 
		}
		if (right_button()) {
			printf("Turning Compensation Ratio: %f \n", TURN_COMP_RATIO); 
			turn(90); 
		}
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
			createMove(NORMAL_SPEED, 1.885); 
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
			createMove(NORMAL_SPEED, .8); 
			turn(90); 
			while((seconds()-startTime)<29.6) {}
			createMove(FAST_SPEED, 2.37); 
			
			//pick up third set of blocks
			turn(-90); 
			createMove(-NORMAL_SPEED,.79); 
			turn(-90); 			
			moveArm(ARM_POS_MID); 
			createCenter(0,7,MIN_CONFIDENCE_SHORT); 
			moveArm(ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 2.2);  
			closeClaw(); 
			sleep(.5); 		

			//goes back to side B
			moveArm(ARM_POS_UP); 
			createMove(-FAST_SPEED, .3);
			adjustTurn(); 
			turn(-90); 
			createMove(-FAST_SPEED, .92); 
			turn(90);
			createMove(FAST_SPEED, 2.99);
			
			//Drop off blocks near starting box.
			moveArm(ARM_POS_DOWN); 
			turn(80);
			createMove(FAST_SPEED, 1.2);
			bmd(ARM_MOTOR_PORT); 
			openClaw(); 
			moveArm(ARM_POS_UP); 
			
			//Move to stack of four
			int bumperStart = seconds(); 
			while( get_create_rbump(.01) != 1) { 
				moveStraight(-FAST_SPEED);
				if ((seconds() - bumperStart) > 5) {
					break; 
				}
			}
			createStop(); 
			createMove(NORMAL_SPEED, .69); 
			turn(90); 
			createMove(NORMAL_SPEED, .3); 
			moveArm(ARM_POS_MID); 
			
			//pick up stack of four
			createCenter(0,6,MIN_CONFIDENCE_SHORT); 
			moveArm(ARM_POS_DOWN); 
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 2.1); 
			closeClawIncrement(); 
			sleep(.5); 
			
			//Drop off stack of four on stack of two
			moveArm(ARM_POS_UP); 
			createMove(-SLOW_SPEED, 2); 
			moveSupport(SUPPORT_POS_UP); 
			smoothTurn(-110,210);   
			createMove(SLOW_SPEED, 3.1);  
			createStop(); 
			createCenter(0,15,MIN_CONFIDENCE_LONG); 
			accel(0,245);  
			accel(245,0); 
			createStop(); 
			createCenter(0,7,MIN_CONFIDENCE_SHORT); 
			createMove(SLOW_SPEED, 3.5);  
			createMove(-SLOW_SPEED, .3); 
			if (CANT_SEE==false) {
				moveArm(ARM_POS_MID); 
			}
			else {
				moveArm(ARM_POS_DOWN); 
			}
			bmd(ARM_MOTOR_PORT); 
			sleep(.5); 
			openClawIncrement(); 
			sleep(.5); 
			if (CANT_SEE==false) {
				moveArm(ARM_POS_UP);
				bmd(ARM_MOTOR_PORT); 
			}
			createMove(-FAST_SPEED, .6); 
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
			createMove(NORMAL_SPEED, 1.885); 
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
			createMove(NORMAL_SPEED, .8); 
			turn(-90); 
			while((seconds()-startTime)<29.6) {}
			createMove(FAST_SPEED, 2.37); 
			
			//pick up third set of blocks
			turn(90); 
			createMove(-NORMAL_SPEED,.79); 
			turn(90); 			
			moveArm(ARM_POS_MID); 
			createCenter(0,7,MIN_CONFIDENCE_SHORT); 
			moveArm(ARM_POS_DOWN);
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 2.2);  
			closeClaw(); 
			sleep(.5); 		

			//goes back to side B
			moveArm(ARM_POS_UP); 
			createMove(-FAST_SPEED, .3);
			adjustTurn(); 
			turn(90); 
			createMove(-FAST_SPEED, .92); 
			turn(-90);
			createMove(FAST_SPEED, 2.99);
			
			//Drop off blocks near starting box.
			moveArm(ARM_POS_DOWN); 
			turn(-80);
			createMove(FAST_SPEED, 1.2);
			bmd(ARM_MOTOR_PORT); 
			openClaw(); 
			moveArm(ARM_POS_UP); 
			
			//Move to stack of four
			int bumperStart = seconds(); 
			while( get_create_rbump(.01) != 1) { 
				moveStraight(-FAST_SPEED);
				if ((seconds() - bumperStart) > 5) {
					break; 
				}
			}
			createStop(); 
			createMove(NORMAL_SPEED, .69); 
			turn(-90); 
			createMove(NORMAL_SPEED, .3); 
			moveArm(ARM_POS_MID); 
			
			//pick up stack of four
			createCenter(0,6,MIN_CONFIDENCE_SHORT); 
			moveArm(ARM_POS_DOWN); 
			bmd(ARM_MOTOR_PORT); 
			createMove(SLOW_SPEED, 2.1); 
			closeClawIncrement(); 
			sleep(.5); 
			
			//Drop off stack of four on stack of two
			moveArm(ARM_POS_UP); 
			createMove(-SLOW_SPEED, 2); 
			moveSupport(SUPPORT_POS_UP); 
			smoothTurn(110,210);   
			createMove(SLOW_SPEED, 3.1);  
			createStop(); 
			createCenter(0,15,MIN_CONFIDENCE_LONG); 
			accel(0,245);  
			accel(245,0); 
			createStop(); 
			createCenter(0,7,MIN_CONFIDENCE_SHORT); 
			createMove(SLOW_SPEED, 3.5);  
			createMove(-SLOW_SPEED, .3); 
			if (CANT_SEE==false) {
				moveArm(ARM_POS_MID); 
			}
			else {
				moveArm(ARM_POS_DOWN); 
			}
			bmd(ARM_MOTOR_PORT); 
			sleep(.5); 
			openClawIncrement(); 
			sleep(.5); 
			if (CANT_SEE==false) {
				moveArm(ARM_POS_UP);
				bmd(ARM_MOTOR_PORT); 
			}
			createMove(-FAST_SPEED, .6); 
		}
	}
}
