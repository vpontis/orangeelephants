#include "turning.c"
#include "createFunctions.c"

int main() {
	create_connect(); 
	while (1) {
		if (b_button()) {
			calibrateArm(); 
			openClaw(); 
			sleep(2); 
			moveArm(ARM_POS_DOWN); 
			sleep(5); 
			closeClaw(); 
			sleep(2); 
			moveArm(ARM_POS_START); 
			sleep(2); 
			turnCW(); 
			sleep(5); 
			openClaw(); 
		}
	}
}
