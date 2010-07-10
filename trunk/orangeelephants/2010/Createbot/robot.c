#include "create_constants.h"
#include "controller.c"
#include "robot.h"
#include "boolean.h"
#include "tests.c"

boolean startingBoxPVC = false;

int main()
{
	disable_servos();
	kissSim_init(7, 151, 25, 1.5708*3);
	create_connect();
	msleep(5L);
	boolean competitionMode = false;
	int lightPort = 13;
	printf("Competition Mode? A = Yes B = No\n");
	while (!(a_button() || b_button()))
		msleep(100L);
	competitionMode = a_button();
	while (a_button() || b_button())
		msleep(100L);
	cbc_display_clear();
	printf("Create Main Menu\n");
	printf("Competition Mode: ");
	if (competitionMode)
		printf("On\n");
	else
		printf("Off\n");
	printf("Choose program to run\nUp: jacob()\nDown: controller()\nLeft: mark()\nRight: yixin()\n");
	printf("A button: vivek()\n B button: voltage read\n");
	while (!(up_button() || down_button() || right_button() || left_button() || a_button() || b_button()))
		msleep(100L);	
	if(up_button())
		{
			return competitionMode ? competition_runner(jacob, lightPort): jacob();
		}
	if(down_button())
		{
			return competitionMode ? competition_runner(controller, lightPort): controller();
		}
	if(left_button())
		{
			return competitionMode ? competition_runner(mark, lightPort): mark();
		}
	if(right_button())
		{
			printf("Are they dumping over the Starting Box PVC? A = Yes B = No\n");
			while (!(a_button() || b_button()))
				msleep(100L);
			startingBoxPVC = a_button();
			while (a_button() || b_button())
				msleep(100L);			
			return competitionMode ? competition_runner(yixin, lightPort): yixin();
		}
	if(a_button())
		{
			return competitionMode ? competition_runner(vivek, lightPort): vivek();
		}
	if (b_button())
		{
			return competitionMode ? competition_runner(check_battery_levels, lightPort):
				check_battery_levels();
		}
	create_disconnect();		
	return 0;	
}

/** \brief The competition runner method for the competition
	\param (*func)() the name of the function wished to be implemented
	\param lightPort the port that the function should look for with regards to light
*/
int competition_runner(int(*func)(), int lightPort)
{
	printf("Competition Runner Initiated\n");
	printf("Waiting for light port: %d\n", lightPort);
	create_full();
	wait_for_light(lightPort);
	shut_down_in(115.0);
	printf("Light Found, Running Func\n");
	return func();
}

int controller()
{	
	printf("Starting controller method\n");
	enable_servos();
	grab();		
	create_full();
	run_Control();
	return 0;
}



void printCurrentDist()
{
	printf("current distance before moving: %d\t%d\n", create_distance(), gc_distance);
}
