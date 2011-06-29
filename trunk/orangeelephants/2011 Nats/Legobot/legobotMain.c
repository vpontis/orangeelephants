#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {
	set_servo_position(CLAW_PORT,CLAW_CLOSE); //initialize closed
	set_servo_position(ARM_PORT,ARM_VERT); // initialize up
	enable_servos();
	
/*	drive forward ??? cm (~3cm before hitting the structure); lower arm to 550; open claw; 	lower arm to 850; 		close claw; raise arm; reverse. */
	
	//pick up second airplane
	moveToDist(29,500);
	moveArm(550); //pos where to open claw
	openClaw();
	moveArm(850); //pos where to grab both at once
	closeClaw();
	moveArm(ARM_VERT);
	
	//move to the side of the board opposite to the starting boxes
	moveToDist(-3,500);
	pivot(1,90,500);
	moveToDist(200,800);
	
	//drop off first two airplanes
	moveToDist(-6,500);
	pivot(1,90,500);
	moveToDist(50,500);
	moveArm(850);
	openClaw();
	moveArm(ARM_VERT);
	closeClaw();
	
	//pick up third airplane
	pivot(1,-90,500);
	moveToDist(15,500);
	openClaw();
	moveArm(ARM_HORIZONTAL);
	closeClaw();
	moveArm(ARM_VERT);
	
	//drop off third airplane
	moveToDist(-6,500);
	pivot(1,45,500);
	moveToDist(20,500);
	moveArm(850);
	openClaw();
	moveArm(ARM_VERT);
	closeClaw();
	/**
	//make sure airplanes dont fall on top of each other
	moveArm(ARM_HORIZONTAL);
	moveToDist(-4,500);
	moveToDist(4,500);
	moveToDist(-4,500);
	moveToDist(4,500);
	*/

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

