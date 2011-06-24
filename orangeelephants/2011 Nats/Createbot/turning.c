#include "turning.h"
#include "math.c"

//use this if you want multiple turns
void turn(int degrees) {
	int numTurns = (int) f_abs(degrees/90);
	int i; 	
	for (i = 0; i < numTurns; i++) {
		if (degrees < 0) {
			turnCW(); 
			sleep(.6); //turns get innacurate without sleeps
		}
		else {
			turnCCW(); 
			sleep(.6); //turns get innacurate without sleeps 
		}
	}
}

void turnCCW() { //90 degree turn counterclockwise
	//set_create_total_angle(0); 
	create_drive(101,1); 
	sleep(2.057252314);
	create_stop(); 
}


void turnCW() { //90 degree turn clockwise
	//set_create_total_angle(0); 
	create_drive(-101,1); 
	sleep(2.057252314);
	create_stop(); 
}

