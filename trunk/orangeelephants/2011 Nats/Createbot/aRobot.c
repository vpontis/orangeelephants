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
			createMove(NORMAL_SPEED, 1.54); 
		}
		if (b_button()) {
			closeClaw(); 
			
			createMove(NORMAL_SPEED, 1.59); 	
			turn(90); 
			openClaw();		 
			createMove(NORMAL_SPEED, 1.00); 	
			//createCenter(0);
				
			createMove(SLOW_SPEED, 1.8); 
			sleep(.5); 
			closeClaw(); 
			sleep(1); 
			moveArm(ARM_POS_UP);  
			createMove(-NORMAL_SPEED, 1.05); 
			turn(-90); 
			createMove(NORMAL_SPEED, 1.84); 
			turn(90); 
			 
			createMove(NORMAL_SPEED, .7); 
			//createCenter(0); 
			createMove(SLOW_SPEED, .9);  		
			sleep(1); 
			openClaw(); 
	
			createMove(-SLOW_SPEED, .85); 
			moveArm(ARM_POS_MID); 
			bmd(ARM_MOTOR_PORT); 
			closeClawIncrement(); 
			sleep(.5); 
			openClaw(); 
			 
			createMove(-NORMAL_SPEED, .85); 
			turn(90); 
			createMove(NORMAL_SPEED, 1.05); 
			turn(-90); 
			createMove(NORMAL_SPEED, 4); 
			turn(-90); 
			createMove(NORMAL_SPEED, 1.05); 
			moveArm(ARM_POS_DOWN); 
			turn(-90); 
			createMove(NORMAL_SPEED, .5); 
			
			createCenter(0); 
			createMove(SLOW_SPEED, 1); 
			closeClaw(); 
			
		}
	}
}
