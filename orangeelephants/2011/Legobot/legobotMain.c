#include "legobotFunctions.c"
#include "legobotConstants.h"


// BLOCKERS NEED TO START ON GROUND BEFORE ROUND, THEN CALL
//170 angled
//270 vertical

int main() {
	setStartingBlockers();
	sleep(10);
	moveToDistance(30,500);
	raiseBlockersVertical();
	moveToDistance(18.5,500);
	sleep(2);
	moveToDistance(-10,500);
	turn(-90,250);
	moveToDistance(-30,500);
}
