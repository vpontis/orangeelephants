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
				shut_down_in(117);
				float initSeconds = seconds();
				printf("Init seconds = %d.\n", initSeconds);
				shut_down_in(120);
				enable_servos();
				moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
				smoothTurn(-90, 200);//Faces North
				accel(0, 500);
				moveToDist(250, 500);//Travels North to middle of board
				accel(500, 0);
				smoothTurn(-90, 200);//Turns towards runway, robot faces West
				while(1)	{
					if(seconds() - initSeconds > 14.5) //wait 15 seconds before moving
						break;					
				}
				printf("The time is %f.\n", seconds()-initSeconds);
				moveToDist(1300, 500);//drive across the divider in the middle
				sleep(8);
				int i;
				for(i=1; i<=10; i++)
				{
					moveToDist(150, 500);
					sleep(.5);
					moveToDist(-150,500);
				}
				ao();
			}

			if(b_button())
			{	
				wait_for_light(LIGHT_PORT);
				shut_down_in(117);
				float initSeconds = seconds();
				printf("Init seconds = %d.\n", initSeconds);
				shut_down_in(120);
				enable_servos();
				moveToDistAccel(-5, NORMAL_SPEED);//first movement, backs up to travel down lane
				smoothTurn(90, 200);//Faces North
				accel(0, 500);
				moveToDist(250, 500);//Travels North to middle of board
				accel(500, 0);
				smoothTurn(90, 200);//Turns towards runway, robot faces West
				while(1)	{
					if(seconds() - initSeconds > 14.5) //wait 15 seconds before moving
						break;					
				}
				printf("The time is %f.\n", seconds()-initSeconds);
				moveToDist(1300, 500);//drive across the divider in the middle
				sleep(8);
				int i;
				for(i=1; i<=10; i++)
				{
					moveToDist(150, 500);
					sleep(.5);
					moveToDist(-150,500);
				}
				ao();
				ao();
			}
			
		}//keep, ends while loop
 
	}
}
	
