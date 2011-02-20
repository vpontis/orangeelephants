#include "create_main.c"
#include "create_constants.h"

//int competitionRunner();


int main()
{
	printf("Press A button for competition mode. \n Press B button for testing mode \n Press UP Button for Calibration. \n");
	while(1)
	{
		if(a_button())
		{
			printf("Running competition mode!");
			int conVal=create_connect();
			enable_servos();
			create_full();
			set_each_analog_state(1,0,0,0,0,0,0,0);
			clear_motor_position_counter(ARM_MOTOR);
			competitionRunner(create_main, LIGHT_SENSOR_PORT);
			break;
		}
		else if(b_button())
		{
			printf("Running non-competition mode.");
			int conVal= create_connect();  //Connects to Create
			enable_servos();
			clear_motor_position_counter(ARM_MOTOR);
			create_full(); //Puts Create in full mode
			create_main();
			break;
		}
		else if(up_button())
		{
			clear_motor_position_counter(ARM_MOTOR);
			mrp(ARM_MOTOR, ARM_NORMAL_SPEED, -1400);
			bmd(ARM_MOTOR);
			clear_motor_position_counter(ARM_MOTOR);
			break;
		}
		sleep(.05);
	}	
}
