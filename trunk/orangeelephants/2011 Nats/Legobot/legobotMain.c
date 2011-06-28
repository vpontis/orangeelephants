#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {
	set_servo_position(CLAW_PORT,CLAW_CLOSE); //initialize closed
	set_servo_position(ARM_PORT,ARM_VERT); // initialize up
	enable_servos();
	
/*	drive forward ??? cm (~3cm before hitting the structure); lower arm to 550; open claw; 	lower arm to 850; 		close claw; raise arm; reverse. */
	
	moveToDist(31,500);
	moveArm(550); //pos where to open claw
	openClaw();
	moveArm(850); //pos where to grab both at once
	closeClaw();
	moveArm(ARM_VERT);
	moveToDist(-31,500);




/*
	closeClaw();
	printf("closing");
	sleep(2);		
	raiseArm();
	printf("raising");	
	sleep(2);

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
*/
}

