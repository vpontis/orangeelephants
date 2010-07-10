#include "create_constants.h"
#include "controller.c"
#include "create_motor.c"
#include "robot.h"
#include "boolean.h"

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

 int jacob()
{
	printf("Starting jacob method\n");
	enable_servos();
	set_servo_position(LEFTDETACH, 1710);
	set_servo_position(RIGHTDETACH, 210);
	move(-52.0);
	turn_angle(-60.0, 0, 200);
	move(-43.0);
	release();
	msleep(500);
	move(40.0); //move back down slope
	turn_d(-70);
	move_dist(-24. * 2.54, 0, 500);
	turn_d(30);
	move_dist(-24. * 2.54, 0, 500);	
	return 0;
} 

//seeding round method
int mark()
{
	//Initialize everything
	cbc_display_clear();
	printf("Starting mark-test method\n");
	enable_servos();
	grab();
	printCurrentDist();
	
	//Moves out of starting box and gets tribble cups 1 and 2
	move_forward(150.0);
	
	//Turns left toward tribble cup 3
	turn_speed(100, -95.0);
	
	//Go toward tribble cup 3
	move_forward(44);//38
	
	//Turns toward tribble cup 4
	turn_speed(88, -85.0);//100deg
	
	//Move toward tribble cup 4
	move_forward(85.0);
	
	//Turn toward mayor botguy
	turn_speed(125, -180.0);
	
	//Move and get mayor botguy and turbine 2
	//Also moves to the base of their slope
	move_forward(164.0);//165
	
	//Turn toward slope
	turn_speed(90, 68.0);//100
	
	//Move to top of slope
	move_forward(131.0);
	
	return 0;
}

//ideal double-elimination method
int yixin()
{
	cbc_display_clear();
	printf("Starting yixin-test method\n");		
		
	seconds();
	enable_servos();
	grab();
	printCurrentDist();
	
	//move to position to turn
	move_forward(114.0);
	printCurrentDist();
	//arc-like thing, without actually arcing
	//turn_angle(-10., 0, 300); //actually 45 degrees
	
	//turn to slope
	turn_speed(200, 45.0);
	msleep(500);
	
	//move up slope slightly
	move_forward(55.0); //test
	//turn_angle(-60., 0, 300); //actually 45 degrees
	//This is on a slope, so the angle must be increased. 
	
	//turn on slope
	turn_speed(200, 69.0); //speed is 200 because it has all the items gathered, needs to be slower.	
	msleep(500);
	
	move_forward(108.0); //move up to peak
	//following code was sometimes scoring other teams points commented out for that reason
	/*release(); 
	msleep(1000);
	//bulldozer gets caught. this movement fixes that.
	turn_d(45.);
	msleep(250);
	move_backward(5.);
	turn_d(-45.);
	msleep(500);
	move_backward(104.0); //go back down the slope
	turn_d(185.0); //turn around 180 degrees
	msleep(200);
	move_forward(63.0); //move toward starting box area.
	msleep(500);
	turn_d(50.0); //turn to starting box area more
	move_forward(50.); //rams treble cup right outside starting box
	msleep(500);
	move_backward(30.); //move backwards to re-ram
	msleep(250);
	move_forward(40.); //ram again
	move_backward(5.);//positions iteslf
	msleep(100);	
	turn_d(110.); //turn to starting box.
	msleep(500);
	move_forward(100.); //move into the starting box
	msleep(500);
	move_backward(60.); //back up in order to repush anything inside the starting box out
	msleep(200);	
	move_forward(60.);	
	move_backward(60.);	
	move_forward(60.);	
	move_backward(60.);
	move_forward(60.);	
	move_backward(60.);
	move_forward(60.);	
	move_backward(60.);
	move_forward(60.);	
	move_backward(60.);*/
	return 0;
} 

//if their robot is going to block the peak, use vivek()
int vivek()
{
	//initializes everything, grabs the bulldozer
	cbc_display_clear();
	printf("Starting vivek-test method\n");
	enable_servos();
	grab();
	printCurrentDist();
	
	//gather two tribble cups
	move_forward(120.0);
	printCurrentDist();
	
	//Turns back toward starting box
	turn_speed(250, -185.0);
	
	//Drives back into the starting box
	move_forward(100.0);
	
	//release the bulldozer
	release();
	
	//Drives back out of starting box
	move_backward(115.0);
	
	/**
	Turns toward opposing starting box
	goes forward
	turns into opposing starting box
	drives forward
	*/
	turn_d(100.0);
	move_forward(100.0);
	msleep(250L);
	move_backward(5.0);
	turn_d(100.0);
	move_forward(70.0);
	
	//should be in starting box
	return 0;
}

int check_battery_levels()
{
	printf("CBC Battery Level: %f volts\n",power_level());
	create_battery_charge();
	printf("Create Battery Level: %f volts\n", gc_batt_voltage/1000.0);
	return 0;
}

void printCurrentDist()
{
	printf("current distance before moving: %d\t%d\n", create_distance(), gc_distance);
}
