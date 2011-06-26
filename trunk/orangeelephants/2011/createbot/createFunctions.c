#include "createFunctions.h"
#include "createConstants.h"
#include "createVision.c"
#include "createMotor.c"

/** \brief Connects create to CBC and sets to full mode.
*/
void createInitialize()
{
	int conVal = create_connect();
	if(conVal == 0){
		printf("Connection success. Setting to full mode...");
	}
	else{
		printf("Connection failed.");
	}
	
	//connected successfully! Place in full mode. 
	create_full();
}

/** \brief Function to move horizontal slider system
	\todo seperate into individual functions
*/
void moveSlider(int pos, int speed){
	clear_motor_position_counter(SLIDER_BACK);
	clear_motor_position_counter(SLIDER_FRONT);
	
	//TODO: Move commands into seperate functions
	mrp(SLIDER_BACK, speed, pos);
	mrp(SLIDER_FRONT, -speed, pos);
	bmd(SLIDER_BACK);
	bmd(SLIDER_FRONT);
	
	clear_motor_position_counter(SLIDER_BACK);
	clear_motor_position_counter(SLIDER_FRONT);
}

/** \brief Closes hopper
*/
void closeHopper(){
	set_servo_position(HOPPER, HOPPER_CLOSE);
}



