#include "legobotFunctions.c"
#include "legobotConstants.h"
#include "boolean.h"

// BLOCKERS NEED TO START ON GROUND BEFORE ROUND, THEN CALL setStartingBlockers()
// ADJUST THE GATE TO BE PERPENDICULAR TO THE HOPPER
int main() {
	calibrateGate();
	setStartingBlockers();
	printf("press a button to start \n");
	while(1) {
			if(a_button() == 1) {
				break;
			}
			if(b_button() == 1) {
				moveToDistance(200, SLOW_SPEED);
				sleep(1);
				moveToDistance(-200, SLOW_SPEED);
			}

	}
	//code for right side

    //raiseBlockers();
    moveToDistance(52, FAST_SPEED);//moves forward, pushing away blocks and collecting ping pong balls
	sleep(.7);
    moveToDistance(-20, FAST_SPEED);//moves back to move around blocks
	
    turnArc(0, 23, FAST_SPEED, 60);//arcs around blocks
    pivot(1,82,FAST_SPEED);
	
	//turnArc(1, 30, FAST_SPEED, 52);
	moveToDistance(145, FAST_SPEED); //hits North wall near the drop zone				
	
	
	
	moveToDistance(-25,FAST_SPEED);//backs up to allow for turn
	turn(-90,SLOW_SPEED);//turns to face West
	moveToDistance(65, FAST_SPEED); //align with pvc on West
	moveToDistance(-10, FAST_SPEED); //backs up to allow for turn. 10 is best.
	turn(-93, SLOW_SPEED);//turns to face blocks, South
	moveToDistance(25, FAST_SPEED); //moves blocks out of the way
	moveToDistance(3.5, FAST_SPEED);//got all the biofuels
	turnArc(1, 50, -SLOW_SPEED, -10);
	
	moveToDistance(-55,FAST_SPEED);
	moveToDistance(4, FAST_SPEED);
	//turnArc(1,50,-SLOW_SPEED,-10);
	
	turnArc(1, 20, FAST_SPEED, 92); //100 is compensation
	moveToDistance(100, FAST_SPEED);
	pivot(0, -94, SLOW_SPEED); //runs into wall. 96 is compensation
	moveToDistance(55, FAST_SPEED);
	moveStraight(200);
	gateOpen();
}


