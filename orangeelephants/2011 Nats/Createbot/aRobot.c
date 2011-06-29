#include "createFunctions.c"

int main()
{
	
	enable_servos();
	createInitialize();
	calibrateArm();
	bmd(ARM_MOTOR_PORT); 
	openClaw(); 
	sleep(2); 
	moveArm(ARM_POS_DOWN); 
	while (1) {
		if (a_button()) {
		double ratio = -90.0/90.0; 
		ratio = -ratio;
        	create_drive(101,1); 
        	sleep(2.057252314*ratio);
        	create_stop();
		}
		if (b_button()) {
			closeClaw();
			moveToDist(535,500); 
			turn(90); 
			openClaw(); 
			moveToDist(500,500);
			moveToDist(30,100); 
			sleep(1); 
			closeClaw(); 
			sleep(1); 
			moveArm(ARM_POS_START);
			moveToDist(-200,500);  
			turn(-90); 
			moveToDist(525,500);
			turn(90); 
			moveToDist(100,500); 
			openClaw(); 
		}
	}
}
