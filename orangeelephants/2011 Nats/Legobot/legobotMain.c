#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {
printf("Press A for Side A or B for Side B");
while(1)
{	
if(a_button())
{
	shut_down_in(117);
	printf("\n Starting side A\nSleeping 10 seconds.");
	sleep(10);
	//init
	set_servo_position(CLAW_PORT,CLAW_CLOSE); //initialize closed
	set_servo_position(ARM_PORT,ARM_VERT); // initialize up
	enable_servos();
	
	//move to the side of the board opposite to the starting boxes
	moveToDist(20,500);
	pivot(0,90,500);
	moveToDist(35,500);
	moveArm(130);
	pivot(1,90,500);
	sleep(12);
	moveToDist(150,800);
	moveToDist(50,500);
	
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
	moveToDist(-2,500);
	moveArm(ARM_VERT);
	closeClaw();
	moveToDist(10,500);
}

if(b_button())
{

	shut_down_in(117);
	printf("\n Starting side B\nSleeping 10 seconds");

	//init
	set_servo_position(CLAW_PORT,CLAW_CLOSE); //initialize closed
	set_servo_position(ARM_PORT,ARM_VERT); // initialize up
	enable_servos();
	
	//move to the side of the board opposite to the starting boxes
	sleep(10);
	moveToDist(20,500);
	pivot(1,90,500);
	moveToDist(35,500);
	moveArm(130);
	moveToDist(-3,500);
	pivot(0,85,500);
	sleep(12);
	moveToDist(150,800);
	moveToDist(50,500);
	
	//drop off first two airplanes
	moveToDist(-5,500);
	pivot(0,85,500);
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
	moveToDist(-2,500);
	moveArm(ARM_VERT);
	closeClaw();
	moveToDist(10,500);
} //end if b_button
} //end while loop
} //end main