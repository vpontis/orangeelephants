#include "legobotFunctions.c"
#include "legobotConstants.h"
#include "boolean.h"


// BLOCKERS NEED TO START ON GROUND BEFORE ROUND, THEN CALL setStartingBlockers()

int main() {
/*	calibrateGate();
	sleep(1);
	moveToDistance(10,500);
	gateOpen();
	moveToDistance(10,500);
	gateClose();
	turnArc(1, 30, 400, 90);
*/
	//THIS IS THE START OF THE ROUTINE... DONT DELETE IT
	calibrateGate();
	setStartingBlockers();

	printf("press a button to start \n ");
	while(1) {
			if(a_button() == 1) {
					break;
			}
	}
	moveToDistance(23,700);
	raiseBlockers();
	moveToDistance(25.5,700);
	sleep(0.5);
	moveToDistance(3.5,700);
	moveToDistance(-25,1000);
	turnArc(0,26,700,65);
	moveToDistance(120,1000);
	moveToDistance(-8,300);
	mrp(3, 1000, 1722);
	moveToDistance(45,1000);
	gateOpen();
	

	printf("press a button to start \n ");
	while(1) {
			if(a_button() == 1) {
					break;
			}
	}
	moveToDistance(23,500);
	raiseBlockers();
	moveToDistance(26.5,500);
	sleep(2);
	moveToDistance(-25,500);
	turnArc(0,28,500,72);
	moveToDistance(120,500);
	moveToDistance(-8,300);
	turn(-90,300);
	moveToDistance(55,500);
	gateOpen();
	

}
