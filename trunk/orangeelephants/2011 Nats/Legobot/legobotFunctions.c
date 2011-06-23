#include "legobotConstants.h"
#include "legobotFunctions.h"

// *******************USE CENTIMETERS*********************


void raiseArm() {
	int position = get_servo_position(ARM_PORT);
	while (position > ARM_VERTICAL) {
		set_servo_position(ARM_PORT,position);
		position -= ARM_INCR;
	}
}

void lowerArm() {
	int position = get_servo_position(ARM_PORT);
	while (position < ARM_HORIZONTAL) {
		set_servo_position(ARM_PORT,position);
		position += ARM_INCR;
	}
}

void openClaw() {
	int position = get_servo_position(CLAW_PORT);
	while (position < CLAW_OPEN) {
		set_servo_position(CLAW_PORT,position);
		position += CLAW_INCR;
	}
}

void closeClaw() {
	int position = get_servo_position(CLAW_PORT);
	while (position > CLAW_CLOSE){
		set_servo_position(CLAW_PORT, position);
		position -= CLAW_INCR;
	}
}


