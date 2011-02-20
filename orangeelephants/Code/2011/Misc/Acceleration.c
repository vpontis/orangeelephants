#include "math.c"

void accel(int initSpeed, int finalSpeed);

int main()
{
	accel(0,500);
}

/*Function definitions go below.*/


/**
accel(int initSpeed, int finalSpeed)
Accelerates the robot from one speed to the next in 10 incremental speeds. 
Robot continues on driving straight at finalSpeed.
*/

void accel(int initSpeed, int finalSpeed)
{
	int increm = (finalSpeed-initSpeed)/10;
	int speed = initSpeed;
	
	float time = abs((finalSpeed-initSpeed)/5000);//delay is .1 sec for accel from 0-500
	
	while(speed<finalSpeed)
	{
		speed += increm; 
		create_drive_straight(speed);
		sleep(time);
	}
	
	create_drive_straight(finalSpeed);
}
