#include "createMotor.h"
#include "createConstants.h"
#include "math.c"
/**
accel(int initSpeed, int finalSpeed)
Accelerates or decelerates the robot from one speed to the next in 20 incremental speeds. 
Robot continues on driving straight at finalSpeed.
*/
void accel(int initSpeed, int finalSpeed)
{
	int speed = initSpeed;
	int increm = (finalSpeed-initSpeed)/20;
	
	float time = abs((finalSpeed-initSpeed)/2000);//delay is .1 sec for accel from 0-500
	
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



void modAccel(int distance, int highSpeed){
	
	
	int speed = get_create_requested_velocity(.1);
	int increm = (highSpeed-speed)/20;
	
	float time = abs(((highSpeed-speed))/2500*(distance/500));//delay is .1 sec for accel from 0-500
	
	if(speed<highSpeed)//if you are accelerating
	{
		while(speed<highSpeed)
		{
			speed += increm; 
			create_drive_straight(speed);
			sleep(time);
		}
	}
	else//if you are decelerating
	{
		while(speed>highSpeed)
		{
			speed += increm; 
			create_drive_straight(speed);
			sleep(time);
		}
	}
	
	create_drive_straight(highSpeed);
	
	
	
	
	}
/** \brief Moves the robot a distance at a constant speed

	Does not work well for very short distances.
	\param distance Desired distance in mm
	\param speed Desired speed in ??
*/
void moveToDist(int distance, int speed) 
{ 
	distance = -distance;
	set_create_distance(0); 
	
	if(distance > 0) {   
		createDrive(speed);
		while (get_create_distance(.1) < distance) {}
		createDrive(0);
	}
	else{ //backwards
		createDrive(-speed);
		while (get_create_distance(.1) > distance) {}
		createDrive(0);
	}
}

//Optimized at d = 90, v = 200. Test at other values. 
void smoothTurn(float deg, int finalVel)	{
	deg = -deg;
	set_create_total_angle(0);
	float compRatio = 1.7; //.00405*finalVel*(standardVel/finalVel)
	
	int increment = finalVel/10;
	int currVel = increment;
	if(deg > 0){
		//CCW: +deg, +vel
		while(get_create_total_angle(.1) < 0.5*(compRatio*deg))	{
			while(currVel < finalVel)
			{
				create_drive_direct(currVel, -currVel);
				currVel += increment;
				sleep(.15);
			}
			currVel = finalVel;
			create_drive_direct(currVel, -currVel);
		}
		
		set_create_total_angle(0);
		/*
		while(get_create_total_angle(.1) < 0.5*(compRatio*deg)){
			while(currVel > increment)
			{
				create_drive_direct(currVel, -currVel);
				currVel -= increment;
				sleep(.15);
			}
			currVel = 0;
			create_drive_direct(currVel, -currVel);
		}*/
	}
	else{
		while(get_create_total_angle(.1) > 0.5*(compRatio*deg))	{
			while(currVel < finalVel)
			{
				create_drive_direct(-currVel, currVel);
				currVel += increment;
				sleep(.15);
			}
			currVel = finalVel;
			create_drive_direct(-currVel, currVel);
		}
		set_create_total_angle(0);
		/*
		while(get_create_total_angle(.1) > 0.5*(compRatio*deg)){
			while(currVel > increment)
			{
				create_drive_direct(-currVel, currVel);
				currVel -= increment;
				sleep(.15);
			}
			currVel = 0;
			create_drive_direct(-currVel, currVel);
		}*/
	}
	create_stop();
	
}

void moveToDistAccel(int distance, int finalSpeed) 
{
	//Input velocity is ALWAYS positive
	distance = -distance;
	
	set_create_distance(0); 
	double numIncrements = 20.;
	double increment = finalSpeed/numIncrements;
	double currSpeed;
	
	double totalDistance = 0;
	
	
	if(distance > 0) {
		currSpeed = increment;
		create_drive_straight(currSpeed);
		while((totalDistance) < (distance/2)) {   
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/(numIncrements))){}
			totalDistance += (distance/(numIncrements));
			currSpeed += increment;
			create_drive_straight(currSpeed);
		}
		
		totalDistance = 0;
		while((totalDistance) < (distance/2)) {   
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/numIncrements)) {}
			totalDistance += (distance/(numIncrements));
			currSpeed -= increment;
			create_drive_straight(currSpeed);
		}
		
	}
	else{
		currSpeed = -increment;
		create_drive_straight(currSpeed);
		while((totalDistance) > (distance/2)) { 
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/numIncrements)) {}
			totalDistance += (distance/numIncrements);
			currSpeed -= increment;
			create_drive_straight(currSpeed);
		}
		
		totalDistance = 0;
		while((totalDistance) > (distance/2)) {  
			set_create_distance(0);
			while(get_create_distance(.1) > (distance/numIncrements)) {}
			totalDistance += (distance/numIncrements);
			currSpeed += increment;
			create_drive_straight(currSpeed);
		}
	}
	create_stop();
	
}
