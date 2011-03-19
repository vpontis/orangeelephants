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
			if(left_button())
			{
					int initL = get_motor_position_counter(1);
					int initR = get_motor_position_counter(0);
					mav(1, 900);
					mav(0, 900);
					sleep(5);
					freeze(0);
					freeze(3);
					int leftDist = initL-get_motor_position_counter(1);
					int rightDist = initR-get_motor_position_counter(0);
					printf("The left distance traveled is %d.\n", initL-get_motor_position_counter(1));
					printf("The right distance traveled is %d.\n", initR-get_motor_position_counter(0));
					float ratio = (float)leftDist/(float)rightDist;
					printf("Comp ratio is %.3f or %.3f.\n", ratio, 1.0/ratio);
			}
			if(a_button()) 
			{
				wait_for_light(LIGHT_PORT);
				shut_down_in(117);
				printf("\n Starting side A");
				//LEG 1: collects ping pong balls @ first station
				sleep(14.5);
				moveToDist(49, MED_SPEED);
				sleep(0.2);
				moveToDist(3, MED_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
				moveToDist(-6, FAST_SPEED); //moves back to avoid tampering the red towers	
				sleep(1.5);
				pivot(0,-90,FAST_SPEED); //pivots -90 degrees CW
				moveToDist(-7-6,FAST_SPEED);//moves back to avoid pivoting on black tape***********
				pivot(1,-98,FAST_SPEED); //pivots -100 degrees CCW, faces north
				//moveToDist(120,FAST_SPEED); //split into two distances in following lines
				moveToDist(87+65, FAST_SPEED);//runs into to North PVC, the two distances should add up to 140

				
				//LEG 3: collects ping pong balls @ second station				
				moveToDist(-20,FAST_SPEED); //backs up to allow for turn
				turn(-90,SLOW_SPEED); //pivots to face west PVC
				moveToDist(40+10,FAST_SPEED); //aligns with west PVC
				moveToDist(-6,FAST_SPEED); //backs up to allow for turn
				turn(-85, SLOW_SPEED); //pivots to face south PVC & ping pong balls
				moveToDist(20, FAST_SPEED); //collects all biofuels
				sleep(.7);
				moveToDist(-10,FAST_SPEED); //backs up so that bot won't turn on tape when arriving at drop zone
				
				//LEG 4: drop all biofuels
				turnArc(1, 50, -MED_SPEED, -4); //arcs back and hits north PVC <-reverted
				moveToDist(-55,SLOW_SPEED); //aligns with north PVC
				moveToDist(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(1, 94, FAST_SPEED); //pivots to face final east PVC
				moveToDist(100, FAST_SPEED); //moves and aligns with east PVC
				moveToDist(-30, FAST_SPEED); //moves back to align with drop zone and avoid tape
				pivot(0, -83, FAST_SPEED); //pivots to face drop zone
				moveToDist(50, FAST_SPEED); //drives to and aligns with drop zone (north PVC)
				gateOpen(); //drops all biofuels
				int i;
				for (i = 0; i < 7; i++)	{
					moveToDist(-0.5,FAST_SPEED);
					sleep(0.1);
					moveToDist(2,SUPER_SPEED);
				}
			}

			if(b_button())
			{
				wait_for_light(LIGHT_PORT);
				shut_down_in(117);
				printf("\n Starting side B");
				//LEG 1: collects ping pong balls @ first station
				sleep(14.5);
				moveToDist(50.5, MED_SPEED);
				sleep(.2);
				moveToDist(3, MED_SPEED);
				sleep(.7);
				
				//LEG 2: navigates to north PVC
				moveToDist(-8, FAST_SPEED); //moves back to avoid tampering the red towers	
				sleep(2.5);
				pivot(1,-90,FAST_SPEED); //pivots -90 degrees CCW
				moveToDist(-6-10,FAST_SPEED);//moves back to avoid pivoting on black tape, faces North PVC
				pivot(0,-90 , FAST_SPEED); //pivots -90 degrees CW
				moveToDist(82+72, FAST_SPEED);//head to North PVC, the two distances should add up to 120
				
				//LEG 3: collects ping pong balls @ second station
				moveToDist(-19,FAST_SPEED); //backs up to allow for turn
				turn(90, SLOW_SPEED); //pivots to face east PVC
				moveToDist(60+10,FAST_SPEED); //aligns with east PVC
				moveToDist(-8,FAST_SPEED); //backs up to allow for turn
				turn(88,SLOW_SPEED); //pivots to face south PVC & ping pong balls
				moveToDist(21, FAST_SPEED); //collects all biofuels
				sleep(.7);
				moveToDist(-5,FAST_SPEED);
				
				//LEG 4: drop all biofuels			
				turnArc(0, 50, -MED_SPEED, -4); //arcs back and hits north PVC <-reverted
				moveToDist(-100,	SLOW_SPEED); //aligns with north PVC
				moveToDist(4, FAST_SPEED); //moves slightly forward to leave room for pivot
				pivot(0, 100, FAST_SPEED); //pivots to face final east PVC
				moveToDist(100, FAST_SPEED); //moves and aligns with east PVC
				moveToDist(-43.5,FAST_SPEED);//backs up before dropping off balls
				pivot(0, 86, FAST_SPEED); //pivots to face drop zone
				moveToDist(50, FAST_SPEED); //drives to and aligns with drop zone (north PVC)
				gateOpen(); //drops all biofuels
				int i;
				for (i = 0; i < 7; i++) {
					moveToDist(-0.5,FAST_SPEED);
					sleep(0.1);
					moveToDist(2,SUPER_SPEED);
				}
			}
	}		
}
