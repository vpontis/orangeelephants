#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {
	set_servo_position(CLAW_PORT,1200); //initialize closed
	set_servo_position(ARM_PORT,500); // initialize up
	enable_servos();

//	closeClaw();
//	printf("closing");
//	sleep(2);		
//	raiseArm();
//	printf("raising");	
//	sleep(2);

	interArm();
	sleep(2);

	openClaw();
	sleep(2);

	lowerArm();
	sleep(2);

	closeClaw();
	sleep(2);

	raiseArm();
	printf("done");	
	sleep(4);

	moveToDist(30,1000);

}

