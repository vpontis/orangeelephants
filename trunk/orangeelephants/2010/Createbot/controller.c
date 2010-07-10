#include "controller.h"
#include "create_motor.h"
#include "boolean.h"

int run_Control()
{	

	boolean isGoingUp = 0;
	boolean isGoingRight = 0;
	boolean isGoingDown = 0;
	boolean isGoingLeft = 0;
	boolean isOff = 1;
	boolean grip_Closed = TRUE;
	while(!b_button())
	{
		
		if(black_button())
		{
			printf("release button pressed\n");
			if(grip_Closed)
			{				
				release();
				grip_Closed = FALSE;
				//sleep(1.5);
				//disable_servos();
			}
			else
			{
				//enable_servos();
				grab();
				grip_Closed = TRUE;
			}
			while (black_button())
				msleep(100L);
			printf("Lever can be switched again\n");
		}
		
		if(JOYPAD_UP || JOYPAD_DOWN || JOYPAD_LEFT || JOYPAD_RIGHT)
		{
			if(JOYPAD_UP)
			{
				if(!isGoingUp)
				{
					backward(SPEED_C);
					isGoingUp = 1;
					isOff = 0;
					printf("up\n");
				}
			}
		
			if(JOYPAD_RIGHT)
			{
				if(!isGoingRight)
				{
					create_spin_CW(SPEED_C /*- 100*/);
					isGoingRight = 1;
					isOff = 0;
					printf("right\n");
				}
			}	
		
			if(JOYPAD_DOWN)
			{
				if(!isGoingDown)
				{
					forward(SPEED_C);
					isGoingDown = 1;
					isOff = 0;
					printf("down\n");
				}
			}
		
			if(JOYPAD_LEFT)
			{
				if(!isGoingLeft)
				{
					create_spin_CCW(SPEED_C);
					isGoingLeft = 1;
					isOff = 0;
					printf("left\n");
				}
			}
		}
		
		else
		{
			if(!isOff)
			{
				turnOff();
				printf("STOP\n");
				isGoingUp = 0;
				isGoingRight = 0;
				isGoingDown = 0;
				isGoingLeft = 0;
				isOff = 1;
			}
		}
	}

return 0;	
}

void turnOff()
{
	stop();
}
