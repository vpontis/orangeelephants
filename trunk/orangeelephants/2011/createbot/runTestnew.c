#include "createConstants.h"
#include "createFunctions.c"

int main()
{
	enable_servos();
	set_servo_position(CLAW_PORT, CLAW_OPEN_POS);
	printf("Press A button to run program \n");
	printf("Press UP to raise arm. Press DOWN to callibrate and to lower arm \n");
	while(1)
	{
		if(a_button())//Gives prompts to run code.
		{
			stackBlocks();
			sleep(1);
			break;
		}
		else if(up_button())
		{
			moveClawUp();
		}
		else if(down_button())
		{
			moveClawUp();
			moveClawDown(ARM_POS_DOWN);
		}        
	}
	
}
