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
	//code for right side
	
    //raiseBlockers();
	/*
    moveToDistance(48.5,700);
    sleep(0.5);
    moveToDistance(3.5,500);
    moveToDistance(-20,1000);
    turnArc(0,26,500,60);
    turnArc(1,30,500,52); //52 is compensation
	moveToDistance(105,1000); //hits wall near the drop zone				
	
	*/
	
	moveToDistance(-25,1000);
	turn(-90,400);
	moveToDistance(50,1000); //align with pvc on left
	moveToDistance(-9,1000); //tested: moving back 7cm lines up with the wall best
	turn(-93,400);
	moveToDistance(30,1000);
	sleep(1);
	moveToDistance(3.5,500);//got all the biofuels
	turnArc(1,50,-500,-10);
	
	moveToDistance(-55,500);
	moveToDistance(4,400);
	
	turnArc(1,20,500,93); //100 is compensation
	moveToDistance(100,1000);
	pivot(0,-101,500); //runs into wall. 96 is compensation
	moveToDistance(55,1000);
	moveStraight(200);
	gateOpen();
	
	
	
	/*
	moveToDistance(50, 1000);
	sleep(2);
	turnArc(1, 20, 500, 45);
	sleep(2);
	turnArc(1, 40, 500, 140);
	*/
	
	//code for left side
	/*
	moveToDistance(23,500);
    raiseBlockers();
    moveToDistance(25.5,700);
    sleep(0.5);
    moveToDistance(3.5,500);
    moveToDistance(-20,1000);
    turnArc(1,26,500,60);
    turnArc(0,30,500,52);
	moveToDistance(105,1000);
	moveToDistance(-20,1000);
	turn(90,500);
	moveToDistance(22,1000);
	moveToDistance(-6,1000); //tested: moving back 6 lines up with the wall best
	turn(90,500);
	moveToDistance(30,700);
	sleep(0.5);
	moveToDistance(-20,700);
	turnArc(0,26,500,100);
	moveToDistance(80,1000);
	moveToDistance(-6,500);
	turn(90,500);
	moveToDistance(50,1000);
	gateOpen();
	*/
}


