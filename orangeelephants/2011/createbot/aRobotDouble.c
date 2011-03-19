#include "createFunctions.c"
#include "createMotor.c"

int main()
{
	int LIGHT_PORT = 0;
	printf("Now press the A button to run side A. \n");
	printf("Now press the B button to run side B. \n");
	createInitialize();
	enable_servos();
	while(1)
	{
		while(1)	{
			if(a_button())
			{					
				wait_for_light(LIGHT_PORT);
				float initSeconds = seconds();
				printf("Init seconds = %d.\n", initSeconds);
				shut_down_in(120);
				enable_servos();
				moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
				smoothTurn(-90, 200);//Faces North
				accel(0, 500);
				moveToDist(200, 500);//Travels North to middle of board
				accel(500, 0);
				smoothTurn(-90, 200);//Turns towards runway, robot faces West
				while(1)	{
					if(seconds() - initSeconds > 15) //wait 15 seconds before moving
						break;					
				}
				printf("The time is %f.\n", seconds()-initSeconds);
				moveToDist(1300, 500);//drive across the divider in the middle
			}

			if(b_button())
			{	
				wait_for_light(LIGHT_PORT);
				float initSeconds = seconds();
				printf("Init seconds = %d.\n", initSeconds);
				shut_down_in(120);
				enable_servos();
				moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
				smoothTurn(90, 200);//Faces North
				accel(0, 500);
				moveToDist(200, 500);//Travels North to middle of board
				accel(500, 0);
				smoothTurn(90, 200);//Turns towards runway, robot faces West
				while(1)	{
					if(seconds() - initSeconds > 15) //wait 15 seconds before moving
						break;					
				}
				printf("The time is %f.\n", seconds()-initSeconds);
				moveToDist(1300, 500);//drive across the divider in the middle
			}
			/*
			if(black_button())
			{
				printf("Press up to open, down to close, black button to finish -- move it to the perpendicular position");
				while (1) 
				{
					if (up_button() == 1) {
						mrp(DROPPER_PORT,200,-20);
					}
					if(down_button() == 1) {
						mrp(DROPPER_PORT,200,20);
					}
					if(black_button() == 1) {
						break;
					}
				}
			}
			
			if(up_button())
			{
				mtp(DROPPER_PORT, 100, -40);
				bmd(DROPPER_PORT);
			}
				
			
			*/
		}//keep, ends while loop
 
	}
}
	
