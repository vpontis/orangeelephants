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
		if (b_button()) {
			closeClaw(); 
			
			moveStraight(400); //55cm
			sleep(1.5); 
			createStop(); 
				
			turn(90); 
			openClaw();
				
			moveStraight(400); //50cm
			sleep(1.1); 
			createStop();  
				
			createCenter(0);
			moveArm(ARM_POS_START); 
			bmd(ARM_MOTOR_PORT); 
				
			moveStraight(100); //20cm
			sleep(1.2); 
			createStop(); 
			
			sleep(1); 
			closeClaw(); 
			sleep(1); 
			moveArm(ARM_POS_UP);
			
			moveStraight(-400); //-35cm
			sleep(.84); 
			createStop();   
			
			turn(-90); 
			
			moveStraight(400); //75cm
			sleep(2.0); 
			createStop(); 
			
			turn(97); 
			
			moveStraight(400); //75cm
			sleep(.95); 
			createStop();  
			
			createCenter(0); 
			
			moveStraight(100); 
			sleep(1.1); 
			createStop();
						
			sleep(1); 
			openClaw(); 
		}
	}
}
