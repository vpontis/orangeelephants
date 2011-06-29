#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {
printf("Press A for Side A or B for Side B");
while(1)
{	
if(a_button())
{
	set_servo_position(CLAW_PORT,CLAW_CLOSE); //initialize closed
	set_servo_position(ARM_PORT,ARM_VERT); // initialize up
	enable_servos();
	
	
	//pick up second airplane
	moveToDist(54,500);
	moveArm(550); //pos where to open claw
	openClaw();
	moveArm(850); //pos where to grab both at once
	closeClaw();
	moveArm(130);
	
	//move to the side of the board opposite to the starting boxes
	moveToDist(-10,500);
	pivot(1,90,500);
	moveToDist(200,800);
	
	//drop off first two airplanes
	moveToDist(-5,500);
	pivot(1,90,500);
	moveToDist(80,500);
	moveArm(950);
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
	moveArm(950);
	openClaw();
	moveArm(ARM_VERT);
	closeClaw();
}

if(b_button())
{
	set_servo_position(CLAW_PORT,CLAW_CLOSE); //initialize closed
	set_servo_position(ARM_PORT,ARM_VERT); // initialize up
	enable_servos();
	
	
	//pick up second airplane
	moveToDist(54,500);
	moveArm(550); //pos where to open claw
	openClaw();
	moveArm(900); //pos where to grab both at once
	closeClaw();
	moveArm(130);
	
	//move to the side of the board opposite to the starting boxes
	moveToDist(-3,500);
	pivot(0,85,500);
	moveToDist(200,800);
	
	//drop off first two airplanes
	moveToDist(-5,500);
	pivot(0,90,500);
	moveToDist(80,500);
	moveArm(950);
	openClaw();
	moveArm(ARM_VERT);
	closeClaw();
	
	//pick up third airplane
	pivot(0,-90,500);
	moveToDist(15,500);
	openClaw();
	moveArm(ARM_HORIZONTAL);
	closeClaw();
	moveArm(ARM_VERT);
	
	//drop off third airplane
	moveToDist(-6,500);
	pivot(0,45,500);
	moveToDist(20,500);
	moveArm(950);
	openClaw();
	moveArm(ARM_VERT);
	closeClaw();
} //end if b_button
} //end while loop
} //end main