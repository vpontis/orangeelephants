#include "create_joystick_constants.h"
#include "create_constants.h"
#include "boolean.h"
#include "create_appendages.c"

int sensorsChanged();
int sensStates[NUM_SENS];

int main() {
	create_connect();
	boolean isDozerDown = true;
	while (1) {
		if (sensorsChanged()) {
			int lWheel = 0;
			int rWheel = 0;
			if(LB){
				lWheel = -CREATE_SPEED;
				rWheel = (UB ? -CREATE_SPEED/2: CREATE_SPEED);
				rWheel = (DB ? CREATE_SPEED/2: CREATE_SPEED);
			}
			else if(RB){
				rWheel = -CREATE_SPEED;
				lWheel = (UB ? -CREATE_SPEED/2: CREATE_SPEED);
				lWheel = (DB ? CREATE_SPEED/2: CREATE_SPEED);
			}
			else if(UB){
				rWheel = -CREATE_SPEED;
				lWheel = -CREATE_SPEED;
			}
			else if(DB){
				rWheel = CREATE_SPEED;
				lWheel = CREATE_SPEED;
			}
			int armSpeed = 0;
			if(AUB){
				armSpeed = -ARM_SPEED;
			}
			else if(ADB){
				armSpeed = ARM_SPEED;
			}
			if(SDB && !isDozerDown){
				dozer_down();
				isDozerDown = true;
			}
			else if(SUB && isDozerDown){
				dozer_up();
				isDozerDown = false;
			}
			mav(ARM_MOTOR, armSpeed);			
			create_drive_direct(lWheel,rWheel);
		}
		sleep(0.05);
	}
}

int sensorsChanged() {
	int i = 0;
	int j = 0;
	int hasChanged = 0; 
	for(i=0; i < NUM_SENS; i++) {
		if(digital(dPadPortMap[i])!=sensStates[i]) {
			sensStates[i] = digital(dPadPortMap[i]);
			hasChanged = 1;
		}
	}
	return hasChanged;
}

