#include "legobotConstants.h"
#include "legobotFunctions.h"

// *******************USE CENTIMETERS*********************

void moveToDist(float distance, int speed) {
	clear_motor_position_counter(L_MOTOR); 
	clear_motor_position_counter(R_MOTOR); 
	if (distance > 0) {
		while(get_motor_position_counter(R_MOTOR) < cmToTicks(distance)) {
			mav(R_MOTOR, speed);
			mav(L_MOTOR, speed);	   
		}
	}
	else {
		while (get_motor_position_counter(R_MOTOR) > cmToTicks(distance)) {
			mav(R_MOTOR, -speed); 
			mav(L_MOTOR, -speed);   
		}
	}
	mav(L_MOTOR, 0);
	mav(R_MOTOR, 0);
}

float cmToTicks(float cmDistance) {         // return ticks the motors need to turn to go that distance
        return (float) (cmDistance * TICKS_PER_CM);        
}

/* #####obsolete with moveArm; just feed in the required constant#####
void raiseArm() {	
	int position = get_servo_position(ARM_PORT);
	while (position >= ARM_VERT) {
		set_servo_position(ARM_PORT,position);
		position -= ARM_INCR;
	}
}

void lowerArm() {
	int position = get_servo_position(ARM_PORT);
	while (position <= ARM_HORIZONTAL) {
		set_servo_position(ARM_PORT,position);
		position += ARM_INCR;
	}
} */

void moveArm(pos) {
	int position = get_servo_position(ARM_PORT);
	while (position < pos) {
		set_servo_position(ARM_PORT,position);
		position += ARM_INCR;
	}
	while (position > pos) {
		set_servo_position(ARM_PORT,position);
		position -= ARM_INCR;
	}
}

void openClaw() {
	int position = get_servo_position(CLAW_PORT);
	while (position <= CLAW_OPEN) {
		set_servo_position(CLAW_PORT,position);
		position += CLAW_INCR;
	}
}

void closeClaw() {
	int position = get_servo_position(CLAW_PORT);
	while (position >= CLAW_CLOSE) {
		set_servo_position(CLAW_PORT, position);
		position -= CLAW_INCR;
	}
}

void pivot(int aroundLeftWheel, float degrees, int speed) 
{
	int ticks = (degrees/360) * TICKS_PER_REV; // fraction of circle's circumference * ticks for a whole circle
											   // 1 circle = circle with radius distance between middle of the wheels
	if(aroundLeftWheel == 1) {
		mrp(R_MOTOR, speed, ticks);
		bmd(R_MOTOR);
	}
	else {
		mrp(L_MOTOR, speed, ticks);
		bmd(L_MOTOR);
	}
}	