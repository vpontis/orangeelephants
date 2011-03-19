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
				wait_for_light(LIGHT_PORT);
				shut_down_in(117);
				printf("\n Starting side A");
				//LEG 1: collects ping pong balls @ first station
				moveToDist(49, MED_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
				moveToDist(-4, FAST_SPEED); //moves back to avoid tampering the red towers	
				sleep(2.5);
				pivot(0,-90,FAST_SPEED); //pivots -90 degrees CW
				moveToDist(-7,FAST_SPEED);//moves back to avoid pivoting on black tape
				pivot(1,-100,FAST_SPEED); //pivots -100 degrees CCW
				//pivot(1,18,FAST_SPEED);
				
				//moveToDist(120,FAST_SPEED); //split into two distances in following lines
				moveToDist(87, FAST_SPEED);//head to North PVC, the two distances should add up to 140
				pivot(1,-90,FAST_SPEED);//pivot out of the way
				moveToDist(-15,FAST_SPEED);
				sleep(6.5);
				moveToDist(10,FAST_SPEED);
				pivot(1,93,FAST_SPEED);
				moveToDist(65,FAST_SPEED);
				//moveToDist(80, FAST_SPEED); //starts distance to hit north PVC
				//sleep(5); //to wait for the create to go past
				//moveToDist(80,FAST_SPEED); //finish distance
				
				//LEG 3: collects ping pong balls @ second station				
				moveToDist(-22,FAST_SPEED); //backs up to allow for turn
				turn(-90,SLOW_SPEED); //pivots to face west PVC
				moveToDist(40,FAST_SPEED); //aligns with west PVC
				moveToDist(-5,FAST_SPEED); //backs up to allow for turn
				turn(-87,SLOW_SPEED); //pivots to face south PVC & ping pong balls
				moveToDist(20, FAST_SPEED); //collects all biofuels
				sleep(.7);
				moveToDist(-10,FAST_SPEED); //backs up so that bot won't turn on tape when arriving at drop zone
				
				//LEG 4: drop all biofuels
				turnArc(1, 50, -MED_SPEED, -4); //arcs back and hits north PVC <-reverted
				moveToDist(-45,SLOW_SPEED-100); //aligns with north PVC
				moveToDist(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(1, 95, FAST_SPEED); //pivots to face final east PVC
				moveToDist(100, FAST_SPEED); //moves and aligns with east PVC
				moveToDist(-27, FAST_SPEED); //moves back to align with drop zone and avoid tape
				pivot(0, -80, FAST_SPEED); //pivots to face drop zone
				moveToDist(50, FAST_SPEED); //drives to and aligns with drop zone (north PVC)
				gateOpen(); //drops all biofuels
				
				//LEG 5: navigate
				gateClose();
				moveToDist(-70,FAST_SPEED); //go to middle of board
				pivot(1,-97,FAST_SPEED); //turn to face back to middle bump
				//gateOpen(); //incase the other dump didn't empty the balls
				moveToDist(-110,SUPER_SPEED); //go backward over bump
					
				//LEG 6: screwing with the opponent bots
				moveToDist(-70,FAST_SPEED);
				while(1){
					moveToDist(60,FAST_SPEED);
					moveToDist(-70,FAST_SPEED);
				}
			}

			if(b_button())
			{
				wait_for_light(LIGHT_PORT);
				shut_down_in(117);
				printf("\n Starting side B");
				//LEG 1: collects ping pong balls @ first station
				moveToDist(50.5, MED_SPEED);
				sleep(.2);
				moveToDist(3, MED_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
				moveToDist(-8, FAST_SPEED); //moves back to avoid tampering the red towers	
				sleep(2.5);
				pivot(1,-90,FAST_SPEED); //pivots -90 degrees CCW
				moveToDist(-5,FAST_SPEED);//moves back to avoid pivoting on black tape
				pivot(0,-85,FAST_SPEED); //pivots -90 degrees CW
				
				moveToDist(82, FAST_SPEED);//head to North PVC, the two distances should add up to 120
				pivot(0,-70,FAST_SPEED);//pivot and allow Create to pass
				moveToDist(-13,FAST_SPEED);
				sleep(6.5);//wait for Create to pass
				moveToDist(13,FAST_SPEED);
				pivot(0,85, FAST_SPEED);
				moveToDist(72, FAST_SPEED);
				
//				moveToDist(80, FAST_SPEED); //starts distance to hit north PVC
//				sleep(5); //to wait for the create to go past
//				moveToDist(80,FAST_SPEED); //finish distance
				
				//LEG 3: collects ping pong balls @ second station
				
				moveToDist(-20,FAST_SPEED); //backs up to allow for turn
				turn(90,SLOW_SPEED); //pivots to face east PVC
				moveToDist(60,FAST_SPEED); //aligns with east PVC
				moveToDist(-6,FAST_SPEED); //backs up to allow for turn
				turn(89,SLOW_SPEED); //pivots to face south PVC & ping pong balls
				moveToDist(18, FAST_SPEED); //collects all biofuels
				sleep(.7);
				
				//LEG 4: drop all biofuels			
				turnArc(0, 50, -MED_SPEED, -4); //arcs back and hits north PVC <-reverted
				moveToDist(-45,SLOW_SPEED-100); //aligns with north PVC
				moveToDist(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(0, 99, FAST_SPEED); //pivots to face final east PVC
				moveToDist(100, FAST_SPEED); //moves and aligns with east PVC
				moveToDist(-43,FAST_SPEED);
				pivot(0, 85, FAST_SPEED); //pivots to face drop zone
				moveToDist(50, FAST_SPEED); //drives to and aligns with drop zone (north PVC)
				gateOpen(); //drops all biofuels
				
				//LEG 5: navigate to other side				
				
				moveToDist(-75,FAST_SPEED); //go to middle of board
				pivot(0,-105,FAST_SPEED); //turn to face back to middle bump
				//gateOpen(); //incase the other dump didn't empty the balls
				moveToDist(-110,SUPER_SPEED); //go backward over bump
					
				//LEG 6: screwing with the opponent bots
				moveToDist(-70,FAST_SPEED);
				while(1){
					moveToDist(60,FAST_SPEED);
					moveToDist(-70,FAST_SPEED);
				}	
			}	
	}		
}
