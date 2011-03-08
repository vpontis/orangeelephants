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
    moveToDistance(-6, FAST_SPEED);//moves back to move around blocks
	
	pivot(0,-90,FAST_SPEED);
	moveToDistance(-7,FAST_SPEED);
	pivot(1,-86,FAST_SPEED);
    //turnArc(0, 23, FAST_SPEED, 60);//arcs around blocks
	
	//CALIBRATE THIS VALUE!!!
    //pivot(1,86,FAST_SPEED); //NEED TO CALIBRATE EVERY DAY; currently 88 degrees
	
	//turnArc(1, 30, FAST_SPEED, 52);
	moveToDistance(160, FAST_SPEED); //hits North wall near the drop zone				
	
	moveToDistance(-28,FAST_SPEED);//backs up to allow for turn
	turn(-95,SLOW_SPEED);//turns to face West
	moveToDistance(65,FAST_SPEED); //align with pvc on West
	moveToDistance(-9,FAST_SPEED); //backs up to allow for turn. 10 is best.
	
	//CALIBRATE THIS VALUE!!!
	turn(-100,SLOW_SPEED);//turns to face blocks, South
	
	moveToDistance(25, FAST_SPEED); //moves blocks out of the way
	moveToDistance(3.5, FAST_SPEED);//got all the biofuels
	turnArc(1, 50, -SLOW_SPEED, -10);
	
	moveToDistance(-55,FAST_SPEED);
	moveToDistance(4, FAST_SPEED);
	//turnArc(1,50,-SLOW_SPEED,-10);
	
	pivot(1, 110, FAST_SPEED); //pivots to final right PVC; check angle
	moveToDistance(100, FAST_SPEED);
	pivot(0, -91, FAST_SPEED); //runs into wall. currently 91
	moveToDistance(55, FAST_SPEED);
	moveStraight(200);
	gateOpen();
	gateClose();

	moveToDistance(-50,FAST_SPEED);
	pivot(1, -90, FAST_SPEED);
	moveToDistance(30,FAST_SPEED);
	moveToDistance(-22,FAST_SPEED);
	pivot(0,-90,FAST_SPEED);
	
	moveToDistance(-35,FAST_SPEED);
	pivot(1,-120,FAST_SPEED);
	
	moveToDistance(-60,FAST_SPEED);
	moveToDistance(-100,SUPER_SPEED);//move back beyond black tape
	
	
	lowerBlockerLeft();
	moveToDistance(30, FAST_SPEED);
	lowerBlockerRight();
	moveToDistance(10, FAST_SPEED);
	pivot(1, 90, FAST_SPEED);//pivot to face north
	/*
	pivot(0, -55, FAST_SPEED);
	moveToDistance(-20,FAST_SPEED);
	pivot(1,-60,FAST_SPEED);
	
	moveToDistance(30,FAST_SPEED);
	sleep(0.5);
	moveToDistance(-120,SUPER_SPEED);
	
	lowerBlockerLeft();
	lowerBlockerRight();
	*/

}


