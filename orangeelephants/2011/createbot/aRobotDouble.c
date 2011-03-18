#include "createFunctions.c"
#include "createMotor.c"

int main()
{
	printf("Now press the A button to run side A. \n");
	printf("Now press the B button to run side B. \n");
	createInitialize();
	enable_servos();
	while(1)
	{
		while(1)	{
			if(a_button())
			{	
				//wait_for_light(LIGHT_PORT);
				float initSeconds = seconds();
				printf("Init seconds = %d.\n", initSeconds);
				//initialization
				shut_down_in(120);
				enable_servos();
				
				//Leg 1, starts and drops off airplane
				moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
				smoothTurn(-90, 200);//Faces North
				accel(0, 500);
				moveToDist(400, 500);//Travels North the length of the board
				accel(500, 0);
				smoothTurn(-90, 200);//Turns towards runway, robot faces West
				//Going in for airplane dropoff
				while(1)	{
					if(seconds() - initSeconds > 15) 
						break;					
				}
				printf("The time is %f.\n", seconds()-initSeconds);
				moveToDist(750, 500);//drive forward to pick up block25
				sleep(1);
				moveToDist(500, 500);
				beep();
				sleep(.5);
				beep();
				sleep(.5);
				beep();
			}
			if(b_button())
			{	
				//initialization
				//wait_for_light(LIGHT_PORT);
				int initSeconds = seconds();
				shut_down_in(120);
				
				
				//Leg 1, starts and drops off airplane
				moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
				smoothTurn(110, 200);//Faces North
				accel(0, 500);
				moveToDist(1100, 500);//Travels North the length of the board
				accel(500, 50);
				moveToDist(-7, 200);//Backs up from wall to allow turn
				smoothTurn(-90, 200);//Turns towards runway, robot faces East
				//Going in for airplane dropoff
				moveStraight(-250);//Runs into East PVC
				sleep(2.75);
				create_stop();
				releasePlane();
				//Completed the airplane dropoff
				
				//Leg 2, picks up first set of blocks
				moveToDist(225+25, 500);//backs up before turning to head back 
				smoothTurn(94, 200);//Turns to face North
				moveStraight(100);//Wall alignment w/ North PVC
				sleep(.6);
				accel(0, -1400+450);//drives back to align with blocks
				accel(-1400+450, 0);
				smoothTurn(94, 200);//turns East to face blocks
				while(1)	{if(seconds() - initSeconds > 15) break;}
				printf("The time is %d.\n", seconds()-initSeconds);
				moveToDist(500, 500);//drive forward to pick up blocks
			}
		}//keep, ends while loop
 
	}
}
	
