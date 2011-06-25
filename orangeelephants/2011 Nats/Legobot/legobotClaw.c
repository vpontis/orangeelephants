#include "legobotFunctions.c"

int main()
{
	clear_motor_position_counter(R_MOTOR); 
	clear_motor_position_counter(L_MOTOR);
	set_servo_position(ARM_PORT, 800); 
	set_servo_position(CLAW_PORT, 1600); 
	
	printf("A Button to start"); 
	while (1) {
		if (a_button()) {
			raiseArm(); 
			openClaw();  
			moveToDist(60, 500); 
			lowerArm(); 
			closeClaw(); 
			raiseArm(); 
		}
	}
}
	
