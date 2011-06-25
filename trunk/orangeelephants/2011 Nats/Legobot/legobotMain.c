#include "legobotFunctions.c"
#include "legobotConstants.h"

int main() {
	set_servo_position(CLAW_PORT,1800);
	set_servo_position(ARM_PORT,1100);
	enable_servos();

	openClaw();
	printf("sleep");
	sleep(4);
	raiseArm();
	printf("sleeping");
	sleep(4);
	lowerArm();
	printf("sleeping");
	sleep(4);
	closeClaw();
	printf("sleep");
	sleep(4);
	raiseArm();
}

