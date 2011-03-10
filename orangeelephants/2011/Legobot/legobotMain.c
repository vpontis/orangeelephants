#include "legobotFunctions.c"
#include "legobotConstants.h"
#include "boolean.h"

//**NOTE: adjust the gate to be perpendicular to the ground before presesing the black or 'A' button
int main() {
	
	calibrateGate();
	setStartingBlockers();
	
	printf("Press 'A' to start if you are on Side A.\nPress 'B' if you are on Side B.\n");
	
	while(1) 
	{
			if(a_button() == 1) 
			{
				//LEG 1: collects ping pong balls @ first station
	
				moveToDistance(52, FAST_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
				
				moveToDistance(-6, FAST_SPEED); //moves back to avoid tampering the red towers	
				pivot(0,-90,FAST_SPEED); //pivots -90 degrees CCW
				moveToDistance(-7,FAST_SPEED);//moves back to avoid pivoting on black tape
				pivot(1,-93,FAST_SPEED); //pivots -90 degrees CW
				moveToDistance(125, FAST_SPEED); //moves to and hits north PVC
				
				pivot(1,45,FAST_SPEED); //final pivot
				moveToDistance(50,FAST_SPEED);
				
				//LEG 3: collects ping pong balls @ second station
				
				moveToDistance(-25,FAST_SPEED); //backs up to allow for turn
				turn(-96,SLOW_SPEED);//turns to face West
				moveToDistance(65,FAST_SPEED); //aligns with west PVC
				moveToDistance(-9,FAST_SPEED); //backs up to allow for turn
				turn(-100,SLOW_SPEED);//turns to face blocks, South
				moveToDistance(27, FAST_SPEED); //collects all biofuels
				sleep(.7);
				
				//LEG 4: drop all biofuels
				
				turnArc(1, 50, -SLOW_SPEED, -10); //arcs back and hits north PVC
				moveToDistance(-55,FAST_SPEED); //aligns with north PVC
				moveToDistance(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(1, 119, FAST_SPEED); //pivots to face final east PVC
				moveToDistance(100, FAST_SPEED); //moves and aligns with east PVC
				pivot(0, -93, FAST_SPEED); //pivots to face drop zone
				moveToDistance(100, FAST_SPEED); //drives to and aligns with drop zone
				gateOpen(); //drops all biofuels
				
				//LEG 5: navigate and drop blockers
				
				/*
				gateClose();
				moveToDistance(-50,FAST_SPEED);
				pivot(1, -90, FAST_SPEED);
				
				moveToDistance(30,FAST_SPEED);
				moveToDistance(-22,FAST_SPEED);
				pivot(0,-90,FAST_SPEED);
				
				moveToDistance(-35,FAST_SPEED);
				pivot(1,-100,FAST_SPEED);
				
				moveToDistance(-60,FAST_SPEED);
				moveToDistance(-100,SUPER_SPEED);
				*/
				
				break;
			}
			//LEFT ****DONT MOD THIS YET****
			if(b_button() == 1)
			{
			//LEG 1: collects ping pong balls @ first station
	
			moveToDistance(52, FAST_SPEED);
			sleep(.7);
		
			//LEG 2: navigates to north PVC
		
			moveToDistance(-6, FAST_SPEED); //moves back to avoid tampering the red towers	
			pivot(1,-90,FAST_SPEED); //pivots -90 degrees CCW
			moveToDistance(-7,FAST_SPEED);//moves back to avoid pivoting on black tape
			pivot(0,-86,FAST_SPEED); //pivots -90 degrees CW
			moveToDistance(160, FAST_SPEED); //moves to and hits north PVC
			
			//LEG 3: collects ping pong balls @ second station
			
			moveToDistance(-25,FAST_SPEED); //backs up to allow for turn
			pivot(0,96,FAST_SPEED); //pivots to face west
			moveToDistance(65,FAST_SPEED); //aligns with west PVC
			moveToDistance(-9,FAST_SPEED); //backs up to allow for turn
			pivot(1,-100,FAST_SPEED); //pivots to face south PVC & ping pong balls
			moveToDistance(25, FAST_SPEED); //collects all biofuels
			sleep(.7);
		
			//LEG 4: drop all biofuels
		
			turnArc(1, 50, -SLOW_SPEED, 10); //arcs back and hits north PVC
			moveToDistance(-55,FAST_SPEED); //aligns with north PVC
			moveToDistance(4, FAST_SPEED); //moves slightly forward to leave room for pivot
			pivot(0, 100, FAST_SPEED); //pivots to face final east PVC
			moveToDistance(100, FAST_SPEED); //moves and aligns with east PVC
			pivot(1, -91, FAST_SPEED); //pivots to face drop zone
			moveToDistance(100, FAST_SPEED); //drives to and aligns with drop zone
			gateOpen(); //drops all biofuels
			
			//LEG 5: navigate and drop blockers
			
			gateClose();
			moveToDistance(-50,FAST_SPEED);
			pivot(0, -90, FAST_SPEED);
			
			moveToDistance(30,FAST_SPEED);
			moveToDistance(-22,FAST_SPEED);
			pivot(1,-90,FAST_SPEED);
			
			moveToDistance(-35,FAST_SPEED);
			pivot(0,-100,FAST_SPEED);
			
			moveToDistance(-60,FAST_SPEED);
			moveToDistance(-100,SUPER_SPEED);
			break;
			}
					
	}		
}