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

void raiseArm() {
	int position = get_servo_position(ARM_PORT);
	while (position > ARM_VERTICAL) {
		set_servo_position(ARM_PORT,position);
		position -= ARM_INCR;
	}
	set_servo_position(ARM_PORT, ARM_VERTICAL); 
}

void lowerArm() {
	int position = get_servo_position(ARM_PORT);
	while (position < ARM_HORIZONTAL) {
		set_servo_position(ARM_PORT,position);
		position += ARM_INCR;
	}
	set_servo_position(ARM_PORT, ARM_HORIZONTAL); 
}

void openClaw() {
	int position = get_servo_position(CLAW_PORT);
	while (position < CLAW_OPEN) {
		set_servo_position(CLAW_PORT,position);
		position += CLAW_INCR;
	}
	set_servo_position(CLAW_PORT, CLAW_OPEN);
}

void closeClaw() {
	int position = get_servo_position(CLAW_PORT);
	while (position > CLAW_CLOSE){
		set_servo_position(CLAW_PORT, position);
		position -= CLAW_INCR;
	}
	set_servo_position(CLAW_PORT, CLAW_CLOSE); 
}
