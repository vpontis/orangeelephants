#include "createFunctions.h"
#include "createConstants.h"

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
