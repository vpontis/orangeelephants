#include "create_motor.c"
#include "create_constants.h"
void poll_Sensors();
void bump_Sensors();

int main() 
{	
	kissSim_init(BB09WORLD, 151, 32, 1.5708*3);
	printf("Starting program\n");
	int conVal = create_connect();
	msleep(5);
	//create_full();
	//start_process(poll_Sensors);
	//start_process(bump_Sensors);
	printf("The con was:%x\n", conVal);
	if(conVal == 0)
	{		
		move_Dist(-25. * 2.54, 0, 500);				
		turn_d(-90);
		move_Dist(-27. * 2.54, 0, 500);
		turn_d(-40);
		move_Dist(-25. * 2.54, 0, 500);
		turn_d(45);
		move_Dist(-15. * 2.54, 0, 500);
		stop();
		//int i = 0, r = 0;
		//gc_total_angle = 0;
	    //r = create_angle();
		//printf("Return is:%d\n", r);
		//create_spin_CW(200);
		//while(gc_total_angle > -90)
		///{
			//create_angle();
			//printf("Total angle is:%d", gc_total_angle);
		//}
	    create_disconnect();
		kissSimPause();
		return 0;
	}
	else
	{
		printf("Did not connect");
		return -1;
	}

}

void poll_Sensors()
{
	SENSOR_PROCESS = TRUE;
	while(TRUE)
		{
			create_sensor_update();
			bump_Hit = (gc_lbump || gc_rbump);
			printf("bump_Hit is:%x\n", bump_Hit);
			if(bump_Hit)
			{
				printf("About to defer\n");
				//defer();
			}				
			msleep(100);
		}
}

void bump_Sensors()
{
	printf("Bumper hit process running\n");	
	if(bump_Hit)
	{
		printf("moving back\n");
		move_Dist(-5. * 2.54, 0, 500);
	}
}
