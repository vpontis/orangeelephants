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
	moveToDistance(23,500);
    raiseBlockers();
    moveToDistance(25.5,500);
    sleep(0.5);
    moveToDistance(3.5,500);
    moveToDistance(-20,1000);
    turnArc(0,26,700,60);
    turnArc(1,28,700,55);
	moveToDistance(105,1000);
	moveToDistance(-22,1000);
	turn(-90,500);
	moveToDistance(20,1000);
	moveToDistance(-6,1000); //tested: moving back 6 lines up with the wall best
	turn(-90,500);
	moveToDistance(40,500);
}