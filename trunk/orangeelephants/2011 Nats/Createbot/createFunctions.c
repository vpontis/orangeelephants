#include "createFunctions.h"
#include "createVision.c"
#include "createMotor.c"

void createInitialize()
{
	int conVal = create_connect();
	if(conVal == 0){
		printf("Connection success. Setting to full mode...");
	}
	else{
		printf("Connection failed.");
	}
	create_full();
}

//Moves the claw to pinch the blocks up until it hits the sensor
void moveSlider(int pos, int speed){
	
	clear_motor_position_counter(SLIDER_BACK);
	clear_motor_position_counter(SLIDER_FRONT);

	mrp(SLIDER_BACK, speed, pos);
	mrp(SLIDER_FRONT, -speed, pos);
	bmd(SLIDER_BACK);
	bmd(SLIDER_FRONT);
	
	clear_motor_position_counter(SLIDER_BACK);
	clear_motor_position_counter(SLIDER_FRONT);
}

void closeHopper(){
	set_servo_position(HOPPER, HOPPER_CLOSE);
}

void openClaw() {
	set_servo_position(CLAWL_SERVO_PORT, CLAWL_OPEN_POS); 
	set_servo_position(CLAWR_SERVO_PORT, CLAWR_OPEN_POS); 
}

void closeClaw() {
	set_servo_position(CLAWL_SERVO_PORT, CLAWL_CLOSE_POS); 
	set_servo_position(CLAWR_SERVO_PORT, CLAWR_CLOSE_POS); 
}

void calibrateArm() { //beginning of game
	printf("Set arm at the bottom. Black Button to break"); 
	while (1) {	
		if (up_button()) {
			mrp(ARM_MOTOR_PORT, 800, 20); 
		}
		if (down_button()) {
			mrp(ARM_MOTOR_PORT, -800, -20); 
		}
		if (black_button()) {
			mrp(ARM_MOTOR_PORT, 800, 6195);  
			clear_motor_position_counter(ARM_MOTOR_PORT); 
			break; 
		}
	}
}

void moveArm(int pos) {
	printf("moving arm"); 
	mtp(ARM_MOTOR_PORT, 850, pos); //850 needs to be calibrated
	bmd(ARM_MOTOR_PORT); 
}