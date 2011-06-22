#include "legobotConstants.h"
#include "legobotFunctions.h"
#include "boolean.h"
// *******************USE CENTIMETERS*********************


void raiseArm() {
	int position = get_servo_position(ARM_PORT);
	while (position > CLAW_VERTICAL){
		position -= 15;
		set_servo_position(ARM_PORT,position);
	}
}
}
