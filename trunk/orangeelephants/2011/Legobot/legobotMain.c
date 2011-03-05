#include "legobotFunctions.c"
#include "legobotConstants.h"
#include "boolean.h"


// BLOCKERS NEED TO START ON GROUND BEFORE ROUND, THEN CALL setStartingBlockers()

int main() {
/*	calibrateGate();
	sleep(1);
	moveToDistance(10,SLOW_SPEED);
	gateOpen();
	moveToDistance(10,SLOW_SPEED);
	gateClose();
	turnArc(1, 30, SLOW_SPEED, 90);
*/
	//THIS IS THE START OF THE ROUTINE... DONT DELETE IT
	calibrateGate();
	setStartingBlockers();FAST_SPEED
	printf("press a button to start \n ");
	while(1) {
			if(a_button() == 1) {
					break;
			}
	}
	//code for right side
	
    raiseBlockers();
    moveToDistance(48.5,NORMAL_SPEED);
    sleep(0.5);
    moveToDistance(3.5,SLOW_SPEED);
    moveToDistance(-20,FAST_SPEED);
    turnArc(0,26,SLOW_SPEED,60);
    turnArc(1,30,SLOW_SPEED,52); //52 is compensation
	moveToDistance(105,FAST_SPEED);				
	
	
	
	moveToDistance(-25,FAST_SPEED);
	turn(-90,400);
	moveToDistance(50,FAST_SPEED);
	moveToDistance(-9,FAST_SPEED); //tested: moving back 7cm lines up with the wall best
	turn(-93,400);
	moveToDistance(30,FAST_SPEED);
	sleep(1);
	moveToDistance(3.5,SLOW_SPEED); 
	turnArc(1,50,-SLOW_SPEED,-10);
	
	moveToDistance(-55,SLOW_SPEED);
	turnArc(1,20,SLOW_SPEED,90); //100 is compensation
	moveToDistance(90,FAST_SPEED);
	pivot(0,-101,SLOW_SPEED); //runs into wall. 96 is compensation
	moveToDistance(55,FAST_SPEED);
	moveStraight(200);
	gateOpen();
	
	
	
	/*
	moveToDistance(50, FAST_SPEED);
	sleep(2);
	turnArc(1, 20, SLOW_SPEED, 45);
	sleep(2);
	turnArc(1, 40, SLOW_SPEED, 140);
	*/
	
	//code for left side
	/*
	moveToDistance(23,SLOW_SPEED);
    raiseBlockers();
    moveToDistance(25.5,NORMAL_SPEED);
    sleep(0.5);
    moveToDistance(3.5,SLOW_SPEED);SLOW_SPEED
    moveToDistance(-20,FAST_SPEED);
    turnArc(1,26,SLOW_SPEED,60);
    turnArc(0,30,SLOW_SPEED,52);
	moveToDistance(105,FAST_SPEED);
	moveToDistance(-20,FAST_SPEED);
	turn(90,SLOW_SPEED);
	moveToDistance(22,FAST_SPEED);
	moveToDistance(-6,FAST_SPEED); //tested: moving back 6 lines up with the wall best
	turn(90,SLOW_SPEED);
	moveToDistance(30,NORMAL_SPEED);
	sleep(0.5);
	moveToDistance(-20,NORMAL_SPEED);
	turnArc(0,26,SLOW_SPEED,100);
	moveToDistance(80,FAST_SPEED);
	moveToDistance(-6,NORMAL_SPEED);
	turn(90,500);
	moveToDistance(50,FAST_SPEED);
	gateOpen();
	*/
}



