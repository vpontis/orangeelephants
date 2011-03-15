#include "legobotFunctions.c"
#include "legobotConstants.h"
#include "boolean.h"

//**NOTE: adjust the gate to be perpendicular to the ground before presesing the black or 'A' button
int main() {
	
	calibrateGate();
	setStartingBlockers();
	
	printf("Press 'A' to start if you are on Side A.\nPress 'B' to start if you are on Side B.\n");
	
	while(1) 
	{
			if(a_button()) 
			{
				shut_down_in(117);
				printf("\n Starting side A");
				sleep(5); //wait for create
				//LEG 1: collects ping pong balls @ first station
				moveToDistance(49, MED_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
			
				moveToDistance(-2, FAST_SPEED); //moves back to avoid tampering the red towers	
				pivot(0,-90,FAST_SPEED); //pivots -90 degrees CW
				moveToDistance(-7,FAST_SPEED);//moves back to avoid pivoting on black tape
				pivot(1,-80,FAST_SPEED); //pivots -65 degrees CCW
				turnArc(0,98,FAST_SPEED,10);
				pivot(1,12,FAST_SPEED);
				sleep(5);
				moveToDistance(120,FAST_SPEED);
				
				//moveToDistance(80, FAST_SPEED); //starts distance to hit north PVC
				//sleep(5); //to wait for the create to go past
				//moveToDistance(80,FAST_SPEED); //finish distance
				
				//LEG 3: collects ping pong balls @ second station
				
				moveToDistance(-22,FAST_SPEED); //backs up to allow for turn
				turn(-90,SLOW_SPEED); //pivots to face west PVC
				moveToDistance(35,FAST_SPEED); //aligns with west PVC
				moveToDistance(-7,FAST_SPEED); //backs up to allow for turn
				turn(-89,SLOW_SPEED); //pivots to face south PVC & ping pong balls
				moveToDistance(20, FAST_SPEED); //collects all biofuels
				sleep(.7);
				
				//LEG 4: drop all biofuels
			
				turnArc(1, 50, -MED_SPEED, -4); //arcs back and hits north PVC <-reverted
				moveToDistance(-55,MED_SPEED); //aligns with north PVC
				moveToDistance(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(1, 96, FAST_SPEED); //pivots to face final west PVC
				moveToDistance(100, FAST_SPEED); //moves and aligns with west PVC
				pivot(0, -83, FAST_SPEED); //pivots to face drop zone
				moveToDistance(50, FAST_SPEED); //drives to and aligns with drop zone (north PVC)
				gateOpen(); //drops all biofuels
				
				//LEG 5: navigate and drop blockers
				
				gateClose();
				moveToDistance(-20,FAST_SPEED); //back up
				pivot(0, 90, FAST_SPEED); //pivot to face east PVC
				moveToDistance(30,FAST_SPEED); //Wall align against east PVC
				moveToDistance(-55,FAST_SPEED); //go back to wall align to middle pvc
				pivot(1,90, FAST_SPEED); //turn to face front of bot to north PVC
				moveToDistance(20,FAST_SPEED); //forward wall align to north PVC
				moveToDistance(-85,FAST_SPEED); //go to middle of board
				pivot(1,-98,FAST_SPEED); //turn to face back to middle bump
				gateOpen(); //incase the other dump didn't empty the balls
				moveToDistance(-100,SUPER_SPEED); //go backward over bump
					
				//LEG 6: screwing with the opponent bots
				moveToDistance(-55,FAST_SPEED);
				while(1){
					moveToDistance(70,FAST_SPEED);
					moveToDistance(-70,FAST_SPEED);
				}
				
				
			}

			if(b_button())
			{
				shut_down_in(117);
				printf("\n Starting side B");
				sleep(5); //wait for create
				//LEG 1: collects ping pong balls @ first station
				moveToDistance(49, MED_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
			
				moveToDistance(-4, FAST_SPEED); //moves back to avoid tampering the red towers	
				pivot(1,-90,FAST_SPEED); //pivots -90 degrees CCW
				moveToDistance(-7,FAST_SPEED);//moves back to avoid pivoting on black tape
				pivot(0,-65,FAST_SPEED); //pivots -65 degrees CW
				turnArc(1,98,FAST_SPEED,10);
				pivot(0,12,FAST_SPEED);
				sleep(5);
				moveToDistance(120,FAST_SPEED);
				
//				moveToDistance(80, FAST_SPEED); //starts distance to hit north PVC
//				sleep(5); //to wait for the create to go past
//				moveToDistance(80,FAST_SPEED); //finish distance
				
				//LEG 3: collects ping pong balls @ second station
				
				moveToDistance(-22,FAST_SPEED); //backs up to allow for turn
				turn(90,SLOW_SPEED); //pivots to face east PVC
				moveToDistance(35,FAST_SPEED); //aligns with east PVC
				moveToDistance(-7,FAST_SPEED); //backs up to allow for turn
				turn(89,SLOW_SPEED); //pivots to face south PVC & ping pong balls
				moveToDistance(20, FAST_SPEED); //collects all biofuels
				sleep(.7);
				
				//LEG 4: drop all biofuels
			
				turnArc(0, 50, -MED_SPEED, -4); //arcs back and hits north PVC <-reverted
				moveToDistance(-55,MED_SPEED); //aligns with north PVC
				moveToDistance(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(0, 96, FAST_SPEED); //pivots to face final east PVC
				moveToDistance(100, FAST_SPEED); //moves and aligns with east PVC
				pivot(1, -83, FAST_SPEED); //pivots to face drop zone
				moveToDistance(50, FAST_SPEED); //drives to and aligns with drop zone (north PVC)
				gateOpen(); //drops all biofuels
				
				//LEG 5: navigate and drop blockers
				
				gateClose();
				moveToDistance(-20,FAST_SPEED); //back up
				pivot(1, 90, FAST_SPEED); //pivot to face west PVC
				moveToDistance(30,FAST_SPEED); //Wall align against west PVC
				moveToDistance(-55,FAST_SPEED); //go back to wall align to middle pvc
				pivot(0,90, FAST_SPEED); //turn to face front of bot to north PVC
				moveToDistance(20,FAST_SPEED); //forward wall align to north PVC
				moveToDistance(-85,FAST_SPEED); //go to middle of board
				pivot(0,-98,FAST_SPEED); //turn to face back to middle bump
				gateOpen(); //incase the other dump didn't empty the balls
				moveToDistance(-100,SUPER_SPEED); //go backward over bump
					
				//LEG 6: screwing with the opponent bots
				moveToDistance(-55,FAST_SPEED);
				while(1){
					moveToDistance(70,FAST_SPEED);
					moveToDistance(-70,FAST_SPEED);
				}
				
			}
					
	}		
}
