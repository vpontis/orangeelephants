#include "createFunctions.c"

int main()
{  
	enable_servos();
	createInitialize();
	calibrateArm();
	openClaw(); 
	moveArm(ARM_POS_UP);
	while (1) {
		if (a_button()) {
			createCenter(0); 
		}
		if (left_button()) {
			turn(-90); 
		}
		if (right_button()) {
			turn(90); 
		}
		if (b_button()) {
			closeClaw(); 
			
			moveStraight(400); //55cm
			sleep(1.5); 
			createStop(); 
				
			turn(90); 
			openClaw();
				
			moveStraight(400); //50cm
			sleep(1); 
			createStop();  
				
			createCenter(0);
			moveArm(ARM_POS_START); 
			bmd(ARM_MOTOR_PORT); 
				
			moveStraight(100); //20cm
			sleep(1.9); 
			createStop(); 
			
			sleep(1); 
			closeClaw(); 
			sleep(1); 
			moveArm(ARM_POS_UP);
			
			moveStraight(-400); //-35cm
			sleep(1.05); 
			createStop();   
			
			turn(-90); 
			
			moveStraight(400); //75cm
			sleep(2.0); 
			createStop(); 
			
			turn(90); 
			
			moveStraight(400); //75cm
			sleep(1); 
			createStop();  
			
			createCenter(0); 
			
			moveStraight(100); 
			sleep(1.2); 
			createStop();
			
			moveStraight(-100); 
			sleep(.75); 
			createStop(); 
						
			sleep(1); 
			openClaw(); 
		}
	}
}
