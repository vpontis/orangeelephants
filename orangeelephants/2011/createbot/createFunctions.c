#include "createFunctions.h"

/**
accel(int initSpeed, int finalSpeed)
Accelerates or decelerates the robot from one speed to the next in 20 incremental speeds. 
Robot continues on driving straight at finalSpeed.
*/
void accel(int initSpeed, int finalSpeed)
{
	int increm = (finalSpeed-initSpeed)/20;
	int speed = initSpeed;
	
	float time = abs((finalSpeed-initSpeed)/2500);//delay is .1 sec for accel from 0-500
	
	if(speed<finalSpeed)//if you are accelerating
	{
		while(speed<finalSpeed)
		{
			speed += increm; 
			create_drive_straight(speed);
			sleep(time);
		}
	}
	else//if you are decelerating
	{
		while(speed>finalSpeed)
		{
			speed += increm; 
			create_drive_straight(speed);
			sleep(time);
		}
	}
	
	create_drive_straight(finalSpeed);
}

void createDrive(int finalSpeed)
{
	int initSpeed = get_create_requested_velocity(.1);
	accel(initSpeed, finalSpeed);
}

void createInitialize()
{
	int conVal = create_connect();
	if(conVal == 0){
		printf("Connection success. Setting to full mode...");
	}
	else{
		printf("Connection failed.");
	}
	create_full();
}

/**
void moveToDistance(int distance, int speed) 
Moves the robot a distance at a speed. 
Does not work well for very short distances.
*/
void moveToDistance(int distance, int speed) 
{ 
	int slowDownDist = speed*.535; 
	
	set_create_distance(0); 
	if(get_create_distance(.1) < distance) {      
		createDrive(speed);
        while (get_create_distance(.1) < (distance-slowDownDist)) {
                sleep(0.05);
        }
		createDrive(0);
     }
}
