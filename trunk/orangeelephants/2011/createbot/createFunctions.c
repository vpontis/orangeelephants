#include "createFunctions.h"
#include "createConstants.h"

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

/** \brief Moves the robot a distance at a constant speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param speed Desired speed in ??
*/
void moveToDistance(int distance, int speed) 
{ 
	int slowDownDist = speed*stopDistanceRatio; //Calculates the stopping distance based on speed
	
	//so it doesn't go in the wrong way with a short distance and fast speed
	//Needs testing/refinement
	if((slowDownDist > abs(distance))){ 
		slowDownDist = 0;
	}
	
	set_create_distance(0); 
	
	//Testing Code
	printf("The total distance is %2.2d \n", distance - slowDownDist);
	printf("The slowDownDist is %2.2d \n", slowDownDist);
	
	if(get_create_distance(.1) < distance) {   
		createDrive(speed);
        while (get_create_distance(.1) < (distance-slowDownDist)) {
                sleep(0.05);
        }
		create_stop();
     }
	 else{ 
		 //backwards
		 createDrive(-speed);
		 while (get_create_distance(.1) > (distance+slowDownDist)) {
                sleep(0.05);
        }
		create_stop();
	}
		 
}
