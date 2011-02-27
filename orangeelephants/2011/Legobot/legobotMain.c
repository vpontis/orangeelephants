#include "legobotFunctions.c"
#include "legobotConstants.h"


// BLOCKERS NEED TO START ON GROUND BEFORE ROUND, THEN CALL setStartingBlockers()

int main() {
	/*setStartingBlockers();
	sleep(10);
	moveToDistance(30,500);
	raiseBlockersVertical();
	moveToDistance(18.5,500);
	sleep(2);
	moveToDistance(-10,500);
	turn(-90,250);
	moveToDistance(-30,500);*/
	while(1) {
		if(right_button() == 1) {
			turn(90,500);
		}
		else if(left_button() == 1) {
			turn(-90,500);
		}
		else if(a_button() == 1) {
			turnArc(1,20,400,90);
		}
		else if(b_button() == 1) {
			turnArc(0,20,400,90);
		}
		else if(black_button() == 1) {
			break;
		}
		else if(up_button() == 1) {
			moveToPosition(10,500);
		}
		else if(down_button() == 1) {
			moveToPosition(-10,500);
		}
	}
}
